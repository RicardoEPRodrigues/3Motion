#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
}

DivisactionWindow::~DivisactionWindow()
{
    delete ui;
}
