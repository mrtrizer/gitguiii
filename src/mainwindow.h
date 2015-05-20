#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>

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

signals:
    void setRepoDir(QString dir);
    void addToIndex(QStringList strList);
    void updateIndex();
    void resetFromIndex(QStringList strList);
    void commitIndex(QString msg);
    void hardReset();
    void pull(QString source, QString branch);
    void push(QString target, QString branch);
    void initRepo();

public slots:
    void indexUpdated(QStringList changed, QStringList index);

private slots:
    void onAddButton();
    void onResetButton();
    void onUpdateButton();
    void onCommitButton();
    void onHardResetButton();
    void onActionLocalRepo();
    void onActionInitRepo();
    void onActionExit();

};

#endif // MAINWINDOW_H
