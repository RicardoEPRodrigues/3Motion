#ifndef ACTIONPROGRESS_H
#define ACTIONPROGRESS_H

#include <QWidget>

namespace Ui {
class ActionProgress;
}

class ActionProgress : public QWidget
{
    Q_OBJECT

public:
    explicit ActionProgress(QWidget *parent = 0);
    ~ActionProgress();

    void setLabel(QString name);

private:
    Ui::ActionProgress *ui;
};

#endif // ACTIONPROGRESS_H
