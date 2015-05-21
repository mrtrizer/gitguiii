#include "gitcmdpush.h"

GitCmdPush::GitCmdPush(QString repository, QString branch):repository(repository),branch(branch)
{

}

GitCmdPush::~GitCmdPush()
{

}

QStringList GitCmdPush::getArgs()
{
    QStringList args;
    args << "push";
    if (repository.length() > 0)
    {
        args << repository;
        if (branch.length() > 0)
            args << branch;
    }
    return args;
}
