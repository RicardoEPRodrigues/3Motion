#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

#include "actionprogress.h"

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
    ui->ActionStackLayout->setAlignment(Qt::AlignTop);

    for(int i = 1; i <= 10; i++) {
        ActionProgress * actionProgress = new ActionProgress();
        actionProgress->setLabel(QString("Super Action ") + QString::number(i));
        ui->ActionStackLayout->addWidget(actionProgress);
    }
}

DivisactionWindow::~DivisactionWindow()
{
    delete ui;
}
