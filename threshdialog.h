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
#ifndef THRESHDIALOG_H
#define THRESHDIALOG_H

#include "trimeshview.h"

#include <QDialog>

namespace Ui {
    class ThreshDialog;
}

class ThreshDialog : public QDialog
{
    Q_OBJECT

public:
    //explicit ThreshDialog(QWidget *parent = 0);
    ThreshDialog(TriMeshView *view, QWidget *parent = 0);
    ~ThreshDialog();

private slots:
    void on_sug_horizontalSlider_valueChanged(int value);

    void on_rv_horizontalSlider_valueChanged(int value);

    void on_ar_horizontalSlider_valueChanged(int value);

private:
    TriMeshView *meshView;
    Ui::ThreshDialog *ui;
};

#endif // THRESHDIALOG_H
