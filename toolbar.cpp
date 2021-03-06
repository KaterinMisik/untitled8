#include "toolbar.h"
#include "ui_toolbar.h"
#include <QPushButton>
#include <qimagewidget.h>
#include <QObject>
#include <QToolButton>
#include <QDebug>
ToolBar::ToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBar)
{
    ui->setupUi(this);
    ui->rectangleControl->hide();
    ui->checkboxControl->hide();
    ui->saveControl->hide();



    connect(ui->pushButton, &QPushButton::clicked, this, &ToolBar::on_pushButton_clicked);



}



ToolBar::~ToolBar()
{
    delete ui;
}

void ToolBar::on_pushButton_clicked()
{

    QVector<QPoint> p1, p2;
    QFile file("C:/Users/kamil/Desktop/data2.txt");
    QStringList lineList;
    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream  in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            lineList.append(line);
        }
        emit(dataReady(lineList));
        file.close();
    }
}


bool ToolBar::isSaveBoxEnabled(void)

{


    return ui->saveControl->isChecked();

}

bool ToolBar::isrectanglingEnabled(void)

{

    return ui->RectangleControl->isChecked();
}


bool ToolBar::isRectanglingEnabled(void)

{

    return ui->rectangleControl->isChecked();

}
bool ToolBar::isCheckboxingEnabled(void)

{

    return ui->checkboxControl->isChecked();
}

bool ToolBar::isCircleEnabled(void)


{

    return ui->circleControl->isChecked();
}



bool ToolBar::isTriangleEnabled(void)

{

    return ui->TriangleControl->isChecked();
}

