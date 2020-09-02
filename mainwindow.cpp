#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qimagewidget.h"
#include "figure.h"
#include "toolbar.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ToolBar *toolBar = new ToolBar(this);
    QImageWidget* image = new QImageWidget(toolBar, this);


    ui->verticalLayout->addWidget(toolBar);

    ui->verticalLayout->addWidget(image);

    ui->verticalLayout->setStretch(1,1);
    ui->verticalLayout->setStretch(1,1);

    connect(toolBar, &ToolBar::dataReady, image, &QImageWidget::QParseFileData);
}

MainWindow::~MainWindow()
{
    delete ui;



}





