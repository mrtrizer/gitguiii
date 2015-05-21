#include "gitliveproc.h"
#include "gitcmdstatus.h"
#include "gitcmdadd.h"
#include "gitcmdreset.h"
#include "gitcmdcommit.h"
#include "gitcmdpush.h"
#include "gitcmdpull.h"
#include "gitcmdinit.h"
#include "gitcmdlog.h"
#include "gitcmdbranch.h"

#include <QDir>

GitLiveProc::GitLiveProc(QObject *parent) : QThread(parent),scan(false)
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

void GitLiveProc::execGitCmd(GitCmd & gitCmd)
{
    QString result = gitCmd.execCmd();
    emit logText(gitCmd.getCmdStr() + "\n" + result);
}

void GitLiveProc::procStatus()
{
    GitCmdStatus cmd;
    cmd.execCmd();
    emit indexUpdated(cmd.getChanged(),cmd.getIndex());
}

void GitLiveProc::procBranch()
{
    GitCmdBranch cmd;
    cmd.execCmd();
    emit branchUpdated(cmd.getBranchList(), cmd.getCurBranch());
}

void GitLiveProc::procLog()
{
    GitCmdLog cmd;
    cmd.execCmd();
    emit hashUpdated(cmd.getHashList());
    emit commitChanged(cmd.getHashList()[0]);
}

void GitLiveProc::onTimer()
{
    if (!scan)
        return;
    procStatus();
    procBranch();
    procLog();
}

void GitLiveProc::initRepo()
{
    GitCmdInit cmd;
    execGitCmd(cmd);
}

void GitLiveProc::setRepoDir(QString repoDir)
{
    this->repoDir = repoDir;
    QDir::setCurrent(repoDir);
    dirChanged(QDir::current().path());
    scan = true;
}

void GitLiveProc::addToIndex(QStringList strList)
{
    GitCmdAdd cmd(strList);
    execGitCmd(cmd);
    procStatus();
}

void GitLiveProc::updateIndex()
{
    GitCmdAdd cmd(QStringList(), true);
    execGitCmd(cmd);
    procStatus();
}

void GitLiveProc::resetFromIndex(QStringList strList)
{
    GitCmdReset cmd(strList);
    execGitCmd(cmd);
    procStatus();
}

void GitLiveProc::resetAllFromIndex()
{
    GitCmdReset cmd;
    execGitCmd(cmd);
    procStatus();
}

void GitLiveProc::hardReset()
{
    GitCmdReset cmd(QStringList(),true);
    execGitCmd(cmd);
    procStatus();
}

void GitLiveProc::commitIndex(QString msg)
{
    GitCmdCommit cmd(msg);
    execGitCmd(cmd);
}

void GitLiveProc::push(QString repository, QString branch)
{
    GitCmdPush cmd(repository, branch);
    execGitCmd(cmd);
}

void GitLiveProc::pull(QString repository, QString branch)
{
    GitCmdPull cmd(repository, branch);
    execGitCmd(cmd);
}
