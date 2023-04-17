QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXX = g++
CONFIG += c++17

RESOURCES = resources.qrc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += src

SOURCES += \
    src/gameui/gameconfig.cpp \
    src/widgets/betcontrols.cpp \
    src/blackjack/blackjack.cpp \
    src/blackjack/card.cpp \
    src/blackjack/deck.cpp \
    src/audio/gameaudio.cpp \
    src/widgets/gamecontrols.cpp \
    src/widgets/gameendmessage.cpp \
    src/widgets/gameinfo.cpp \
    src/widgets/gamesceneview.cpp \
    src/blackjack/hand.cpp \
    src/widgets/handinfo.cpp \
    src/main.cpp \
    src/gameui/bjwindow.cpp \
    src/util/qutil.cpp \
    src/resources.cpp \
    src/graphics/scene.cpp \
    src/graphics/spritesheet.cpp

HEADERS += \
    src/gameui/gameconfig.h \
    src/widgets/betcontrols.h \
    src/gameui/bjwindow.h \
    src/blackjack/blackjack.h \
    src/blackjack/card.h \
    src/blackjack/deck.h \
    src/audio/gameaudio.h \
    src/widgets/gamecontrols.h \
    src/widgets/gameendmessage.h \
    src/widgets/gameinfo.h \
    src/widgets/gamesceneview.h \
    src/blackjack/hand.h \
    src/widgets/handinfo.h \
    src/util/qutil.h \
    src/util/dialogs.h \
    src/resources.h \
    src/graphics/scene.h \
    src/graphics/spritesheet.h \
    src/types.h

FORMS += \
    src/widgets/betcontrols.ui \
    src/gameui/bjwindow.ui \
    src/widgets/gamecontrols.ui \
    src/widgets/gameendmessage.ui \
    src/widgets/gameinfo.ui \
    src/widgets/handinfo.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
