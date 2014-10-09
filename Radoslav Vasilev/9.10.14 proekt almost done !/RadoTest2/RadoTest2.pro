TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Application.cpp \
    #RenderableImage.cpp \
    Background.cpp \
    IWidget.cpp \
    WidgetButtonBase.cpp \
    CardButton.cpp \
    logic/Card.cpp\
    logic/Deck.cpp\
    ButtonDeal.cpp \
    logic/AutoHold.cpp\
    DisplayButton.cpp \
    SoundButton.cpp \
    StatistcDisplays.cpp \
    HelpButton.cpp


LIBS += -lSDLmain -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Application.h \
  #  RenderableImage.h \
    Background.h \
    IWidget.h \
    WidgetButtonBase.h \
    CardButton.h \
    logic/Card.h\
    logic/Deck.h\
    ButtonDeal.h \
    logic/AutoHold.h\
    DisplayButton.h \
    SoundButton.h \
    StatistcDisplays.h \
    HelpButton.h

QMAKE_CXXFLAGS += -Wno-write-strings

