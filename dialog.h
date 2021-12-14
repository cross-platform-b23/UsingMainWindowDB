#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    float getResult() { return m_nResult; }

private slots:
    void on_comboBoxOperation_currentIndexChanged(const QString &arg1);

private:
    float m_nResult;
    Ui::Dialog *ui;
};
#endif // DIALOG_H
