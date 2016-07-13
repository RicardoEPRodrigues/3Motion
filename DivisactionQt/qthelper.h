/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef HELPER_H
#define HELPER_H

#include <QWidget>
#include <QStyle>

class QtHelper
{
private:
    QtHelper();
public:
    static void setProperty(QWidget* object, const char* name, const QVariant & value);
};

#endif // HELPER_H
