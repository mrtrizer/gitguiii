#include "gitcmd.h"
#include <QProcess>
#include <QDebug>

GitCmd::GitCmd()
{

}

GitCmd::~GitCmd()
{

}

QString GitCmd::getCmdStr()
{
    QString argsStr;
    foreach (QString str, getArgs())
        argsStr += str + ' ';
    return "git " + argsStr;
}

QString GitCmd::execCmd()
{
    QStringList args;
    args << getArgs();
    QProcess myProcess;
    myProcess.start("git", args);
    QString outStr;
    QString errorStr;
    if (myProcess.waitForFinished())
    {
        outStr = QString(myProcess.readAllStandardOutput());
        errorStr = QString(myProcess.readAllStandardError());
        procOutStr(outStr);
        procErrorStr(errorStr);
    }
    else
        myProcess.terminate();
    return outStr + errorStr;
}

void GitCmd::procOutStr(QString str)
{
    qDebug() << str;
}

void GitCmd::procErrorStr(QString str)
{
    qDebug() << str;
}
