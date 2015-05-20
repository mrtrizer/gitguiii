#include "gitcmdadd.h"

GitCmdAdd::GitCmdAdd(const QStringList &fileList, bool update):fileList(fileList),update(update)
{

}

GitCmdAdd::~GitCmdAdd()
{

}

QStringList GitCmdAdd::getArgs()
{
    QStringList args;
    args << "add";
    args << fileList;
    if (update)
        args << "--update";
    return args;
}
