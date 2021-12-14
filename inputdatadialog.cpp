#include "inputdatadialog.h"
#include "ui_inputdatadialog.h"

InputDataDialog::InputDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDataDialog)
{
    ui->setupUi(this);
}

InputDataDialog::~InputDataDialog()
{
    delete ui;
}
