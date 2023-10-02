TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt             # this needs to be removed

QT += core                # this should be added
QT += sql                 # this should be added

SOURCES += main.cpp \
    db_accessor.cpp

HEADERS += \
    db_accessor.h
