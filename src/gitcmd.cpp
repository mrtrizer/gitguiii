#include "gitcmd.h"
#include <QProcess>
#include <QDebug>

GitCmd::GitCmd()
{

}

GitCmd::~GitCmd()
{

}

void GitCmd::execCmd()
{
    QStringList args;
    args << getArgs();
    QProcess myProcess;
    myProcess.start("git", args);
    if (myProcess.waitForFinished())
    {
        procOutStr(QString(myProcess.readAllStandardOutput()));
    }
    else
        myProcess.terminate();
}

void GitCmd::procOutStr(QString str)
{
    qDebug() << str;
}
