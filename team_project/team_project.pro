TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    gameboard.cpp \
    player.cpp \
    gamelauncher.cpp

HEADERS += \
    gameboard.h \
    player.h \
    gamelauncher.h
