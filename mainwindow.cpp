#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    meshView = new TriMeshView;

    threshDialog = new ThreshDialog(meshView, this);
    threshDialog->hide();

    ui->actionBoundaries->setChecked(true);
    meshView->isDrawBoundaries = true;

    ui->actionOccluding_Contours->setChecked(true);
    meshView->isDrawOccludingContours = true;

//    ui->actionRidges->setChecked(true);
//    meshView->isDrawRidges = true;


    this->setCentralWidget(meshView);
    this->statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));//取消状态栏中的竖线
    this->statusBar()->showMessage(tr("Ready."));
}

MainWindow::~MainWindow()
{
    delete threshDialog;
    delete meshView;
    delete ui;
}

void MainWindow::setThresh()
{
    threshDialog->show();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Obj"), "", tr("Obj Files (*.obj)"));

    if(!fileName.endsWith(tr(".obj")) && !fileName.endsWith(tr(".OBJ")))
        return;

    this->statusBar()->showMessage( tr("Opening file..."));
    meshView->readMesh(fileName.toStdString().c_str());
    this->statusBar()->showMessage( tr("Done."));

    QString wt = "LineDrawing -- " + fileName;
    this->setWindowTitle(wt);
}

void MainWindow::on_actionEdges_triggered()
{
    meshView->isDrawEdges = !meshView->isDrawEdges;
}

void MainWindow::on_actionNormals_triggered()
{
    meshView->isDrawNormals = !meshView->isDrawNormals;
}

void MainWindow::on_actionPrincipal_1_triggered()
{
    meshView->isDrawCurv1 = !meshView->isDrawCurv1;
}

void MainWindow::on_actionPrincipal_2_triggered()
{
    meshView->isDrawCurv2 = !meshView->isDrawCurv2;
}

void MainWindow::on_actionNormalColor_triggered()
{
    ui->actionCurv_Color->setChecked(false);
    meshView->isDrawCurvColors = false;
    meshView->isDrawNormalColors = !meshView->isDrawNormalColors;
}

void MainWindow::on_actionCurv_Color_triggered()
{
    ui->actionNormalColor->setChecked(false);
    meshView->isDrawNormalColors = false;
    meshView->isDrawCurvColors = !meshView->isDrawCurvColors;
}

void MainWindow::on_actionBoundaries_triggered()
{
    meshView->isDrawBoundaries = !meshView->isDrawBoundaries;
}

void MainWindow::on_actionPreview_triggered()
{
    meshView->isDrawPreview = !meshView->isDrawPreview;
}

void MainWindow::on_actionExterior_Silhouette_triggered()
{
    meshView->isDrawSilhouette = !meshView->isDrawSilhouette;
}

void MainWindow::on_actionOccluding_Contours_triggered()
{
    meshView->isDrawOccludingContours = !meshView->isDrawOccludingContours;
}

void MainWindow::on_actionSuggestive_Contours_triggered()
{
    meshView->isDrawSuggestiveContours = !meshView->isDrawSuggestiveContours;
}

void MainWindow::on_actionRidges_triggered()
{
    meshView->isDrawRidges = !meshView->isDrawRidges;
}

void MainWindow::on_actionValleys_triggered()
{
    meshView->isDrawValleys = !meshView->isDrawValleys;
}

void MainWindow::on_actionApparent_Ridges_triggered()
{
    meshView->isDrawApparentRidges = !meshView->isDrawApparentRidges;
}

void MainWindow::on_actionSave_Ridges_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("Ridges File(*.rv)"));
    if(!fileName.endsWith(tr(".rv")) && !fileName.endsWith(tr(".RV")))
        return;
    this->statusBar()->showMessage( tr("Save ridges file ..."));
    if(meshView->saveRidgesFile(fileName))
    {
        this->statusBar()->showMessage( tr("Save ridges file ... Done."));
        meshView->updateGL();
    }
    else
        this->statusBar()->showMessage( tr("Save ridges file ... Error."));
}

void MainWindow::on_actionSave_Occluding_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("Occluding File(*.oc)"));

    if(!fileName.endsWith(tr(".oc")) && !fileName.endsWith(tr(".OC")))
        return;
    this->statusBar()->showMessage( tr("Save OC file ..."));
    if(meshView->saveOccludingFile(fileName))
    {
        this->statusBar()->showMessage( tr("Save OC file ... Done."));
        meshView->updateGL();
    }
    else
        this->statusBar()->showMessage( tr("Save OC file ... Error."));
}

