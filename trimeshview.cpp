
#include "trimeshview.h"
#include <QTime>
#include <QFile>
#include <QTextStream>

//输出数据_测试用
void TriMeshView::write_to_file(const vector<float> &v, const QString &filename)
{
    QFile file(filename);
    file.open(QFile::WriteOnly);

    QTextStream out(&file);

    for(unsigned int i = 0; i < v.size(); i++)
    {
        out << v[i] - 1.0f << "\r";
    }
    out <<"\r\n";

    file.close();
}

TriMeshView::TriMeshView(QWidget *parent) :
    QGLWidget(parent)
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setSizePolicy(sizePolicy);

    this->setFocusPolicy(Qt::StrongFocus);//QWidget只有设置焦点才能进行按键响应

    this->timer = new QTimer(this);
    timer->start(1);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(autospin()));

    resize(840, 720);

    isCtrlPressed = false;
    triMesh = NULL;
    feature_size = 0.0f;

    currcolor = vec(0.0, 0.0, 0.0);
    currsmooth = 0.0f;

    sug_thresh = 0.05f;
//    rv_thresh = 0.05f;
    rv_thresh = 0.15f;
    ar_thresh = 0.1f;

    closeAllDrawings();

    isSavedRV = false;
    isSavedOc = false;
}

TriMeshView::~TriMeshView()
{
    if(triMesh)
    {
        delete triMesh;
        triMesh = NULL;
    }
}

void TriMeshView::autospin()
{
    if(camera.autospin(xf))
    {
        updateGL();
    }
}

void TriMeshView::closeAllDrawings()
{
    //draw_base
    isDrawEdges = false;

    isDrawNormals = false;
    isDrawPreview = false;
    isDrawCurv1 = false;
    isDrawCurv2 = false;

    isDrawCurvColors = false;
    isDrawNormalColors = false;

    //draw_lines

    isDrawBoundaries = false;

    isDrawSilhouette = false;
    isDrawOccludingContours = false;
    isDrawSuggestiveContours = false;

    isDrawIsophotes = false;
    isDrawTopolines = false;

    isDrawRidges = false;
    isDrawValleys = false;

    isDrawApparentRidges = false;

    isDrawRVLines = false;
    isDrawRVFaces = false;
    isDrawOCLines = false;
    isDrawOCFaces = false;
}

bool TriMeshView::readMesh(const char *filename, const char *xffilename)
{
    if(triMesh)
    {
        delete triMesh;
        triMesh = NULL;

        curv_colors.clear();
        normal_colors.clear();

        rv_fLines.clear();
        c_fLines.clear();
    }

    triMesh = TriangleMesh::read(filename);
    if(!triMesh)
    {
        cout<<"read file "<<filename<<" error."<<endl;
        exit(-1);
    }

    triMesh->need_tstrips();
    triMesh->need_bsphere();
    triMesh->need_normals();

    QTime time;

    time.start();//开始计时，以ms为单位

    triMesh->need_curvatures();
    triMesh->need_dcurv();

    int time_Diff = time.elapsed(); //返回从上次start()或restart()开始以来的时间差，单位ms
    //以下方法是将ms转为s
    float f = time_Diff/1000.0;
    printf("compute curvatures: %f\n", f);fflush(stdout);



//    write_to_file(triMesh->curv1, "normal_curv1.txt");
//    write_to_file(triMesh->curv2, "normal_curv2.txt");

    feature_size = triMesh->feature_size();
    currsmooth = 0.5 * triMesh->feature_size();

    if(!xf.read(xffilename))
        xf = xform::trans(0, 0, -3.5f / 0.7 * triMesh->bsphere.r) *
                             xform::trans(-triMesh->bsphere.center);

    camera.stopspin();

    updateGL();
    return true;
}

//------------------------protected function------------------------

void TriMeshView::resizeGL(int width, int height)
{
    //设置opengl视口与QWidget窗口大小相同
    glViewport( 0, 0, (GLint)width, (GLint)height );
}

