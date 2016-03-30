#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T18:37:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DivisactionQt
TEMPLATE = app


SOURCES += main.cpp\
        divisactionwindow.cpp \
    actionprogress.cpp

HEADERS  += divisactionwindow.h \
    actionprogress.h

FORMS    += divisactionwindow.ui \
    actionprogress.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Divisaction/Debug/ -lDivisaction
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Divisaction/Debug/ -lDivisaction
else:unix: LIBS += -L$$PWD/../Divisaction/Debug/ -lDivisaction

INCLUDEPATH += $$PWD/../Divisaction/
DEPENDPATH += $$PWD/../Divisaction/
