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
** Form generated from reading UI file 'threshdialog.ui'
**
** Created: Tue May 14 20:58:18 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHDIALOG_H
#define UI_THRESHDIALOG_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QSlider>

QT_BEGIN_NAMESPACE

class Ui_ThreshDialog
{
public:
    QGroupBox *groupBox;
    QSlider *rv_horizontalSlider;
    QLabel *rv_threshLabel;
    QGroupBox *groupBox_2;
    QSlider *ar_horizontalSlider;
    QLabel *ar_threshLabel;
    QGroupBox *groupBox_3;
    QSlider *sug_horizontalSlider;
    QLabel *sug_threshLabel;

    void setupUi(QDialog *ThreshDialog)
    {
        if (ThreshDialog->objectName().isEmpty())
            ThreshDialog->setObjectName(QString::fromUtf8("ThreshDialog"));
        ThreshDialog->resize(445, 327);
        groupBox = new QGroupBox(ThreshDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 20, 311, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox->setFont(font);
        rv_horizontalSlider = new QSlider(groupBox);
        rv_horizontalSlider->setObjectName(QString::fromUtf8("rv_horizontalSlider"));
        rv_horizontalSlider->setGeometry(QRect(20, 40, 261, 21));
        rv_horizontalSlider->setOrientation(Qt::Horizontal);
        rv_threshLabel = new QLabel(groupBox);
        rv_threshLabel->setObjectName(QString::fromUtf8("rv_threshLabel"));
        rv_threshLabel->setGeometry(QRect(200, 20, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        rv_threshLabel->setFont(font1);
        rv_threshLabel->setLayoutDirection(Qt::LeftToRight);
        rv_threshLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_2 = new QGroupBox(ThreshDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(70, 120, 311, 81));
        groupBox_2->setFont(font);
        ar_horizontalSlider = new QSlider(groupBox_2);
        ar_horizontalSlider->setObjectName(QString::fromUtf8("ar_horizontalSlider"));
        ar_horizontalSlider->setGeometry(QRect(20, 40, 261, 19));
        ar_horizontalSlider->setOrientation(Qt::Horizontal);
        ar_threshLabel = new QLabel(groupBox_2);
        ar_threshLabel->setObjectName(QString::fromUtf8("ar_threshLabel"));
        ar_threshLabel->setGeometry(QRect(210, 20, 71, 21));
        ar_threshLabel->setFont(font1);
        ar_threshLabel->setLayoutDirection(Qt::LeftToRight);
        ar_threshLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_3 = new QGroupBox(ThreshDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(70, 220, 311, 81));
        groupBox_3->setFont(font);
        sug_horizontalSlider = new QSlider(groupBox_3);
        sug_horizontalSlider->setObjectName(QString::fromUtf8("sug_horizontalSlider"));
        sug_horizontalSlider->setGeometry(QRect(20, 40, 261, 19));
        sug_horizontalSlider->setOrientation(Qt::Horizontal);
        sug_threshLabel = new QLabel(groupBox_3);
        sug_threshLabel->setObjectName(QString::fromUtf8("sug_threshLabel"));
        sug_threshLabel->setGeometry(QRect(200, 20, 81, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Catriel"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        sug_threshLabel->setFont(font2);
        sug_threshLabel->setLayoutDirection(Qt::LeftToRight);
        sug_threshLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(ThreshDialog);

        QMetaObject::connectSlotsByName(ThreshDialog);
    } // setupUi

    void retranslateUi(QDialog *ThreshDialog)
    {
        ThreshDialog->setWindowTitle(QApplication::translate("ThreshDialog", "Thresh Dialog", 0));
        groupBox->setTitle(QApplication::translate("ThreshDialog", "rv_thresh", 0));
        rv_threshLabel->setText(QApplication::translate("ThreshDialog", "rv_thresh", 0));
        groupBox_2->setTitle(QApplication::translate("ThreshDialog", "ar_thresh", 0));
        ar_threshLabel->setText(QApplication::translate("ThreshDialog", "ar_thresh", 0));
        groupBox_3->setTitle(QApplication::translate("ThreshDialog", "sug_thresh", 0));
        sug_threshLabel->setText(QApplication::translate("ThreshDialog", "sug_thresh", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreshDialog: public Ui_ThreshDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHDIALOG_H
