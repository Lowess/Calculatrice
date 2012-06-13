#-------------------------------------------------
#
# Project created by QtCreator 2012-05-10T17:11:55
#
#-------------------------------------------------

QT       += core gui

TARGET = Calculatrice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Rationnel.cpp \
    Reel.cpp \
    Complexe.cpp \
    Constante.cpp \
    Entier.cpp \
    Expression.cpp \
    Nombre.cpp \
    Operateur.cpp \
    Fabrique.cpp \
    Pile.cpp \
    Calculatrice.cpp \
    Option.cpp \
    CalculatriceException.cpp \
    OperateurUnaire.cpp \
    OperateurBinaire.cpp \
    Exp.cpp \
    Gardien.cpp

HEADERS  += mainwindow.h \
    Expression.h \
    Constante.h \
    Complexe.h \
    Nombre.h \
    Reel.h \
    Entier.h \
    Rationnel.h \
    Operateur.h \
    Fabrique.h \
    Pile.h \
    Calculatrice.h \
    Option.h \
    CalculatriceException.h \
    OperateurUnaire.h \
    OperateurBinaire.h \
    Exp.h \
    Gardien.h

FORMS    += mainwindow.ui
