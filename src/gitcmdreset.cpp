#include "gitcmdreset.h"

GitCmdReset::GitCmdReset(const QStringList &fileList, bool hard):fileList(fileList), hard(hard)
{

}

GitCmdReset::~GitCmdReset()
{

}

QStringList GitCmdReset::getArgs()
{
    QStringList args;
    args << "reset";
    if (hard)
        args << "--hard";
    return args;
}
