#include "gitcmdpull.h"

GitCmdPull::GitCmdPull(const QString & source, const QString & branch):source(source), branch(branch)
{

}

GitCmdPull::~GitCmdPull()
{

}

QStringList GitCmdPull::getArgs()
{
    QStringList args;
    args << "pull";
    if (source.length() > 0)
    {
        args << source;
        if (branch.length() > 0)
            args << branch;
    }
    return args;
}
