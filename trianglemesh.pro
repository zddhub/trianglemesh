#-------------------------------------------------------------------------
# Copyright (c) 2014 Zhang Dongdong
# All rights reserved.
# email: zddhub@gmail.com
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#-------------------------------------------------------------------------

QT       += core gui \
            opengl

CONFIG += console
TARGET = gen_view_image
TEMPLATE = app
DESTDIR = ./bin

macx : CONFIG -= app_bundle
macx : QMAKE_MAC_SDK=macosx10.13 # Change this to your macOS version if you are using macOS

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD \
    $$PWD/include

SOURCES += main.cpp \
    trimeshview.cpp \
    trianglemesh/trianglemesh_io.cpp \
    trianglemesh/trianglemesh_tstrips.cpp \
    trianglemesh/trianglemesh_connectivity.cpp \
    trianglemesh/trianglemesh_bounding.cpp \
    trianglemesh/trianglemesh_normals.cpp \
    trianglemesh/KDtree.cpp \
    trianglemesh/GLCamera.cpp \
    trianglemesh/trianglemesh_curvature.cpp \
    trianglemesh/trianglemesh_pointareas.cpp \
    trianglemesh/trianglemesh_stats.cpp \
    mainwindow.cpp \
    trimeshview_draw_base.cpp \
    trimeshview_draw_lines.cpp \
    trimeshview_draw_ridges_and_valleys.cpp \
    trimeshview_draw_apparent_ridges.cpp \
    featurelines.cpp \
    threshdialog.cpp \
    trianglemesh/diffuse.cpp

HEADERS  += \
    trimeshview.h \
    include/lineqn.h \
    include/timestamp.h \
    include/bsphere.h \
    include/KDtree.h \
    include/mempool.h \
    include/Color.h \
    mainwindow.h \
    featurelines.h \
    threshdialog.h \
    include/meshalgo.h

FORMS += \
    mainwindow.ui \
    threshdialog.ui










































