// Clear the screen and reset OpenGL modes to something sane
void TriMeshView::cls()
{
    glDisable(GL_DITHER);
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    glClearColor(1,1,1,0);
//        if (color_style == COLOR_GRAY)
//                glClearColor(0.8, 0.8, 0.8, 0);
    glClearDepth(1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void TriMeshView::paintGL()
{
    if(!triMesh)
    {
        cls();
        return;
    }

    viewpos = inv(xf) * point(0,0,0);

    camera.setupGL(xf * triMesh->bsphere.center, triMesh->bsphere.r);

    cls();

    // Transform and draw
    glPushMatrix();

    glMultMatrixd((double *)xf);
    draw_mesh();
    glPopMatrix();
}

//鼠标交互处理
Mouse::button btn = Mouse::NONE;
void TriMeshView::mousePressEvent(QMouseEvent *e)
{
    if(!triMesh)
        return;

    int x = e->pos().x();
    int y = e->pos().y();

    if(e->button() ==  Qt::LeftButton)
    {
        if(isCtrlPressed)
            btn = Mouse::LIGHT;
        else
            btn = Mouse::ROTATE;
    }
    else if(e->button() == Qt::RightButton)
    {
        if(isCtrlPressed)
            btn = Mouse::LIGHT;
        else
            btn = Mouse::MOVEZ;
    }
    else if(e->button() == Qt::MidButton)
    {
        btn = Mouse::MOVEXY;
    }
    else
        btn = Mouse::NONE;

    //根据鼠标交互位置(x,y)重新放置摄像机
 //   camera.setupGL(xf*triMesh->bsphere.center, triMesh->bsphere.r);
    camera.mouse(x, y, btn, xf*triMesh->bsphere.center, triMesh->bsphere.r, xf);

    mouseMoveEvent(e);
}

void TriMeshView::mouseReleaseEvent(QMouseEvent * e)
{
    if(!triMesh)
        return;

    int x = e->pos().x();
    int y = e->pos().y();

    btn = Mouse::NONE;

    camera.mouse(x, y, btn, xf*triMesh->bsphere.center, triMesh->bsphere.r, xf);
}

void TriMeshView::mouseMoveEvent(QMouseEvent *e)
{
    if(!triMesh)
        return;

    int x = e->pos().x();
    int y = e->pos().y();

    if(e->buttons() &  Qt::LeftButton) //该函数中，e->button()总是返回Qt::NoButton.
    {
        btn = Mouse::ROTATE;
    }
    else if(e->buttons() &  Qt::RightButton)
    {
        btn = Mouse::MOVEZ;
    }
    else if(e->buttons() &  Qt::MidButton)
    {
        btn = Mouse::MOVEXY;
    }
    else
    {
        btn = Mouse::NONE;
    }

    camera.mouse(x, y, btn, xf*triMesh->bsphere.center, triMesh->bsphere.r, xf);

    if(btn != Mouse::NONE)
        updateGL();
}

void TriMeshView::wheelEvent(QWheelEvent *e)
{
    if(!triMesh)
        return;

    int x = e->pos().x();
    int y = e->pos().y();

    if(e->orientation() == Qt::Vertical)
    {
        if (e->delta() > 0)
        {
            btn = Mouse::WHEELUP;
        }
        else
        {
            btn = Mouse::WHEELDOWN;
        }
    }

    e->accept();
    camera.mouse(x, y, btn, xf*triMesh->bsphere.center, triMesh->bsphere.r, xf);
    //btn = Mouse::NONE;
    updateGL();
}

void TriMeshView::keyPressEvent(QKeyEvent *e)
{
    if(!triMesh)
        return;

    switch(e->key())
    {
    case Qt::Key_Control:
        isCtrlPressed = true;
        break;
    default:
        QGLWidget::keyPressEvent(e);
    }
    updateGL();
}

void TriMeshView::keyReleaseEvent(QKeyEvent * /*e*/)
{
    isCtrlPressed = false;
}
