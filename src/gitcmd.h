#ifndef GITCMD_H
#define GITCMD_H

#include <QStringList>

class GitCmd
{
public:
    GitCmd();
    ~GitCmd();
    virtual QString execCmd();
    QString getCmdStr();
protected:
    virtual QStringList getArgs() = 0;
    virtual void procOutStr(QString str);
    virtual void procErrorStr(QString str);
};

#endif // GITCMD_H