void MainWindow::on_actionLines_triggered()
{
    meshView->isDrawRVLines = !meshView->isDrawRVLines;
}

void MainWindow::on_actionFaces_triggered()
{
    meshView->isDrawRVFaces = !meshView->isDrawRVFaces;
}

void MainWindow::on_actionLines_2_triggered()
{
    meshView->isDrawOCLines = !meshView->isDrawOCLines;
}

void MainWindow::on_actionFaces_2_triggered()
{
    meshView->isDrawOCFaces = !meshView->isDrawOCFaces;
}

void MainWindow::on_actionSave_RV_mesh_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("RV Mesh File(*.obj)"));

    if(!fileName.endsWith(tr(".obj")) && !fileName.endsWith(tr(".OBJ")))
        return;
    this->statusBar()->showMessage( tr("Save RV Mesh File ..."));
    if(meshView->saveRVMeshFile(fileName))
    {
        this->statusBar()->showMessage( tr("Save RV Mesh file ... Done."));
        meshView->updateGL();
    }
    else
        this->statusBar()->showMessage( tr("Save RV Mesh file ... Error."));
}

void MainWindow::on_actionSave_OC_mesh_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("OC Mesh File(*.obj)"));

    if(!fileName.endsWith(tr(".obj")) && !fileName.endsWith(tr(".OBJ")))
        return;
    this->statusBar()->showMessage( tr("Save OC Mesh File ..."));
    if(meshView->saveOCMeshFile(fileName))
    {
        this->statusBar()->showMessage( tr("Save OC Mesh file ... Done."));
        meshView->updateGL();
    }
    else
        this->statusBar()->showMessage( tr("Save OC Mesh file ... Error."));
}

void MainWindow::on_actionOpen_LD_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open LineDrawings File"), "", tr("OC Files (*.oc) | RV Files (*.rv)"));

    if(!fileName.endsWith(tr(".oc")) && !fileName.endsWith(tr(".OC")) &&
       !fileName.endsWith(tr(".rv")) && !fileName.endsWith(tr(".RV")) )
        return;

    this->statusBar()->showMessage( tr("Opening file..."));
    //meshView->readMesh(fileName.toStdString().c_str());
    meshView->readFeatureLines(fileName);

    this->statusBar()->showMessage( tr("Done."));
}

void MainWindow::on_actionThresh_triggered()
{
    threshDialog->show();
}

void MainWindow::on_actionSmooth_curv_triggered()
{
    meshView->smooth_curv();
    this->statusBar()->showMessage( tr("Smooth Curv ... Done."));
}

void MainWindow::on_actionSmooth_DCurv_triggered()
{
    meshView->smooth_dcurv();
    this->statusBar()->showMessage( tr("Smooth DCurv ... Done."));
}

void MainWindow::on_actionSave_curv1_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("Curv1 File(*.txt)"));

    if(!fileName.endsWith(tr(".txt")) && !fileName.endsWith(tr(".TXT")))
        return;
    this->statusBar()->showMessage( tr("Curv1 File ..."));
    meshView->saveCurv1(fileName);
    this->statusBar()->showMessage( tr("Save Curv1 File ... Done."));
}

void MainWindow::on_actionSave_Curv2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save File"), "", tr("Curv2 File(*.txt)"));

    if(!fileName.endsWith(tr(".txt")) && !fileName.endsWith(tr(".TXT")))
        return;
    this->statusBar()->showMessage( tr("Curv2 File ..."));
    meshView->saveCurv2(fileName);
    this->statusBar()->showMessage( tr("Save Curv2 File ... Done."));
}

void MainWindow::on_actionLaplace_Smooth_triggered()
{
    meshView->laplace_smooth_curv();
    this->statusBar()->showMessage( tr("Smooth Laplace Curv ... Done."));
}

void MainWindow::on_actionRidge_Valley_triggered()
{
    meshView->time_ridge_valley();
    this->statusBar()->showMessage( tr("test ridge-valley time ... Done."));
}
