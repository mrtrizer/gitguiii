#include "gitcmdpull.h"

GitCmdPull::GitCmdPull(QString repository, QString branch):repository(repository),branch(branch)
{

}

GitCmdPull::~GitCmdPull()
{

}

QStringList GitCmdPull::getArgs()
{
    QStringList args;
    args << "pull";
    if (repository.length() > 0)
    {
        args << repository;
        if (branch.length() > 0)
            args << branch;
    }
    return args;
}
