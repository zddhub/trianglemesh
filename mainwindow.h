/*************************************************************************
 * Copyright (c) 2014 Zhang Dongdong
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trimeshview.h"

#include "threshdialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void open();
    void setThresh();

private slots:
    void on_actionEdges_triggered();

    void on_actionNormals_triggered();

    void on_actionPrincipal_1_triggered();

    void on_actionPrincipal_2_triggered();

    void on_actionNormalColor_triggered();

    void on_actionCurv_Color_triggered();

    void on_actionBoundaries_triggered();

    void on_actionPreview_triggered();

    void on_actionExterior_Silhouette_triggered();

    void on_actionOccluding_Contours_triggered();

    void on_actionSuggestive_Contours_triggered();

    void on_actionRidges_triggered();

    void on_actionValleys_triggered();

    void on_actionApparent_Ridges_triggered();

    void on_actionSave_Ridges_file_triggered();

    void on_actionSave_Occluding_file_triggered();

    void on_actionLines_triggered();

    void on_actionFaces_triggered();

    void on_actionLines_2_triggered();

    void on_actionFaces_2_triggered();

    void on_actionSave_RV_mesh_file_triggered();

    void on_actionSave_OC_mesh_file_triggered();

    void on_actionOpen_LD_file_triggered();

    void on_actionThresh_triggered();

    void on_actionSmooth_curv_triggered();

    void on_actionSmooth_DCurv_triggered();

    void on_actionSave_curv1_triggered();

    void on_actionSave_Curv2_triggered();

    void on_actionLaplace_Smooth_triggered();

    void on_actionRidge_Valley_triggered();

private:
    Ui::MainWindow *ui;
    ThreshDialog *threshDialog;

    TriMeshView *meshView;
};

#endif // MAINWINDOW_H
