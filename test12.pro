QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credits.cpp \
    hp.cpp \
    klawisz.cpp \
    main.cpp \
    mainwindow.cpp \
    nuta.cpp \
    ok.cpp \
    perfect.cpp \
    songselect.cpp \
    tlo.cpp \
    utility.cpp

HEADERS += \
    credits.h \
    hp.h \
    klawisz.h \
    mainwindow.h \
    nuta.h \
    ok.h \
    perfect.h \
    songselect.h \
    tlo.h \
    utility.h

FORMS += \
    credits.ui \
    mainwindow.ui \
    songselect.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
