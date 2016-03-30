#ifndef DIVISACTIONWINDOW_H
#define DIVISACTIONWINDOW_H

#include <QMainWindow>
#include "mamma.h"

namespace Ui {
class DivisactionWindow;
}

class DivisactionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DivisactionWindow(QWidget *parent = 0);
    ~DivisactionWindow();

private:
    Ui::DivisactionWindow *ui;
};

#endif // DIVISACTIONWINDOW_H
