Line View Tool
==============

This project is to serve for [opensse](https://github.com/zddhub/opensse), Get line-drawing images for each model(support *.off and *.obj) using viewpoint matrix(under `../data/view/`).

Demo
====

In [my demo](http://opensse.com), I used 102 viewpoints on earth to project line drawings.

### view points(red points)

![view points](http://img.blog.csdn.net/20140612163508796)

### model

![teddy](http://img.blog.csdn.net/20140612164244140)

### line drawings

![line drawings](http://img.blog.csdn.net/20140612163841031)

Usage
=====
```shell
gen_view_image.exe modelfile xfdir viewnum imagedir
```
example:(make sure dir teddy is exist.)
```shell
./gen_view_image ../data/teddy.off ./data/view/ 102 teddy
```

Thanks
======
- [Szymon Rusinkiewicz](http://www.cs.princeton.edu/~smr/)
- [Tilke Judd](http://people.csail.mit.edu/tjudd/)

License
=======

Code is under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Donations
=========

I accept tips through [Alipay](http://img.blog.csdn.net/20140506233949640). Scan below qr code to donate:

![Alipay](http://img.blog.csdn.net/20140506233949640 "Donation").

Contact me
==========

If you have any question or idea, please [email to me](mailto:zddhub@gmail.com).