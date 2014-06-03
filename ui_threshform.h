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
** Form generated from reading UI file 'threshform.ui'
**
** Created: Fri May 10 15:37:54 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHFORM_H
#define UI_THRESHFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreshForm
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *rv_horizontalSlider;
    QLabel *label_2;
    QSlider *ar_horizontalSlider;
    QLabel *label_3;
    QSlider *sug_horizontalSlider;

    void setupUi(QWidget *ThreshForm)
    {
        if (ThreshForm->objectName().isEmpty())
            ThreshForm->setObjectName(QString::fromUtf8("ThreshForm"));
        ThreshForm->resize(272, 153);
        widget = new QWidget(ThreshForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 146, 71));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        rv_horizontalSlider = new QSlider(widget);
        rv_horizontalSlider->setObjectName(QString::fromUtf8("rv_horizontalSlider"));
        rv_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rv_horizontalSlider, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        ar_horizontalSlider = new QSlider(widget);
        ar_horizontalSlider->setObjectName(QString::fromUtf8("ar_horizontalSlider"));
        ar_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ar_horizontalSlider, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        sug_horizontalSlider = new QSlider(widget);
        sug_horizontalSlider->setObjectName(QString::fromUtf8("sug_horizontalSlider"));
        sug_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sug_horizontalSlider, 2, 1, 1, 1);


        retranslateUi(ThreshForm);

        QMetaObject::connectSlotsByName(ThreshForm);
    } // setupUi

    void retranslateUi(QWidget *ThreshForm)
    {
        ThreshForm->setWindowTitle(QApplication::translate("ThreshForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ThreshForm", "rv_thresh", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ThreshForm", "ar_thresh", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ThreshForm", "sug_thresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThreshForm: public Ui_ThreshForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHFORM_H
