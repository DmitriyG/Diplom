#-------------------------------------------------
#
# Project created by QtCreator 2012-11-14T15:48:23
#
#-------------------------------------------------

QT       += network sql
QT       += core gui
QT += sql

TARGET = podsystem
TEMPLATE = app
INCLUDEPATH += C:/PSQL/include C:/PSQL/bin C:/PSQL/lib C:/Qt/qt/plugins/sqldrivers C:/Qt/qt/bin C:/Qt/mingw/bin
LIBS+= C:/PSQL/lib/libpq.lib

SOURCES += main.cpp\
        mainwindow.cpp \
    enter.cpp \
    tab.cpp

HEADERS  += mainwindow.h \
    enter.h \
    tab.h

FORMS    += mainwindow.ui \
    enter.ui \
    tab.ui \
    tab.ui
