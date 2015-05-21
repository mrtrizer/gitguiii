#include "commitdialog.h"
#include "ui_commitdialog.h"

CommitDialog::CommitDialog(QString & message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommitDialog),
    message(message)
{
    ui->setupUi(this);
    QObject::connect(ui->okButton,SIGNAL(clicked()),SLOT(onOkButton()));
    QObject::connect(ui->cancelButton,SIGNAL(clicked()),SLOT(reject()));
}

CommitDialog::~CommitDialog()
{
    delete ui;
}

void CommitDialog::onOkButton()
{
    message = ui->commitMessage->toPlainText();
    accept();
}
