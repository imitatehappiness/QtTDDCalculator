#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QSizePolicy>
#include <QDebug>
#include <QKeyEvent>
#include <standartcaclulatorfactory.h>
#include <calculatorfactory.h>
#include <structs.h>
#include <stack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    void setInterface();
    void initConnect();

    CalculatorFactory* calculator;
    QVector<QPair<int, QPushButton*>> buttons;
    std::stack<double> currentCalculation;
    QLineEdit* lineEditScreen;
    int IdOperation;
    QString value;
private slots:
    void calculation();
};
#endif // MAINWINDOW_H
