#include "gitcmdlog.h"

GitCmdLog::GitCmdLog()
{

}

GitCmdLog::~GitCmdLog()
{

}

QStringList GitCmdLog::getArgs()
{
    QStringList args;
    args << "log" << "--pretty=oneline";
    return args;
}

void GitCmdLog::procOutStr(QString str)
{
    QStringList list = str.split("\n");
    foreach (QString str, list)
    {
        hashList << str.left(32);
    }
}
