#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void plus();
    void minus();
    void multiply();
    void divide();
    void dot();
    void degree();

    void result();
    void AC();
    void deleteSign();

private:
    Ui::MainWindow *ui;
    QLineEdit *answerLine = nullptr;
    QLineEdit *inputLine = nullptr;
    QString currentExpression;
    int operationDigitPos;
    QVector<QString> operations;

    void setOperation(const QString &text);
    void zeroIsPossible(const QString &text);
    void dotIsPossible(const QString &text);
    void addSymbol(QString text);
    void operationDigitIsPossible(QString &text);
    bool validation(const QString &currentExpression);
    double calculate(double num1, double num2, QChar doOperation);


};

#endif // MAINWINDOW_H
