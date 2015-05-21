#ifndef PULLDIALOG_H
#define PULLDIALOG_H

#include <QDialog>
#include "pullparams.h"

namespace Ui {
class PullDialog;
}

class PullDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PullDialog(PullParams & params, QWidget *parent = 0);
    ~PullDialog();

private:
    Ui::PullDialog *ui;
    PullParams & params;
private slots:
    void onOkButton();
    void onLocalDirButton();
};

#endif // PULLDIALOG_H
