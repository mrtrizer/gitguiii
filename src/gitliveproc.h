#ifndef GITLIVEPROC_H
#define GITLIVEPROC_H

#include <QThread>
#include <QTimer>
#include <QString>
#include <QStringList>
#include "gitcmd.h"
#include "pullparams.h"

class GitLiveProc : public QThread
{
    Q_OBJECT
public:
    explicit GitLiveProc(QObject *parent = 0);
    ~GitLiveProc();
    void run();

private:
    void procStatus();
    void procLog();
    void procBranch();
    void execGitCmd(GitCmd & gitCmd);

    QTimer timer;
    QString repoDir;
    bool scan;

signals:
    void indexUpdated(QStringList changed, QStringList index);
    void logText(QString str);
    void commitChanged(QString commit);
    void dirChanged(QString dir);
    void hashUpdated(QStringList hashList);
    void branchUpdated(QStringList branchList, int index);

public slots:
    void initRepo();
    void setRepoDir(QString repoDir);
    void addToIndex(QStringList strList);
    void updateIndex();
    void resetFromIndex(QStringList strList);
    void resetAllFromIndex();
    void hardReset();
    void commitIndex(QString msg);
    void pull(QString repository, QString branch);
    void push(QString repository, QString branch);

private slots:
    void onTimer();
};

#endif // GITLIVEPROC_H
