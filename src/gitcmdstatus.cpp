#include "gitcmdstatus.h"

GitCmdStatus::GitCmdStatus()
{

}

GitCmdStatus::~GitCmdStatus()
{

}

QStringList GitCmdStatus::getArgs()
{
    QStringList args;
    args << "status";
    args << "-s";
    return args;
}

void GitCmdStatus::procOutStr(QString str)
{
    QStringList list = str.split("\n");
    foreach (QString str, list)
    {
        QString substr = str.left(2);
        if (substr == "??")
            changed << cutString(str);
        if (substr == " M")
            changed << cutString(str);
        if (substr == " D")
            changed << cutString(str);
        if (substr == "A ")
            index << cutString(str);
        if (substr == "D ")
            index << cutString(str);
        if (substr == "M ")
            index << cutString(str);
    }
}

QString GitCmdStatus::cutString(QString str)
{
    return str.right(str.length() - 3);
}
