TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Application.cpp \
    Background.cpp \
    IWidget.cpp \
    WidgetButtonBase.cpp \
    CardButton.cpp \
    logic/Card.cpp\
    logic/Deck.cpp\
    ButtonDeal.cpp \
    logic/AutoHold.cpp\
    WinDisplay.cpp \
    SoundButton.cpp \
    StatistcDisplays.cpp \
    HelpButton.cpp\
    Logo.cpp


LIBS += -lSDLmain -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Application.h \
    Background.h \
    IWidget.h \
    WidgetButtonBase.h \
    CardButton.h \
    logic/Card.h\
    logic/Deck.h\
    ButtonDeal.h \
    logic/AutoHold.h\
    WinDisplay.h \
    SoundButton.h \
    StatistcDisplays.h \
    HelpButton.h \
    Logo.h

QMAKE_CXXFLAGS += -Wno-write-strings

