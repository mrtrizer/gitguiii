#ifndef GITLIVEPROC_H
#define GITLIVEPROC_H

#include <QThread>
#include <QTimer>
#include <QString>
#include <QStringList>

class GitLiveProc : public QThread
{
    Q_OBJECT
public:
    explicit GitLiveProc(QObject *parent = 0);
    ~GitLiveProc();
    void run();

private:
    QTimer timer;
    QString repoDir;

signals:
    void indexUpdated(QStringList changed, QStringList index);

public slots:
    void setRepoDir(QString repoDir);
    void addToIndex(QStringList strList);
    void updateIndex();
    void resetFromIndex(QStringList strList);
    void hardReset();
    void commitIndex(QString msg);
    void pull(QString source, QString branch);
    void push(QString target, QString branch);

private slots:
    void onTimer();
};

#endif // GITLIVEPROC_H
