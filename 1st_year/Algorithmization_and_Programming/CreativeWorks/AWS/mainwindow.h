#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataeditingwindow.h"
#include <QRandomGenerator>
#include <QPixmap>
#include <QPalette>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void milExpencesChanged(int newValue);

    void civilExpencesChanged(int newValue);

    void milDiagramChanged(int newValue);

    void civilDiagramChanged(int newValue);

    void resetSliders();

    void enterInputData();

    void resultChanged();

private slots:
    void on_armySlider_valueChanged(int value);

    void on_navySlider_valueChanged(int value);

    void on_airSlider_valueChanged(int value);

    void on_milExpences_Changed(int newValue);


    void on_socSlider_valueChanged(int value);

    void on_adminSlider_valueChanged(int value);

    void on_scienceSldier_valueChanged(int value);

    void on_civilExpences_Changed(int newValue);


    void on_milDiagram_Changed(int newValue);

    void on_civilDiagram_Changed(int newValue);


    void on_windowButton_clicked();

    void on_enter_Input_Data();


    void on_resetButton_clicked();

    void on_resetSliders();

    void on_expences_changed();


    void on_civilLower_clicked();

    void on_milLower_clicked();

    void on_taxesLower_clicked();

    void on_taxesHigher_clicked();

    void on_result_Changed();

private:
    Ui::MainWindow *ui;

    int armyExpences;
    int navyExpences;
    int airExpences;
    int milExpences;
    bool isMilButtonClicked;

    int socialExpences;
    int adminExpences;
    int scienceExpences;
    int civilExpences;
    bool isCivilButtonClicked;

    int debtExpences;
    int otherExpences;

    int expences;

    int inflation;
    int debt;
    int debtPercentage;
    int gdp;
    int gdpNominalGrow;
    int gdpGrow;

    int incomeTax;
    int businessTax;
    int exciseIncome;
    int otherIncome;
    bool isLowerTaxesClicked;
    bool isHigherTaxesClicked;

    int income;

    int result;
};
#endif // MAINWINDOW_H
