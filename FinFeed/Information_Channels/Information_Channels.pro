TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt             # this needs to be removed

QT += core                # this should be added
QT += sql                 # this should be added

SOURCES += \
        community.cpp \
        main.cpp \
        subcommunity.cpp \
        ../Config/config.cpp \
        ../Communication_Toolset/message.cpp \
        ../Communication_Toolset/thread.cpp \
        ../MainDatabase/db_accessor.cpp

HEADERS += \
    community.h \
    subcommunity.h \
    ../Config/config.h \
    ../Communication_Toolset/message.h \
    ../Communication_Toolset/thread.h \
    ../MainDatabase/db_accessor.h \

