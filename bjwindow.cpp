
#include "bjwindow.h"
#include "ui_bjwindow.h"


BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BJWindow)
{
    ui->setupUi(this);
}

BJWindow::~BJWindow()
{
    delete ui;
}


