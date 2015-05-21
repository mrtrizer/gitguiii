#ifndef GITCMDRESET_H
#define GITCMDRESET_H

#include "gitcmd.h"
#include <QStringList>

class GitCmdReset : public GitCmd
{
public:
    GitCmdReset(const QStringList & fileList = QStringList(), bool hard = false);
    ~GitCmdReset();
protected:
    QStringList getArgs();
private:
    QStringList fileList;
    bool hard;
};

#endif // GITCMDRESET_H
