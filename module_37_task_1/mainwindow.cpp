#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
#include <QVector>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    answerLine = ui->answerLine;
    inputLine = ui->inputLine;
    currentExpression = "";
    operationDigitPos = 0;
    operations = {"+","-","*","/","^"};


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add0() {addSymbol("0");}
void MainWindow::add1() {addSymbol("1");}
void MainWindow::add2() {addSymbol("2");}
void MainWindow::add3() {addSymbol("3");}
void MainWindow::add4() {addSymbol("4");}
void MainWindow::add5() {addSymbol("5");}
void MainWindow::add6() {addSymbol("6");}
void MainWindow::add7() {addSymbol("7");}
void MainWindow::add8() {addSymbol("8");}
void MainWindow::add9() {addSymbol("9");}

void MainWindow::plus() {addSymbol("+");}
void MainWindow::minus() {addSymbol("-");}
void MainWindow::multiply() {addSymbol("*");}
void MainWindow::divide() {addSymbol("/");}
void MainWindow::dot() {addSymbol(".");}
void MainWindow::degree() {addSymbol("^");}


void MainWindow::setOperation(const QString &text)
{
    for (const auto &operation : operations)
    {
        if (operationDigitPos == 0 && operations.contains(text) && currentExpression.size() >= 1
            && (currentExpression.endsWith(operation) || currentExpression.endsWith(".") == false))
        {
            operationDigitPos = currentExpression.size();
            break;
        }
    }
}


void MainWindow::zeroIsPossible(const QString &text)
{
    bool shouldAppendText = false;

    if (currentExpression.isEmpty())
    {
        shouldAppendText = true;
    }
    else
    {
        for (const auto &operation : operations)
        {
            if (currentExpression.endsWith(operation))
            {
                shouldAppendText = true;
                break;
            }
        }

        if (!shouldAppendText)
        {
            QChar lastChar = currentExpression.at(currentExpression.size() - 1);
            if (lastChar.isDigit() || lastChar == '.')
            {
                shouldAppendText = true;
            }
        }
    }

    if (shouldAppendText)
    {
        currentExpression += text;
    }
}



void MainWindow::dotIsPossible(const QString &text)
{
    for (int i = 0; i <= 9;i++)
    {
        if (currentExpression.endsWith(QString::number(i)))
        {
            if (operationDigitPos == 0 && !currentExpression.contains("."))
            {
                currentExpression += text;
                break;

            } else if (operationDigitPos != 0 &&currentExpression.mid(operationDigitPos + 1).contains(".") == false)
            {
                currentExpression += text;
                break;
            }
        }
    }
}

void MainWindow::operationDigitIsPossible(QString &text)
{

    if (currentExpression.endsWith(text))
    {
        currentExpression.chop(1);

        if (text == "-")
        {
            text = "+";

            if (currentExpression.endsWith(text))  currentExpression.chop(1);
        }
    }

    currentExpression += text;

    int unique_digits_counter = currentExpression.count("*") + currentExpression.count("/") + currentExpression.count("^");

    if (unique_digits_counter > 1 || (unique_digits_counter == 1 && operationDigitPos != 0 && text != currentExpression[operationDigitPos] && text != "-"))
    {
        currentExpression.chop(1);
    }

}


void MainWindow::addSymbol(QString text)
{
    setOperation(text);

    if (operations.contains(text)) operationDigitIsPossible(text);

    else if (text == "0") zeroIsPossible(text);

    else if (text == ".") dotIsPossible(text);

    else  currentExpression += text;

    inputLine->setText(currentExpression);
}


void MainWindow::AC()
{
    currentExpression.clear();
    operationDigitPos = 0;
    inputLine->clear();
    answerLine->clear();
}

void MainWindow::deleteSign()
{
    if (!currentExpression.isEmpty())
    {
        currentExpression.chop(1);

        inputLine->setText(currentExpression);

        if (currentExpression.size() < operationDigitPos) operationDigitPos = 0;
    }
}

bool MainWindow::validation(const QString &currentExpression)
{

    if (currentExpression.size() >= 3 && operationDigitPos != 0)
    {
        for(int i = 0; i <= 9; i++)
        {
            if (currentExpression.endsWith(QString::number(i)))
            {
                return true;
            }
        }
    }

    return false;
}

double MainWindow::calculate(double num1, double num2, QChar doOperation)
{
    switch (doOperation.unicode())
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    case '^': return pow(num1, num2);
    default: return 0;
    }
}


void MainWindow::result()
{
    if(validation(currentExpression))
    {
        QString value_1 = currentExpression.left(operationDigitPos);

        QString value_2 = currentExpression.mid(operationDigitPos + 1);

        double num1 = value_1.toDouble();
        double num2 = value_2.toDouble();
        QChar  doOperation = currentExpression[operationDigitPos];

        double answer = calculate(num1, num2, doOperation);

        answerLine->setText(value_1 + " " + doOperation + " " + value_2 + "= " +  QString::number(answer, 'g', 15));
    }
    else
    {
        answerLine->setText("Error");
    }
}












