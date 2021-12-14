#ifndef INPUTDATADIALOG_H
#define INPUTDATADIALOG_H

#include <QDialog>

namespace Ui {
class InputDataDialog;
}

class InputDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDataDialog(QWidget *parent = nullptr);
    ~InputDataDialog();

//private:
    Ui::InputDataDialog *ui;
};

#endif // INPUTDATADIALOG_H
