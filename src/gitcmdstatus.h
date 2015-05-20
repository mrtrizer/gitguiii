#ifndef GITCMDSTATUS_H
#define GITCMDSTATUS_H

#include "gitcmd.h"

class GitCmdStatus : public GitCmd
{
public:
    GitCmdStatus();
    ~GitCmdStatus();
    QStringList & getChanged(){return changed;}
    QStringList & getIndex(){return index;}
protected:
    QStringList getArgs();
    void procOutStr(QString str);
    QStringList changed;
    QStringList index;
private:
    QString cutString(QString str);
};

#endif // GITCMDSTATUS_H
