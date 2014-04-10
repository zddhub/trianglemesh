#-------------------------------------------------
#
# Project created by QtCreator 2013-03-02T10:57:14
#
#-------------------------------------------------

QT       += core gui \
            opengl

TARGET = trimeshview
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    trianglemesh/trianglemesh.h \
    trianglemesh/XForm.h \
    trianglemesh/Vec.h \
    trianglemesh/strutil.h \
    XForm.h \
    Vec.h \
    trianglemesh.h \
    strutil.h \
    GLCamera.h \
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

INCLUDEPATH += ./include

FORMS += \
    mainwindow.ui \
    threshdialog.ui










































































