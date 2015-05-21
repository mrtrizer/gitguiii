#include "gitcmdbranch.h"

GitCmdBranch::GitCmdBranch()
{

}

GitCmdBranch::~GitCmdBranch()
{

}

QStringList GitCmdBranch::getArgs()
{
    QStringList args;
    args << "branch";
    return args;
}

void GitCmdBranch::procOutStr(QString str)
{
    QStringList list = str.split("\n");

    for (int i = 0; i < list.length(); i++)
    {
        QString str = list[i];
        branchList << str.right(str.length() - 2);
        if (str[0] == '*')
            curBranch = i;
    }
}
