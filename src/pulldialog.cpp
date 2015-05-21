#include "pulldialog.h"
#include "ui_pulldialog.h"
#include "pullparams.h"
#include <QFileDialog>

PullDialog::PullDialog(PullParams &params, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PullDialog),
    params(params)
{
    ui->setupUi(this);
    QObject::connect(ui->okButton,SIGNAL(clicked()),SLOT(onOkButton()));
    QObject::connect(ui->cancelButton,SIGNAL(clicked()),SLOT(reject()));
    QObject::connect(ui->localDirButton,SIGNAL(clicked()),SLOT(onLocalDirButton()));
    ui->branchEdit->setText(params.getBranch());
    ui->loginEdit->setText(params.getLogin());
    ui->passwordEdit->setText(params.getPassword());
    ui->repositoryEdit->setText(params.getRepository());
}

PullDialog::~PullDialog()
{
    delete ui;
}

void PullDialog::onOkButton()
{
    params.setBranch(ui->branchEdit->text());
    params.setLogin(ui->loginEdit->text());
    params.setPassword(ui->passwordEdit->text());
    params.setRepository(ui->repositoryEdit->text());
    accept();
}

void PullDialog::onLocalDirButton()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open local repository"),"~",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    params.setRepository(dir);
    ui->repositoryEdit->setText(params.getRepository());
}
