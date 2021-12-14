#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sortdialog.h"
#include "inputdatadialog.h"
#include "ui_inputdatadialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTable();
//    addTableData("Budi", "Budi@gmail.com");
//    addTableData("Karni", "karni@gmail.com");
//    addTableData("Cinta", "cinta@gmail.com");
//    addTableData("Amir", "amir@gmail.com");
    if (openDatabase())
    {
        qDebug("Open database success");
        loadPhoneBook();
    }
    else
    {
        qDebug("Open database failed");
    }
}

void MainWindow::initTable()
{
    QStringList strHeader;
    strHeader << "  Nim  " << "                      Nama                      "
              << "Email";
    ui->tableWidget->setColumnCount(strHeader.size());
    ui->tableWidget->setHorizontalHeaderLabels(strHeader);
//    ui->tableWidget->setRowCount(5);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QTableView::SelectRows);
    ui->tableWidget->setAlternatingRowColors(true);
//    ui->tableWidget->setSelectionMode(QTableView::SingleSelection);
}

void MainWindow::addTableData(const QString& strNim, const QString &strNama, const QString &strEmail)
{
    int nCurrentRowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(nCurrentRowCount+1); // add new row
    QTableWidgetItem* pItemNim = new QTableWidgetItem(strNim);
    QTableWidgetItem* pItemNama = new QTableWidgetItem(strNama);
    QTableWidgetItem* pItemEmail = new QTableWidgetItem(strEmail);

    pItemNama->setTextAlignment(Qt::AlignCenter);
//    QFont font = pItemNama->font();
//    font.setBold(true);
//    font.setPointSize(18);
//    pItemNama->setFont(font);
    ui->tableWidget->setItem(nCurrentRowCount, 0, pItemNim);
    ui->tableWidget->setItem(nCurrentRowCount, 1, pItemNama);
    ui->tableWidget->setItem(nCurrentRowCount, 2, pItemEmail);
}

bool MainWindow::openDatabase()
{
    m_db = QSqlDatabase::addDatabase("QODBC");
    m_db.setHostName("127.0.0.1");
    m_db.setDatabaseName("dbdaftarMhs");
    m_db.setUserName("root");
    m_db.setPassword("steff123");
    return m_db.open();
}

void MainWindow::closeDatabase()
{
    m_db.close();
}

bool MainWindow::loadPhoneBook()
{
    int i=0;
    QSqlQuery qry("SELECT * FROM tbdaftarnama", m_db);
    while (qry.next())
    {
        QString nim = qry.value("nim").toString();
        QString nama = qry.value("nama").toString();
        QString email = qry.value("email").toString();
        addTableData(nim, nama, email);
    }
    return i;
}

bool MainWindow::insertDataToDatabase(const QString &strNim, const QString &strNama, const QString &strEmail)
{
    QSqlQuery qry(m_db);

    qry.prepare("INSERT INTO tbdaftarnama(nim, nama, email) "
                "VALUES (:nim, :nama, :email) ");
    qry.bindValue(":nim", strNim);
    qry.bindValue(":nama", strNama);
    qry.bindValue(":email", strEmail);
    bool fResult = qry.exec();
    if (!fResult)
        qDebug() << "Error insertDataToDatabase: " <<
                    qry.lastError().text();
    return fResult;
}

MainWindow::~MainWindow()
{
    closeDatabase();
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    qDebug("File New");
}


void MainWindow::on_actionOpen_triggered()
{
    qDebug("File Open");
}


void MainWindow::on_action_About_triggered()
{
    qDebug("About");
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionCalculator_triggered()
{
    qDebug("Calculator");
    Dialog dlg;
    dlg.exec();
    qDebug("Result: %.2f", dlg.getResult());
}


void MainWindow::on_actionSort_triggered()
{
    qDebug("on_actionSort_triggered");
    statusBar()->showMessage("Ini utk membuka menu dialog Sort", 5*1000);
    SortDialog dlg;
    dlg.exec();
}

void MainWindow::on_actionFind_triggered()
{

}

void MainWindow::on_actionAdd_Data_triggered()
{
    InputDataDialog d;

    if (d.exec()==QDialog::Accepted)
    {
        addTableData(d.ui->lineEditNim->text(),
                     d.ui->lineEditNama->text(),
                     d.ui->lineEditEmail->text());

        insertDataToDatabase(d.ui->lineEditNim->text(),
                     d.ui->lineEditNama->text(),
                     d.ui->lineEditEmail->text());
    }
}


void MainWindow::on_actionDelete_triggered()
{
    int nRow = ui->tableWidget->currentRow();
    int nColumn = ui->tableWidget->currentColumn();
    qDebug("delete row: %d column: %d", nRow, nColumn);
    ui->tableWidget->removeRow(nRow);
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    qDebug("DoubleClick-> Row: %d, column: %d", row, column);
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug("Clicked-> Row: %d, column: %d", row, column);
}


void MainWindow::on_actionReload_data_triggered()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    loadPhoneBook();
}

