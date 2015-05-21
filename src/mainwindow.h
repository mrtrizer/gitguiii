#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <pullparams.h>

class QListWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList getStrList(QListWidget * changedList);
    QStringList curIndex;
    QStringList curChanged;
    PullParams params;

signals:
    void setRepoDir(QString dir);
    void addToIndex(QStringList strList);
    void updateIndex();
    void resetFromIndex(QStringList strList);
    void resetAllFromIndex();
    void commitIndex(QString msg);
    void hardReset();
    void pull(QString repository, QString branch);
    void push(QString repository, QString branch);
    void initRepo();
    void cloneRepo(QString repository, QString branch);

public slots:
    void indexUpdated(QStringList changed, QStringList index);
    void logText(QString str);
    void commitChanged(QString commit);
    void dirChanged(QString dir);
    void hashUpdated(QStringList hashList);
    void branchUpdated(QStringList branchList, int index);

private slots:
    void onAddButton();
    void onResetButton();
    void onResetAllButton();
    void onUpdateButton();
    void onCommitButton();
    void onHardResetButton();
    void onActionLocalRepo();
    void onActionInitRepo();
    void onActionExit();
    void onActionCloneRepo();
    void onPushButton();
    void onPullButton();

};

#endif // MAINWINDOW_H
