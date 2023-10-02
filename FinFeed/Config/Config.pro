TEMPLATE = app

CONFIG += console c++20
CONFIG -= app_bundle
#CONFIG -= qt             # this needs to be removed

QT += core                # this should be added
QT += sql                 # this should be added

SOURCES += \
        config.cpp \
        main.cpp \
        ../MainDatabase/db_accessor.cpp



HEADERS += \
        ../MainDatabase/db_accessor.h \
        config.h

