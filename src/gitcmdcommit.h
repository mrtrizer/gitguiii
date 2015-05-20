#ifndef GITCMDCOMMIT_H
#define GITCMDCOMMIT_H

#include "gitcmd.h"
#include <QString>

class GitCmdCommit : public GitCmd
{
public:
    GitCmdCommit(const QString &msg);
    ~GitCmdCommit();
protected:
    QStringList getArgs();
private:
    QString msg;
};

#endif // GITCMDCOMMIT_H
