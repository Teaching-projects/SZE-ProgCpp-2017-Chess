#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T21:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    king.cpp \
    queen.cpp \
    rook.cpp \
    bishop.cpp \
    knight.cpp \
    pawn.cpp \
    chessboard.cpp \
    game.cpp \
    chesspiece.cpp \
    player.cpp \
    discoveredstep.cpp

HEADERS  += mainwindow.h \
    king.h \
    queen.h \
    rook.h \
    bishop.h \
    knight.h \
    pawn.h \
    chessboard.h \
    game.h \
    chesspiece.h \
    player.h \
    piececolor.h \
    discoveredstep.h

FORMS    += mainwindow.ui
