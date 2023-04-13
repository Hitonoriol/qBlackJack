QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RESOURCES = resources.qrc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    betcontrols.cpp \
    blackjack.cpp \
    card.cpp \
    deck.cpp \
    dialogs.h \
    gamecontrols.cpp \
    gameinfo.cpp \
    hand.cpp \
    handinfo.cpp \
    main.cpp \
    bjwindow.cpp \
    resources.cpp \
    scene.cpp \
    spritesheet.cpp

HEADERS += \
    betcontrols.h \
    bjwindow.h \
    blackjack.h \
    card.h \
    deck.h \
    gamecontrols.h \
    gameinfo.h \
    hand.h \
    handinfo.h \
    resources.h \
    scene.h \
    spritesheet.h

FORMS += \
    betcontrols.ui \
    bjwindow.ui \
    gamecontrols.ui \
    gameinfo.ui \
    handinfo.ui

TRANSLATIONS += \
    bj_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
