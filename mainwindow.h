#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void initTable();
    void addTableData(const QString &strNim, const QString& strNama, const QString& strEmail);
    bool openDatabase();
    void closeDatabase();
    bool loadPhoneBook();
    bool insertDataToDatabase(const QString &strNim, const QString& strNama, const QString& strEmail);
    bool deleteDataDatabase(const QString& strNim);

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_action_About_triggered();
    void on_actionExit_triggered();
    void on_actionCalculator_triggered();
    void on_actionSort_triggered();
    void on_actionFind_triggered();

    void on_actionAdd_Data_triggered();
    void on_actionDelete_triggered();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_tableWidget_cellClicked(int row, int column);

    void on_actionReload_data_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
};
#endif // MAINWINDOW_H
