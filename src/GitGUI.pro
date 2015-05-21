#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T10:23:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gitliveproc.cpp \
    gitcmd.cpp \
    gitcmdadd.cpp \
    gitcmdreset.cpp \
    gitcmdcommit.cpp \
    gitcmdstatus.cpp \
    gitcmdpull.cpp \
    gitcmdpush.cpp \
    gitcmdinit.cpp \
    pulldialog.cpp \
    commitdialog.cpp \
    gitcmdlog.cpp \
    gitcmdbranch.cpp

HEADERS  += mainwindow.h \
    gitliveproc.h \
    gitcmd.h \
    gitcmdadd.h \
    gitcmdreset.h \
    gitcmdcommit.h \
    gitcmdstatus.h \
    gitcmdpull.h \
    gitcmdpush.h \
    gitcmdinit.h \
    pulldialog.h \
    pullparams.h \
    commitdialog.h \
    gitcmdlog.h \
    gitcmdbranch.h

FORMS    += mainwindow.ui \
    pulldialog.ui \
    commitdialog.ui
