#include "gitliveproc.h"
#include "gitcmdstatus.h"
#include "gitcmdadd.h"
#include "gitcmdreset.h"
#include "gitcmdcommit.h"
#include "gitcmdpush.h"
#include "gitcmdpull.h"

#include <QDir>

GitLiveProc::GitLiveProc(QObject *parent) : QThread(parent)
{
    QObject::connect(&timer,SIGNAL(timeout()),SLOT(onTimer()));
    timer.start(500);
}

GitLiveProc::~GitLiveProc()
{

}

void GitLiveProc::run()
{
    exec();
}

void GitLiveProc::onTimer()
{
    GitCmdStatus cmd;
    cmd.execCmd();
    emit indexUpdated(cmd.getChanged(),cmd.getIndex());
}

void GitLiveProc::setRepoDir(QString repoDir)
{
    this->repoDir = repoDir;
    QDir::setCurrent(repoDir);
}

void GitLiveProc::addToIndex(QStringList strList)
{
    GitCmdAdd cmd(strList);
    cmd.execCmd();
}

void GitLiveProc::updateIndex()
{
    GitCmdAdd cmd(QStringList(), true);
    cmd.execCmd();
}

void GitLiveProc::resetFromIndex(QStringList strList)
{
    GitCmdReset cmd(strList);
    cmd.execCmd();
}

void GitLiveProc::hardReset()
{
    GitCmdReset cmd(QStringList(),true);
    cmd.execCmd();
}

void GitLiveProc::commitIndex(QString msg)
{
    GitCmdCommit cmd(msg);
    cmd.execCmd();
}

void GitLiveProc::push(QString target, QString branch)
{
    GitCmdPush cmd(target,branch);
    cmd.execCmd();
}

void GitLiveProc::pull(QString source, QString branch)
{
    GitCmdPull cmd(source, branch);
    cmd.execCmd();
}
