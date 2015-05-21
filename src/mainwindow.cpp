#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commitdialog.h"
#include "pulldialog.h"
#include "pullparams.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton,SIGNAL(clicked()),SLOT(onAddButton()));
    QObject::connect(ui->resetButton,SIGNAL(clicked()),SLOT(onResetButton()));
    QObject::connect(ui->resetAllButton,SIGNAL(clicked()),SLOT(onResetAllButton()));
    QObject::connect(ui->updateButton,SIGNAL(clicked()),SLOT(onUpdateButton()));
    QObject::connect(ui->commitButton,SIGNAL(clicked()),SLOT(onCommitButton()));
    QObject::connect(ui->hardResetButton,SIGNAL(clicked()),SLOT(onHardResetButton()));
    QObject::connect(ui->actionExit,SIGNAL(triggered()),SLOT(onActionExit()));
    QObject::connect(ui->actionInitRepo,SIGNAL(triggered()),SLOT(onActionInitRepo()));
    QObject::connect(ui->actionLocalRepo,SIGNAL(triggered()),SLOT(onActionLocalRepo()));
    QObject::connect(ui->actionCloneRepo,SIGNAL(triggered()),SLOT(onActionCloneRepo()));
    QObject::connect(ui->pullButton,SIGNAL(clicked()),SLOT(onPullButton()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),SLOT(onPushButton()));
    params.setBranch("master");
    emit dirChanged("?");
    emit commitChanged("?");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::getStrList(QListWidget *changedList)
{
    QStringList list;
    foreach (QListWidgetItem * item, changedList->selectedItems())
        list << item->text();
    return list;
}

void MainWindow::onAddButton()
{
    QStringList list = getStrList(ui->changedList);
    if (list.length() > 0)
        emit addToIndex(list);
}

void MainWindow::onResetButton()
{
    QStringList list = getStrList(ui->indexList);
    if (list.length() > 0)
        emit resetFromIndex(list);
}

void MainWindow::onResetAllButton()
{
    emit resetAllFromIndex();
}

void MainWindow::onUpdateButton()
{
    emit updateIndex();
}

void MainWindow::onCommitButton()
{
    QString message;
    CommitDialog dialog(message);
    if (dialog.exec() == QDialog::Accepted)
        emit commitIndex(message);
}

void MainWindow::onPushButton()
{
    PullDialog dialog(params);
    if (dialog.exec() == QDialog::Accepted)
        emit push(params.getRepository(),params.getBranch());
}

void MainWindow::onPullButton()
{
    PullDialog dialog(params);
    if (dialog.exec() == QDialog::Accepted)
        emit pull(params.getRepository(),params.getBranch());
}

void MainWindow::onHardResetButton()
{
    int n = QMessageBox::warning(0,
                     "Warning",
                     "Do you realy want to reset all changes?",
                     "Yes","No",
                     QString(),0,1);
    if(n == 0)
    {
        emit hardReset();
    }

}

void MainWindow::indexUpdated(QStringList changed, QStringList index)
{
    if (curIndex != index)
    {
        curIndex = index;
        ui->indexList->clear();
        ui->indexList->addItems(index);
    }
    if (curChanged != changed)
    {
        curChanged = changed;
        ui->changedList->clear();
        ui->changedList->addItems(changed);
    }
}

void MainWindow::onActionInitRepo()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open local repository"),"~",
                                                    QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    emit setRepoDir(dir);
    emit initRepo();
}

void MainWindow::onActionCloneRepo()
{
    PullDialog dialog(params);
    if (dialog.exec() == QDialog::Accepted)
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Select path to clone"),"~",
                                                 QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
        emit setRepoDir(dir);
        emit cloneRepo(params.getRepository(), params.getBranch());
    }
}

void MainWindow::onActionLocalRepo()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open local repository"),"~",
                                                    QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    emit setRepoDir(dir);
}

void MainWindow::onActionExit()
{
    close();
}

void MainWindow::logText(QString str)
{
    ui->logEdit->insertPlainText(str);
}

void MainWindow::dirChanged(QString dir)
{
    ui->dirLabel->setText(QString("pwd: %1").arg(dir));
}

void MainWindow::commitChanged(QString commit)
{
    ui->commitLabel->setText(QString("hash: %1").arg(commit));
}

void MainWindow::hashUpdated(QStringList hashList)
{
    ui->commitList->clear();
    ui->commitList->addItems(hashList);
}

void MainWindow::branchUpdated(QStringList branchList, int index)
{
    ui->branchBox->clear();
    ui->branchBox->addItems(branchList);
    ui->branchBox->setCurrentIndex(index);
}
