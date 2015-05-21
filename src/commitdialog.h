#ifndef COMMITDIALOG_H
#define COMMITDIALOG_H

#include <QDialog>

namespace Ui {
class CommitDialog;
}

class CommitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommitDialog(QString &message, QWidget *parent = 0);
    ~CommitDialog();

private:
    Ui::CommitDialog *ui;
    QString & message;

private slots:
    void onOkButton();
};

#endif // COMMITDIALOG_H
