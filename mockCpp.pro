TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        gameplay.cpp \
        main.cpp \
        replay.cpp

HEADERS += \
    Point.h \
    board.h \
    gameplay.h \
    replay.h
