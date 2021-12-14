#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBoxOperation->addItem("Add", QChar('+'));
    ui->comboBoxOperation->addItem("Substract", QChar('-'));
    ui->comboBoxOperation->addItem("Divide", QChar('/'));
    ui->comboBoxOperation->addItem("Multiply", QChar('*'));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBoxOperation_currentIndexChanged(const QString &arg1)
{
    char ch = ui->comboBoxOperation->currentData().toChar().toLatin1();
//    float nResult=0;
    switch (ch) {
        case '+':
        m_nResult = ui->spinBoxNumber1->value()+ui->spinBoxNumber2->value();
        break;

        case '-':
        m_nResult = ui->spinBoxNumber1->value()-ui->spinBoxNumber2->value();
        break;

        case '/':
        m_nResult = float(ui->spinBoxNumber1->value())/ui->spinBoxNumber2->value();
        break;

        case '*':
        m_nResult = ui->spinBoxNumber1->value()*ui->spinBoxNumber2->value();
        break;
    }
    ui->labelResult->setNum(m_nResult);
//    qDebug("%s", qPrintable(ui->labelResult->text());

//    qDebug() << ui->labelResult->text();
}

