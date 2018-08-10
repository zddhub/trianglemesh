/*
#-------------------------------------------------
# @Author: zdd
# @Email: zddhub@gmail.com
#
# rstc.cc in Qt
#
# Thanks:
#    Original by Tilke Judd
#    Tweaks by Szymon Rusinkiewicz
#
#    apparentridge.h
#    Compute apparent ridges.
#
#    Implements method of
#      Judd, T., Durand, F, and Adelson, E.
#      Apparent Ridges for Line Drawing,
#      ACM Trans. Graphics (Proc. SIGGRAPH), vol. 26, no. 3, 2007.
#-------------------------------------------------
*/

/*************************************************************************
 * Copyright (c) 2014 Zhang Dongdong zddhub@gmail.com
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**************************************************************************/

#include <QApplication>
#include <QImage>
#include <QPixmap>

#include "mainwindow.h"
#include "trianglemesh.h"

//在windows下,本程序使用以下.bat程序调用
/*
 *  gen_view_image.exe cow.obj views 102 images
 */

void usage() {
    cout << "Usage: gen_view_image modelfile xfdir viewnum imagedir"<<endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argc < 4) {
        usage();
        exit(1);
    }
    MainWindow mw;
    mw.show();
    TriMeshView tv;
    tv.isDrawBoundaries = true;
    tv.isDrawOccludingContours = true;
    tv.isDrawSuggestiveContours = true;

    tv.readMesh(argv[1]);
//    tv.show();

    uint viewnum = atoi(argv[3]);

    for(uint i = 0; i < viewnum; i++) {
        char buf[100];
        sprintf(buf, "%s/%d.xf", argv[2], i);
        tv.readXf(buf);

        sprintf(buf, "%s/%d.jpg", argv[4], i);
        QPixmap pixmap = tv.renderPixmap(tv.width(), tv.height());
        pixmap.save(buf);
    }
    exit(0);
    return a.exec();
}
