QT       += core gui

QT += core                # this should be added
QT += sql                 # this should be added

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ../Config/config.cpp \
    ../MainDatabase/db_accessor.cpp \
    ../Information_Channels/community.cpp \
    ../Information_Channels/subcommunity.cpp \
    ../Communication_Toolset/thread.cpp \
    ../Communication_Toolset/message.cpp

HEADERS += \
    mainwindow.h \
    ../Config/config.h \
    ../MainDatabase/db_accessor.h \
    ../Information_Channels/community.h \
    ../Information_Channels/subcommunity.h \
    ../Communication_Toolset/thread.h \
    ../Communication_Toolset/message.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
