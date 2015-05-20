#ifndef GITCMDINIT_H
#define GITCMDINIT_H

#include "gitcmd.h"

class GitCmdInit : public GitCmd
{
public:
    GitCmdInit();
    ~GitCmdInit();
protected:
    QStringList getArgs();
};

#endif // GITCMDINIT_H
