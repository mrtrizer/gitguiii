#ifndef GITCMDPUSH_H
#define GITCMDPUSH_H

#include "gitcmd.h"
#include <QString>

class GitCmdPush : public GitCmd
{
public:
    GitCmdPush(const QString & target, const QString & branch);
    ~GitCmdPush();
protected:
    QStringList getArgs();
private:
    QString target;
    QString branch;
};

#endif // GITCMDPUSH_H
