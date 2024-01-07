QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Inventory-Management
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    logindialog.cpp \
    userswidget.cpp \
    inventorywidget.cpp \
    inboundwidget.cpp \
    outboundwidget.cpp \

HEADERS += \
    mainwindow.h \
    logindialog.h \
    const.h \
    userswidget.h \
    inventorywidget.h \
    inboundwidget.h \
    outboundwidget.h \

FORMS += \
    mainwindow.ui \
    logindialog.ui \
    userswidget.ui \
    inventorywidget.ui \
    inboundwidget.ui \
    outboundwidget.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
