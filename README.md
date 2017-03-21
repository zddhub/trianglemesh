Line View Tool [![Build Status](https://travis-ci.org/zddhub/trianglemesh.svg?branch=trianglemesh)](https://travis-ci.org/zddhub/trianglemesh)
==============

This project serves [OpenSSE](https://github.com/zddhub/opensse), that gets line-drawing images for each model(support *.off and *.obj) using viewpoint matrix (under `../data/view/`).

Demo 1
======

In [my demo](http://opensse.com), I used 102 viewpoints on globe to project line drawings.

### view points(red points)

![view points](data/viewpoints.png)

### model

![teddy](data/teddy.png)

### line drawings

![line drawings](data/teddy_line_drawings.png)

Usage
=====
```shell
gen_view_image.exe modelfile xfdir viewnum imagedir
```
example:(make sure dir teddy is exist.)
```shell
./gen_view_image ../data/teddy.off ./data/view/ 102 teddy
```

Demo 2
======

On `trianglemesh` branch, there are powerfull line drawings extract framework for you. Until now, It supported Boundaries, Exterior Silhouette, Occluding Contours, Suggestive Contours, Ridges and Valleys, Apparent Ridges.

![Triangle Mesh Line Drawings](data/line-drawings.gif "Line Drawings")

Thanks
======
- [Szymon Rusinkiewicz](http://www.cs.princeton.edu/~smr/)
- [Tilke Judd](http://people.csail.mit.edu/tjudd/)

License
=======

Code is under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Donate
======

I accept tips through [Alipay](http://img.blog.csdn.net/20140506233949640). Scan below qr code to donate:

![Alipay](http://img.blog.csdn.net/20140506233949640 "Donation").

Contact me
==========

If you have any question or idea, please [email to me](mailto:zddhub@gmail.com).
