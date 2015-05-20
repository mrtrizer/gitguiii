#ifndef GITCMDADD_H
#define GITCMDADD_H

#include "gitcmd.h"
#include <QStringList>

class GitCmdAdd:public GitCmd
{
public:
    GitCmdAdd(const QStringList &fileList, bool update = false);
    ~GitCmdAdd();
protected:
    QStringList getArgs();
private:
    QStringList fileList;
    bool update;
};

#endif // GITCMDADD_H
