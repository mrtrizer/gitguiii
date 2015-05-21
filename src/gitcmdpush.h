#ifndef GITCMDPUSH_H
#define GITCMDPUSH_H

#include "gitcmd.h"
#include "pullparams.h"

#include <QString>

class GitCmdPush : public GitCmd
{
public:
    GitCmdPush(QString repository, QString branch);
    ~GitCmdPush();
protected:
    QStringList getArgs();
private:
    QString repository;
    QString branch;
};

#endif // GITCMDPUSH_H
