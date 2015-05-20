#include "gitcmdinit.h"

GitCmdInit::GitCmdInit()
{

}

GitCmdInit::~GitCmdInit()
{

}

QStringList GitCmdInit::getArgs()
{
    QStringList args;
    args << "init";
    return args;
}
