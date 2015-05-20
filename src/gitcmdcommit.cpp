#include "gitcmdcommit.h"

GitCmdCommit::GitCmdCommit(const QString & msg):msg(msg)
{

}

GitCmdCommit::~GitCmdCommit()
{

}


QStringList GitCmdCommit::getArgs()
{
    QStringList args;
    args << "commit";
    args << "-m";
    args << msg;
    return args;
}
