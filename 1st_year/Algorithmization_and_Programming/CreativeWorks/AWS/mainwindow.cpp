#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap incomeImage(":/images/resources/income.png");
    int width1 = ui->incomeImage->width();
    int height1 = ui->incomeImage->height();
    ui->incomeImage->setPixmap(incomeImage.scaled(width1, height1, Qt::KeepAspectRatio));

    QPixmap expenceImage(":/images/resources/expences.png");
    int width2 = ui->expenceImage->width();
    int height2 = ui->expenceImage->height();
    ui->expenceImage->setPixmap(expenceImage.scaled(width2, height2, Qt::KeepAspectRatio));


    QPixmap gdpImage(":/images/resources/gdp.png");
    int width3 = ui->gdpImage->width();
    int height3 = ui->gdpImage->height();
    ui->gdpImage->setPixmap(gdpImage.scaled(width3, height3, Qt::KeepAspectRatio));

    QPixmap debtImage(":/images/resources/debt.png");
    int width4 = ui->debtImage->width();
    int height4 = ui->debtImage->height();
    ui->debtImage->setPixmap(debtImage.scaled(width4, height4, Qt::KeepAspectRatio));


    connect(this, &MainWindow::milExpencesChanged, this, &MainWindow::on_milExpences_Changed);
    connect(this, &MainWindow::civilExpencesChanged, this, &MainWindow::on_civilExpences_Changed);

    connect(this, &MainWindow::milExpencesChanged, this, &MainWindow::on_milDiagram_Changed);
    connect(this, &MainWindow::civilExpencesChanged, this, &MainWindow::on_civilDiagram_Changed);

    connect(this, &MainWindow::milExpencesChanged, this, &MainWindow::on_expences_changed);
    connect(this, &MainWindow::civilExpencesChanged, this, &MainWindow::on_expences_changed);

    connect(this, &MainWindow::resetSliders, this, &MainWindow::on_resetSliders);

    connect(this, &MainWindow::enterInputData, this, &MainWindow::on_enter_Input_Data);

    connect(this, &MainWindow::resultChanged, this, &MainWindow::on_result_Changed);


    armyExpences = 50;
    navyExpences = 50;
    airExpences = 50;
    milExpences = 150;
    isMilButtonClicked = false;

    socialExpences = 50;
    adminExpences = 50;
    scienceExpences = 50;
    civilExpences = 150;
    isCivilButtonClicked = false;

    otherExpences = QRandomGenerator::global()->bounded(50);
    ui->otherCounter->display(otherExpences);
    ui->othersDiagram->display(otherExpences);


    inflation = QRandomGenerator::global()->bounded(1,10);
    ui->inflationCounter->display(inflation);

    debt = QRandomGenerator::global()->bounded(50,400);
    ui->nationalDebtCounter->display(debt);

    debtPercentage = QRandomGenerator::global()->bounded(5, 15);
    ui->debtPercentageCounter->display(debtPercentage);

    debtExpences = debt * debtPercentage / 100;
    ui->debtExpenceCounter->display(debtExpences);
    ui->debtCounter_2->display(debtExpences);
    ui->debtDiagram->display(debtExpences);

    gdp = QRandomGenerator::global()->bounded(300, 1000);
    ui->GDPCounter->display(gdp);

    ui->debtToGDPCounter->display(debt * 100 / gdp);

    gdpNominalGrow = QRandomGenerator::global()->bounded(5, 20);
    ui->nominalGDPgrow->display(gdpNominalGrow);

    gdpGrow = gdpNominalGrow-inflation;
    ui->realGDPgrowCounter->display(gdpGrow);

    incomeTax = QRandomGenerator::global()->bounded(150, 400);
    ui->taxDiagram->display(incomeTax);

    businessTax = QRandomGenerator::global()->bounded(100,incomeTax-50);
    ui->businessDiagram->display(businessTax);

    exciseIncome = QRandomGenerator::global()->bounded(20, 100);
    ui->exciseDiagram->display(exciseIncome);

    otherIncome = QRandomGenerator::global()->bounded(5, 50);
    ui->otherIncomeDiagram->display(otherIncome);

    isLowerTaxesClicked = false;
    isHigherTaxesClicked = false;

    expences = milExpences + civilExpences + otherExpences + debtExpences;
    ui->expenciesCount->display(expences);
    income = incomeTax + businessTax + exciseIncome + otherIncome;
    ui->incomeCount->display(income);

    result = income - expences;
    if (result >= 0)
    {
        ui->result->setStyleSheet("QLabel { color: green; }");
        ui->result->setText("ИТОГОВЫЙ ПРОФИЦИТ:" + QString::number(result));

        ui->resultPercentage->setStyleSheet("QLabel { color: green; }");
        ui->resultPercentage->setText("+" + QString::number(result * 100 / gdp) + "% ОТ ВВП");
    }
    else
    {
        ui->result->setStyleSheet("QLabel { color: red; }");
        ui->result->setText("ИТОГОВЫЙ ДЕФИЦИТ: " + QString::number(result));

        ui->resultPercentage->setStyleSheet("QLabel { color: red; }");
        ui->resultPercentage->setText(QString::number(result * 100 / gdp) + "% ОТ ВВП");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_armySlider_valueChanged(int value)
{
    armyExpences = value;
    milExpences = armyExpences + navyExpences + airExpences;

    if (isMilButtonClicked)
    {
        milExpences *= 0.85;
        emit milExpencesChanged(milExpences);
    }
    else emit milExpencesChanged(milExpences);
}


void MainWindow::on_navySlider_valueChanged(int value)
{
    navyExpences = value;
    milExpences = armyExpences + navyExpences + airExpences;

    if (isMilButtonClicked)
    {
        milExpences *= 0.85;
        emit milExpencesChanged(milExpences);
    }
    else emit milExpencesChanged(milExpences);
}


void MainWindow::on_airSlider_valueChanged(int value)
{
    airExpences = value;
    milExpences = armyExpences + navyExpences + airExpences;

    if (isMilButtonClicked)
    {
        milExpences *= 0.85;
        emit milExpencesChanged(milExpences);
    }
    else emit milExpencesChanged(milExpences);
}

void MainWindow::on_milExpences_Changed(int newValue)
{
    ui->milCounter->display(newValue);
}






void MainWindow::on_socSlider_valueChanged(int value)
{
    socialExpences = value;
    civilExpences = socialExpences + adminExpences + scienceExpences;

    if (isCivilButtonClicked) emit
    {
        civilExpences *= 0.85;
        emit civilExpencesChanged(civilExpences);
    }
    else emit civilExpencesChanged(civilExpences);
}


void MainWindow::on_adminSlider_valueChanged(int value)
{
    adminExpences = value;
    civilExpences = socialExpences + adminExpences + scienceExpences;

    if (isCivilButtonClicked) emit civilExpencesChanged(civilExpences*0.85);
    else emit civilExpencesChanged(civilExpences);
}


void MainWindow::on_scienceSldier_valueChanged(int value)
{
    scienceExpences = value;
    civilExpences = socialExpences + adminExpences + scienceExpences;

    if (isCivilButtonClicked) emit civilExpencesChanged(civilExpences*0.85);
    else emit civilExpencesChanged(civilExpences);
}

void MainWindow::on_civilExpences_Changed(int newValue)
{
    ui->civilCounter->display(newValue);
}


void MainWindow::on_milDiagram_Changed(int newValue)
{
    ui->milDiagram->display(newValue);
}

void MainWindow::on_civilDiagram_Changed(int newValue)
{
    ui->civilDiagram->display(newValue);
}



void MainWindow::on_windowButton_clicked()
{
    DataEditingWindow window;
    window.setModal(true);
    if (window.exec())
    {
        gdp = window.getGDP();
        gdpNominalGrow = window.getNominalGrow();
        inflation = window.getInflation();
        debt = window.getDebt();
        debtPercentage = window.getDebtPercentage();
        incomeTax = window.getIncomeTax();
        businessTax = window.getBusinessTax();
        exciseIncome = window.getExciseIncome();
        otherIncome = window.getOtherIncome();
    }
    emit enterInputData();
}

void MainWindow::on_enter_Input_Data()
{
    ui->inflationCounter->display(inflation);

    ui->GDPCounter->display(gdp);

    ui->nominalGDPgrow->display(gdpNominalGrow);

    gdpGrow = gdpNominalGrow - inflation;
    ui->realGDPgrowCounter->display(gdpGrow);

    ui->nationalDebtCounter->display(debt);

    ui->debtToGDPCounter->display(debt * 100 / gdp);

    ui->debtPercentageCounter->display(debtPercentage);

    debtExpences = debt*debtPercentage/100;
    ui->debtExpenceCounter->display(debtExpences);

    ui->debtDiagram->display(debt * debtPercentage/100);

    ui->taxDiagram->display(incomeTax);

    ui->businessDiagram->display(businessTax);

    ui->exciseDiagram->display(exciseIncome);

    ui->otherIncomeDiagram->display(otherIncome);

    income = incomeTax + businessTax + exciseIncome + otherIncome;
    ui->incomeCount->display(income);

    ui->debtCounter_2->display(debtExpences);

    emit resultChanged();
}



void MainWindow::on_resetSliders()
{
    ui->armySlider->setValue(50);
    ui->navySlider->setValue(50);
    ui->airSlider->setValue(50);
    ui->socSlider->setValue(50);
    ui->adminSlider->setValue(50);
    ui->scienceSldier->setValue(50);
}

void MainWindow::on_resetButton_clicked()
{
    armyExpences = 50;
    navyExpences = 50;
    airExpences = 50;
    milExpences = armyExpences + navyExpences + airExpences;

    emit milExpencesChanged(milExpences);

    socialExpences = 50;
    adminExpences = 50;
    scienceExpences = 50;
    civilExpences = socialExpences + adminExpences + scienceExpences;

    emit civilExpencesChanged(civilExpences);

    emit resetSliders();
}

void MainWindow::on_expences_changed()
{
    expences = milExpences + civilExpences + debtExpences + otherExpences;
    ui->expenciesCount->display(expences);

    emit resultChanged();
}


void MainWindow::on_civilLower_clicked()
{
    isCivilButtonClicked = true;

    ui->civilDiagram->display(civilExpences*0.85);
    ui->civilCounter->display(civilExpences*0.85);

    expences = expences - civilExpences*0.15;
    ui->expenciesCount->display(expences);

    ui->civilLower->setDisabled(true);
    ui->milLower->setDisabled(true);

    ui->civilLower->setStyleSheet("QPushButton { background-color: #494464;}");
    ui->milLower->setStyleSheet("QPushButton { background-color: #494464;}");

    emit resultChanged();
}


void MainWindow::on_milLower_clicked()
{
    isMilButtonClicked = true;

    ui->milDiagram->display(milExpences*0.85);
    ui->milCounter->display(milExpences*0.85);

    expences = expences - milExpences*0.15;
    ui->expenciesCount->display(expences);

    ui->civilLower->setDisabled(true);
    ui->milLower->setDisabled(true);

    ui->civilLower->setStyleSheet("QPushButton { background-color: #494464;}");
    ui->milLower->setStyleSheet("QPushButton { background-color: #494464;}");

    emit resultChanged();
}


void MainWindow::on_taxesLower_clicked()
{
    ui->taxDiagram->display(incomeTax*0.85);
    ui->businessDiagram->display(businessTax*0.85);

    income = incomeTax*0.85 + businessTax*0.85 + exciseIncome + otherIncome;
    ui->incomeCount->display(income);

    isLowerTaxesClicked = true;
    ui->taxesLower->setDisabled(true);
    ui->taxesHigher->setDisabled(true);

    ui->taxesHigher->setStyleSheet("QPushButton { background-color: #494464;}");
    ui->taxesLower->setStyleSheet("QPushButton { background-color: #494464;}");

    emit resultChanged();
}


void MainWindow::on_taxesHigher_clicked()
{
    ui->taxDiagram->display(incomeTax*1.15);
    ui->businessDiagram->display(businessTax*1.15);

    income = incomeTax*1.15 + businessTax*1.15 + exciseIncome + otherIncome;
    ui->incomeCount->display(income);

    isHigherTaxesClicked = true;
    ui->taxesLower->setDisabled(true);
    ui->taxesHigher->setDisabled(true);

    ui->taxesHigher->setStyleSheet("QPushButton { background-color: #494464;}");
    ui->taxesLower->setStyleSheet("QPushButton { background-color: #494464;}");

    emit resultChanged();
}

void MainWindow::on_result_Changed()
{
    result = income - expences;
    if (result >= 0)
    {
        ui->result->setStyleSheet("QLabel { color: green; }");
        ui->result->setText("ИТОГОВЫЙ ПРОФИЦИТ:" + QString::number(result));

        ui->resultPercentage->setStyleSheet("QLabel { color: green; }");
        ui->resultPercentage->setText("+" + QString::number(result * 100 / gdp) + "% ОТ ВВП");
    }
    else
    {
        ui->result->setStyleSheet("QLabel { color: red; }");
        ui->result->setText("ИТОГОВЫЙ ДЕФИЦИТ: " + QString::number(result));

        ui->resultPercentage->setStyleSheet("QLabel { color: red; }");
        ui->resultPercentage->setText(QString::number(result * 100 / gdp) + "% ОТ ВВП");
    }
}

