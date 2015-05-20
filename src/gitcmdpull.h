#ifndef GITCMDPULL_H
#define GITCMDPULL_H

#include "gitcmd.h"
#include <QString>

class GitCmdPull : public GitCmd
{
public:
    GitCmdPull(const QString & source, const QString & branch);
    ~GitCmdPull();
protected:
    QStringList getArgs();
private:
    QString source;
    QString branch;
};

#endif // GITCMDPULL_H
