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

    QObject::connect(&gitProc,SIGNAL(indexUpdated(QStringList,QStringList)),&w,SLOT(indexUpdated(QStringList,QStringList)),Qt::QueuedConnection);
    QObject::connect(&gitProc,SIGNAL(hashUpdated(QStringList)),&w,SLOT(hashUpdated(QStringList)),Qt::QueuedConnection);
    QObject::connect(&gitProc,SIGNAL(branchUpdated(QStringList,int)),&w,SLOT(branchUpdated(QStringList,int)),Qt::QueuedConnection);
    QObject::connect(&gitProc,SIGNAL(logText(QString)),&w,SLOT(logText(QString)),Qt::QueuedConnection);
    QObject::connect(&gitProc,SIGNAL(dirChanged(QString)),&w,SLOT(dirChanged(QString)),Qt::QueuedConnection);
    QObject::connect(&gitProc,SIGNAL(commitChanged(QString)),&w,SLOT(commitChanged(QString)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(addToIndex(QStringList)),&gitProc,SLOT(addToIndex(QStringList)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(resetFromIndex(QStringList)),&gitProc,SLOT(resetFromIndex(QStringList)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(resetAllFromIndex()),&gitProc,SLOT(resetAllFromIndex()),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(updateIndex()),&gitProc,SLOT(updateIndex()),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(commitIndex(QString)),&gitProc,SLOT(commitIndex(QString)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(hardReset()),&gitProc,SLOT(hardReset()),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(pull(QString,QString)),&gitProc,SLOT(pull(QString,QString)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(push(QString,QString)),&gitProc,SLOT(push(QString,QString)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(setRepoDir(QString)),&gitProc,SLOT(setRepoDir(QString)),Qt::QueuedConnection);
    QObject::connect(&w,SIGNAL(initRepo()),&gitProc,SLOT(initRepo()),Qt::QueuedConnection);

    return a.exec();
}
