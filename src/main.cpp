#include "mainwindow.h"
#include "gitliveproc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GitLiveProc gitProc;
    gitProc.start();

    MainWindow w;
    w.show();

    QObject::connect(&gitProc,SIGNAL(indexUpdated(QStringList,QStringList)),&w,SLOT(indexUpdated(QStringList,QStringList)));
    QObject::connect(&w,SIGNAL(addToIndex(QStringList)),&gitProc,SLOT(addToIndex(QStringList)));
    QObject::connect(&w,SIGNAL(resetFromIndex(QStringList)),&gitProc,SLOT(resetFromIndex(QStringList)));
    QObject::connect(&w,SIGNAL(updateIndex()),&gitProc,SLOT(updateIndex()));
    QObject::connect(&w,SIGNAL(commitIndex(QString)),&gitProc,SLOT(commitIndex(QString)));
    QObject::connect(&w,SIGNAL(hardReset()),&gitProc,SLOT(hardReset()));
    QObject::connect(&w,SIGNAL(pull(QString, QString)),&gitProc,SLOT(pull(QString, QString)));
    QObject::connect(&w,SIGNAL(push(QString, QString)),&gitProc,SLOT(push(QString, QString)));
    QObject::connect(&w,SIGNAL(setRepoDir(QString)),&gitProc,SLOT(setRepoDir(QString)));

    return a.exec();
}
