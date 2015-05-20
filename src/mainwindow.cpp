#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton,SIGNAL(clicked()),SLOT(onAddButton()));
    QObject::connect(ui->resetButton,SIGNAL(clicked()),SLOT(onResetButton()));
    QObject::connect(ui->updateButton,SIGNAL(clicked()),SLOT(onUpdateButton()));
    QObject::connect(ui->commitButton,SIGNAL(clicked()),SLOT(onCommitButton()));
    QObject::connect(ui->hardResetButton,SIGNAL(clicked()),SLOT(onHardResetButton()));
    QObject::connect(ui->actionExit,SIGNAL(triggered()),SLOT(onActionExit()));
    QObject::connect(ui->actionInitRepo,SIGNAL(triggered()),SLOT(onActionInitRepo()));
    QObject::connect(ui->actionLocalRepo,SIGNAL(triggered()),SLOT(onActionLocalRepo()));
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
    emit addToIndex(getStrList(ui->changedList));
}

void MainWindow::onResetButton()
{
    emit resetFromIndex(getStrList(ui->indexList));
}

void MainWindow::onUpdateButton()
{
    emit updateIndex();
}

void MainWindow::onCommitButton()
{
    //TODO: Open message dialog
}

void MainWindow::onHardResetButton()
{
    emit hardReset();
}

void MainWindow::indexUpdated(QStringList changed, QStringList index)
{
    if (ui->indexList->count() != index.count())
    {
        ui->indexList->clear();
        ui->indexList->addItems(index);
    }
    if (ui->changedList->count() != changed.count())
    {
        ui->changedList->clear();
        ui->changedList->addItems(changed);
    }
}

void MainWindow::onActionInitRepo()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open local repository"),
                                                 "~",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    emit initRepo();
}

void MainWindow::onActionLocalRepo()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open local repository"),
                                                 "~",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    emit setRepoDir(dir);
}

void MainWindow::onActionExit()
{
    close();
}
