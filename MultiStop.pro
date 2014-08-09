#-------------------------------------------------
#
# Project created by QtCreator 2014-08-08T10:55:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MultiStop
TEMPLATE = app


SOURCES += main.cpp\
        multistop.cpp \
    timelistmodel.cpp \
    clock.cpp

HEADERS  += multistop.h \
    timelistmodel.h \
    clock.h

FORMS    += multistop.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

