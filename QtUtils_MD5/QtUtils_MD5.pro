TEMPLATE        = lib
CONFIG         += plugin
TARGET          = $$qtLibraryTarget(MD5)

win32 {
    CONFIG(debug, release|debug):DESTDIR = ../debug/plugins
    CONFIG(release, release|debug):DESTDIR = ../release/plugins
} else {
    DESTDIR    = ../plugins
}


INCLUDEPATH += ../QtUtils
HEADERS += \
    mymd5.h \
    md5form.h

SOURCES += \
    mymd5.cpp \
    md5form.cpp

FORMS += \
    md5form.ui





