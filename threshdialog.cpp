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
#include "threshdialog.h"
#include "ui_threshdialog.h"

//ThreshDialog::ThreshDialog(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::ThreshDialog)
//{
//    ui->setupUi(this);
//    this->setModal(false);

//    ui->ar_horizontalSlider->setRange(0, 1000);
//    ui->rv_horizontalSlider->setRange(0, 1000);
//    ui->sug_horizontalSlider->setRange(0, 1000);
//}

#define SLIDER_RANGE 1000

ThreshDialog::ThreshDialog(TriMeshView *view, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreshDialog)
{
    meshView = view;

    ui->setupUi(this);
    this->setModal(false);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->ar_horizontalSlider->setRange(0, SLIDER_RANGE);
    ui->rv_horizontalSlider->setRange(0, SLIDER_RANGE);
    ui->sug_horizontalSlider->setRange(0, SLIDER_RANGE);

    ui->ar_horizontalSlider->setValue((int) (meshView->getArThresh()*SLIDER_RANGE)/0.5);
    ui->rv_horizontalSlider->setValue((int) (meshView->getRvThresh()*SLIDER_RANGE)/0.5);
    ui->sug_horizontalSlider->setValue((int) (meshView->getSugThresh()*SLIDER_RANGE)/0.1);

    ui->ar_threshLabel->setText(QString("%1").arg(meshView->getArThresh()));
    ui->rv_threshLabel->setText(QString("%1").arg(meshView->getRvThresh()));
    ui->sug_threshLabel->setText(QString("%1").arg(meshView->getSugThresh()));
}

ThreshDialog::~ThreshDialog()
{
    delete ui;
}

void ThreshDialog::on_sug_horizontalSlider_valueChanged(int value)
{
    float sug = (0.1*value)/SLIDER_RANGE;
    meshView->setSugThresh(sug);
    meshView->update();

    ui->sug_threshLabel->setText(QString("%1").arg(sug));
}

void ThreshDialog::on_rv_horizontalSlider_valueChanged(int value)
{
    float rv = (0.5*value)/SLIDER_RANGE;
    meshView->setRvThresh(rv);
    meshView->update();

    ui->rv_threshLabel->setText(QString("%1").arg(rv));
}

void ThreshDialog::on_ar_horizontalSlider_valueChanged(int value)
{
    float ar = (0.5*value)/SLIDER_RANGE;
    meshView->setArThresh(ar);
    meshView->update();

    ui->ar_threshLabel->setText(QString("%1").arg(ar));
}
