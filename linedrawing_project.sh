#!/bin/sh

underline () {
    echo "\033[4m$1\033[0m"
}

usage() {
    echo "Usage: `basename $0` -d rootdir -p pattern"
    echo "  This command generates 102 line-drawing images from 102 views of each model under `underline rootdir` folder"
    echo "  The options are as follows:"
    echo "  -d\t root directory"
    echo "  -p\t the pathname being examined matches `underline pattern`, support \"*.off\" or \"*.obj\" "
    exit 1
}

if [ $# -ne 4 ]; then
    usage;
fi

while getopts "d:p:" arg; do
    case $arg in
        d)
            rootdir=$OPTARG
            ;;
        p)
			pattern=$OPTARG
			;;
        ?)
            usage;
            ;;
    esac
done

for model in $(find $rootdir -name "$pattern" | sed 's/^\.\///'); do
	view="${model%.*}view"
	mkdir -p $view
	release/bin/gen_view_image $model data/view 102 $view
done
