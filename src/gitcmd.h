#ifndef GITCMD_H
#define GITCMD_H

#include <QStringList>

class GitCmd
{
public:
    GitCmd();
    ~GitCmd();
    virtual void execCmd();
protected:
    virtual QStringList getArgs() = 0;
    virtual void procOutStr(QString str);
};

#endif // GITCMD_H
