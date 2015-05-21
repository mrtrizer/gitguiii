#ifndef GITCMDLOG_H
#define GITCMDLOG_H

#include "gitcmd.h"

class GitCmdLog : public GitCmd
{
public:
    GitCmdLog();
    ~GitCmdLog();
    inline QStringList getHashList(){return hashList;}
protected:
    QStringList getArgs();
    void procOutStr(QString str);
private:
    QStringList hashList;
};

#endif // GITCMDLOG_H
