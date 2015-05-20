#include "gitcmdpush.h"

GitCmdPush::GitCmdPush(const QString & target, const QString & branch):target(target), branch(branch)
{

}

GitCmdPush::~GitCmdPush()
{

}

QStringList GitCmdPush::getArgs()
{
    QStringList args;
    args << "push";
    if (target.length() > 0)
    {
        args << target;
        if (branch.length() > 0)
            args << branch;
    }
    return args;
}
