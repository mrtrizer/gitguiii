#ifndef GITCMDBRANCH_H
#define GITCMDBRANCH_H

#include "gitcmd.h"

class GitCmdBranch : public GitCmd
{
public:
    GitCmdBranch();
    ~GitCmdBranch();
    inline QStringList getBranchList(){return branchList;}
    inline int getCurBranch(){return curBranch;}
protected:
    QStringList getArgs();
    void procOutStr(QString str);
    int curBranch;
    QStringList branchList;
};

#endif // GITCMDBRANCH_H
