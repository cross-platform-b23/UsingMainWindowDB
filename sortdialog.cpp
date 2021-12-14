#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->groupBoxSecondary->hide();
    ui->groupBoxTertiary->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

SortDialog::~SortDialog()
{
    delete ui;
}
