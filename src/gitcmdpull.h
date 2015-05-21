#ifndef GITCMDPULL_H
#define GITCMDPULL_H

#include "gitcmd.h"
#include "pullparams.h"

#include <QString>

class GitCmdPull : public GitCmd
{
public:
    GitCmdPull(QString repository, QString branch);
    ~GitCmdPull();
protected:
    QStringList getArgs();
private:
    QString repository;
    QString branch;
};

#endif // GITCMDPULL_H
