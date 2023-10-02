TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt             # this needs to be removed

QT += core                # this should be added
QT += sql                 # this should be added

SOURCES += \
        main.cpp \
        message.cpp \
        thread.cpp \
        ../Config/config.cpp \
        ../MainDatabase/db_accessor.cpp

HEADERS += \
    message.h \
    thread.h \
    ../Config/config.h \
    ../MainDatabase/db_accessor.h
