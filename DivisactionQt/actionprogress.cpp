#include "actionprogress.h"
#include "ui_actionprogress.h"

ActionProgress::ActionProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionProgress)
{
    ui->setupUi(this);
}

ActionProgress::~ActionProgress()
{
    delete ui;
}

void ActionProgress::setLabel(QString name)
{
    this->ui->label->setText(name);
}
