#-------------------------------------------------
#
# Project created by QtCreator 2012-01-05T21:22:51
#
#-------------------------------------------------

QT       += core gui

TARGET = QtUtils
TEMPLATE = app


win32 {
    CONFIG(debug, release|debug):DESTDIR = ../debug/
    CONFIG(release, release|debug):DESTDIR = ../release/
} else {
    DESTDIR    = ../
}

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    UtilInterface.h

FORMS    += widget.ui

