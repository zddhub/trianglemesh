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
