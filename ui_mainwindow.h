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
/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jul 19 08:24:26 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionEdges;
    QAction *actionNormals;
    QAction *actionPrincipal_1;
    QAction *actionPrincipal_2;
    QAction *actionNormalColor;
    QAction *actionCurv_Color;
    QAction *actionBoundaries;
    QAction *actionPreview;
    QAction *actionExterior_Silhouette;
    QAction *actionOccluding_Contours;
    QAction *actionSuggestive_Contours;
    QAction *actionRidges;
    QAction *actionValleys;
    QAction *actionApparent_Ridges;
    QAction *actionSave_Ridges_file;
    QAction *actionSave_Occluding_file;
    QAction *actionLines;
    QAction *actionFaces;
    QAction *actionLines_2;
    QAction *actionFaces_2;
    QAction *actionSave_RV_mesh_file;
    QAction *actionSave_OC_mesh_file;
    QAction *actionOpen_LD_file;
    QAction *actionThresh;
    QAction *actionSmooth_curv;
    QAction *actionSmooth_DCurv;
    QAction *actionSave_curv1;
    QAction *actionSave_Curv2;
    QAction *actionLaplace_Smooth;
    QAction *actionRidge_Valley;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuVectors;
    QMenu *menuVector;
    QMenu *menuLines;
    QMenu *menuColor;
    QMenu *menuRV;
    QMenu *menuOcludding;
    QMenu *menuThresh;
    QMenu *menuImproved_Method;
    QMenu *menuTestTime;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionEdges = new QAction(MainWindow);
        actionEdges->setObjectName(QString::fromUtf8("actionEdges"));
        actionEdges->setCheckable(true);
        actionNormals = new QAction(MainWindow);
        actionNormals->setObjectName(QString::fromUtf8("actionNormals"));
        actionNormals->setCheckable(true);
        actionPrincipal_1 = new QAction(MainWindow);
        actionPrincipal_1->setObjectName(QString::fromUtf8("actionPrincipal_1"));
        actionPrincipal_1->setCheckable(true);
        actionPrincipal_2 = new QAction(MainWindow);
        actionPrincipal_2->setObjectName(QString::fromUtf8("actionPrincipal_2"));
        actionPrincipal_2->setCheckable(true);
        actionNormalColor = new QAction(MainWindow);
        actionNormalColor->setObjectName(QString::fromUtf8("actionNormalColor"));
        actionNormalColor->setCheckable(true);
        actionCurv_Color = new QAction(MainWindow);
        actionCurv_Color->setObjectName(QString::fromUtf8("actionCurv_Color"));
        actionCurv_Color->setCheckable(true);
        actionBoundaries = new QAction(MainWindow);
        actionBoundaries->setObjectName(QString::fromUtf8("actionBoundaries"));
        actionBoundaries->setCheckable(true);
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QString::fromUtf8("actionPreview"));
        actionPreview->setCheckable(true);
        actionExterior_Silhouette = new QAction(MainWindow);
        actionExterior_Silhouette->setObjectName(QString::fromUtf8("actionExterior_Silhouette"));
        actionExterior_Silhouette->setCheckable(true);
        actionOccluding_Contours = new QAction(MainWindow);
        actionOccluding_Contours->setObjectName(QString::fromUtf8("actionOccluding_Contours"));
        actionOccluding_Contours->setCheckable(true);
        actionSuggestive_Contours = new QAction(MainWindow);
        actionSuggestive_Contours->setObjectName(QString::fromUtf8("actionSuggestive_Contours"));
        actionSuggestive_Contours->setCheckable(true);
        actionRidges = new QAction(MainWindow);
        actionRidges->setObjectName(QString::fromUtf8("actionRidges"));
        actionRidges->setCheckable(true);
        actionValleys = new QAction(MainWindow);
        actionValleys->setObjectName(QString::fromUtf8("actionValleys"));
        actionValleys->setCheckable(true);
        actionApparent_Ridges = new QAction(MainWindow);
        actionApparent_Ridges->setObjectName(QString::fromUtf8("actionApparent_Ridges"));
        actionApparent_Ridges->setCheckable(true);
        actionSave_Ridges_file = new QAction(MainWindow);
        actionSave_Ridges_file->setObjectName(QString::fromUtf8("actionSave_Ridges_file"));
        actionSave_Occluding_file = new QAction(MainWindow);
        actionSave_Occluding_file->setObjectName(QString::fromUtf8("actionSave_Occluding_file"));
        actionLines = new QAction(MainWindow);
        actionLines->setObjectName(QString::fromUtf8("actionLines"));
        actionLines->setCheckable(true);
        actionFaces = new QAction(MainWindow);
        actionFaces->setObjectName(QString::fromUtf8("actionFaces"));
        actionFaces->setCheckable(true);
        actionLines_2 = new QAction(MainWindow);
        actionLines_2->setObjectName(QString::fromUtf8("actionLines_2"));
        actionLines_2->setCheckable(true);
        actionFaces_2 = new QAction(MainWindow);
        actionFaces_2->setObjectName(QString::fromUtf8("actionFaces_2"));
        actionFaces_2->setCheckable(true);
        actionSave_RV_mesh_file = new QAction(MainWindow);
        actionSave_RV_mesh_file->setObjectName(QString::fromUtf8("actionSave_RV_mesh_file"));
        actionSave_OC_mesh_file = new QAction(MainWindow);
        actionSave_OC_mesh_file->setObjectName(QString::fromUtf8("actionSave_OC_mesh_file"));
        actionOpen_LD_file = new QAction(MainWindow);
        actionOpen_LD_file->setObjectName(QString::fromUtf8("actionOpen_LD_file"));
        actionThresh = new QAction(MainWindow);
        actionThresh->setObjectName(QString::fromUtf8("actionThresh"));
        actionSmooth_curv = new QAction(MainWindow);
        actionSmooth_curv->setObjectName(QString::fromUtf8("actionSmooth_curv"));
        actionSmooth_DCurv = new QAction(MainWindow);
        actionSmooth_DCurv->setObjectName(QString::fromUtf8("actionSmooth_DCurv"));
        actionSave_curv1 = new QAction(MainWindow);
        actionSave_curv1->setObjectName(QString::fromUtf8("actionSave_curv1"));
        actionSave_Curv2 = new QAction(MainWindow);
        actionSave_Curv2->setObjectName(QString::fromUtf8("actionSave_Curv2"));
        actionLaplace_Smooth = new QAction(MainWindow);
        actionLaplace_Smooth->setObjectName(QString::fromUtf8("actionLaplace_Smooth"));
        actionRidge_Valley = new QAction(MainWindow);
        actionRidge_Valley->setObjectName(QString::fromUtf8("actionRidge_Valley"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuVectors = new QMenu(menubar);
        menuVectors->setObjectName(QString::fromUtf8("menuVectors"));
        menuVector = new QMenu(menubar);
        menuVector->setObjectName(QString::fromUtf8("menuVector"));
        menuLines = new QMenu(menubar);
        menuLines->setObjectName(QString::fromUtf8("menuLines"));
        menuColor = new QMenu(menubar);
        menuColor->setObjectName(QString::fromUtf8("menuColor"));
        menuRV = new QMenu(menubar);
        menuRV->setObjectName(QString::fromUtf8("menuRV"));
        menuOcludding = new QMenu(menubar);
        menuOcludding->setObjectName(QString::fromUtf8("menuOcludding"));
        menuThresh = new QMenu(menubar);
        menuThresh->setObjectName(QString::fromUtf8("menuThresh"));
        menuImproved_Method = new QMenu(menubar);
        menuImproved_Method->setObjectName(QString::fromUtf8("menuImproved_Method"));
        menuTestTime = new QMenu(menubar);
        menuTestTime->setObjectName(QString::fromUtf8("menuTestTime"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuVectors->menuAction());
        menubar->addAction(menuVector->menuAction());
        menubar->addAction(menuLines->menuAction());
        menubar->addAction(menuColor->menuAction());
        menubar->addAction(menuRV->menuAction());
        menubar->addAction(menuOcludding->menuAction());
        menubar->addAction(menuThresh->menuAction());
        menubar->addAction(menuImproved_Method->menuAction());
        menubar->addAction(menuTestTime->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_LD_file);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Ridges_file);
        menuFile->addAction(actionSave_Occluding_file);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_RV_mesh_file);
        menuFile->addAction(actionSave_OC_mesh_file);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_curv1);
        menuFile->addAction(actionSave_Curv2);
        menuVectors->addAction(actionEdges);
        menuVector->addAction(actionNormals);
        menuVector->addAction(actionPrincipal_1);
        menuVector->addAction(actionPrincipal_2);
        menuVector->addAction(actionPreview);
        menuLines->addAction(actionBoundaries);
        menuLines->addAction(actionExterior_Silhouette);
        menuLines->addAction(actionOccluding_Contours);
        menuLines->addAction(actionSuggestive_Contours);
        menuLines->addAction(actionRidges);
        menuLines->addAction(actionValleys);
        menuLines->addAction(actionApparent_Ridges);
        menuColor->addAction(actionNormalColor);
        menuColor->addAction(actionCurv_Color);
        menuRV->addAction(actionLines);
        menuRV->addAction(actionFaces);
        menuOcludding->addAction(actionLines_2);
        menuOcludding->addAction(actionFaces_2);
        menuThresh->addAction(actionThresh);
        menuImproved_Method->addAction(actionSmooth_curv);
        menuImproved_Method->addAction(actionSmooth_DCurv);
        menuImproved_Method->addAction(actionLaplace_Smooth);
        menuTestTime->addAction(actionRidge_Valley);

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(open()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LineDrawing", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionEdges->setText(QApplication::translate("MainWindow", "Edges", 0));
        actionNormals->setText(QApplication::translate("MainWindow", "Normal", 0));
        actionPrincipal_1->setText(QApplication::translate("MainWindow", "Principal 1", 0));
        actionPrincipal_2->setText(QApplication::translate("MainWindow", "Principal 2", 0));
        actionNormalColor->setText(QApplication::translate("MainWindow", "Norm Color", 0));
        actionCurv_Color->setText(QApplication::translate("MainWindow", "Curv Color", 0));
        actionBoundaries->setText(QApplication::translate("MainWindow", "Boundaries", 0));
        actionPreview->setText(QApplication::translate("MainWindow", "Preview", 0));
        actionExterior_Silhouette->setText(QApplication::translate("MainWindow", "Exterior Silhouette", 0));
        actionOccluding_Contours->setText(QApplication::translate("MainWindow", "Occluding Contours", 0));
        actionSuggestive_Contours->setText(QApplication::translate("MainWindow", "Suggestive Contours", 0));
        actionRidges->setText(QApplication::translate("MainWindow", "Ridges", 0));
        actionValleys->setText(QApplication::translate("MainWindow", "Valleys", 0));
        actionApparent_Ridges->setText(QApplication::translate("MainWindow", "Apparent Ridges", 0));
        actionSave_Ridges_file->setText(QApplication::translate("MainWindow", "Save Ridge-Valley file", 0));
        actionSave_Occluding_file->setText(QApplication::translate("MainWindow", "Save Occluding file", 0));
        actionLines->setText(QApplication::translate("MainWindow", "Lines", 0));
        actionFaces->setText(QApplication::translate("MainWindow", "Faces", 0));
        actionLines_2->setText(QApplication::translate("MainWindow", "Lines", 0));
        actionFaces_2->setText(QApplication::translate("MainWindow", "Faces", 0));
        actionSave_RV_mesh_file->setText(QApplication::translate("MainWindow", "Save RV mesh file", 0));
        actionSave_OC_mesh_file->setText(QApplication::translate("MainWindow", "Save OC mesh file", 0));
        actionOpen_LD_file->setText(QApplication::translate("MainWindow", "Open LD file", 0));
        actionThresh->setText(QApplication::translate("MainWindow", "Thresh", 0));
        actionSmooth_curv->setText(QApplication::translate("MainWindow", "Our Method", 0));
        actionSmooth_DCurv->setText(QApplication::translate("MainWindow", "Smooth DCurv", 0));
        actionSave_curv1->setText(QApplication::translate("MainWindow", "Save Curv1", 0));
        actionSave_Curv2->setText(QApplication::translate("MainWindow", "Save Curv2", 0));
        actionLaplace_Smooth->setText(QApplication::translate("MainWindow", "Laplace Smooth", 0));
        actionRidge_Valley->setText(QApplication::translate("MainWindow", "Ridge-Valley", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuVectors->setTitle(QApplication::translate("MainWindow", "Mesh", 0));
        menuVector->setTitle(QApplication::translate("MainWindow", "Vector", 0));
        menuLines->setTitle(QApplication::translate("MainWindow", "Lines", 0));
        menuColor->setTitle(QApplication::translate("MainWindow", "Color", 0));
        menuRV->setTitle(QApplication::translate("MainWindow", "Ridge-Valley", 0));
        menuOcludding->setTitle(QApplication::translate("MainWindow", "Ocludding", 0));
        menuThresh->setTitle(QApplication::translate("MainWindow", "Thresh Control", 0));
        menuImproved_Method->setTitle(QApplication::translate("MainWindow", "Improved Method", 0));
        menuTestTime->setTitle(QApplication::translate("MainWindow", "TestTime", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
