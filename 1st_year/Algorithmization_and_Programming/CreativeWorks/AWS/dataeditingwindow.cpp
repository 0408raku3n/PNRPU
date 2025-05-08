#include "dataeditingwindow.h"
#include "ui_dataeditingwindow.h"

DataEditingWindow::DataEditingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataEditingWindow)
{
    ui->setupUi(this);
    inflation = 0;
    debt = 0;
    debtPercentage = 0;
    gdp = 0;
    gdpNominalGrow = 0;

    incomeTax = 0;
    businessTax = 0;
    exciseIncome = 0;
    otherIncome = 0;
}

int DataEditingWindow::getGDP()
{
    return gdp;
}

int DataEditingWindow::getNominalGrow()
{
    return gdpNominalGrow;
}
int DataEditingWindow::getInflation()
{
    return inflation;
}

int DataEditingWindow::getDebt()
{
    return debt;
}

int DataEditingWindow::getDebtPercentage()
{
    return debtPercentage;
}

int DataEditingWindow::getIncomeTax()
{
    return incomeTax;
}

int DataEditingWindow::getBusinessTax()
{
    return businessTax;
}

int DataEditingWindow::getExciseIncome()
{
    return exciseIncome;
}

int DataEditingWindow::getOtherIncome()
{
    return otherIncome;
}


DataEditingWindow::~DataEditingWindow()
{
    delete ui;
}

void DataEditingWindow::on_enterGDP_textChanged(const QString &arg1)
{
    gdp = arg1.toInt();
}


void DataEditingWindow::on_enterNominalGrow_textChanged(const QString &arg1)
{
    gdpNominalGrow = arg1.toInt();
}


void DataEditingWindow::on_enterInflation_textChanged(const QString &arg1)
{
    inflation = arg1.toInt();
}


void DataEditingWindow::on_enterDebt_textChanged(const QString &arg1)
{
    debt = arg1.toInt();
}


void DataEditingWindow::on_enterDebtPercentage_textChanged(const QString &arg1)
{
    debtPercentage = arg1.toInt();
}


void DataEditingWindow::on_enterIncomeTax_textChanged(const QString &arg1)
{
    incomeTax = arg1.toInt();
}


void DataEditingWindow::on_enterBusinessTax_textChanged(const QString &arg1)
{
    businessTax = arg1.toInt();
}


void DataEditingWindow::on_enterExciseIncome_textChanged(const QString &arg1)
{
    exciseIncome = arg1.toInt();
}


void DataEditingWindow::on_enterOtherIncome_textChanged(const QString &arg1)
{
    otherIncome = arg1.toInt();
}

