#ifndef DATAEDITINGWINDOW_H
#define DATAEDITINGWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class DataEditingWindow;
}

class DataEditingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DataEditingWindow(QWidget *parent = nullptr);
    ~DataEditingWindow();

    int getGDP();

    int getNominalGrow();

    int getInflation();

    int getDebt();

    int getDebtPercentage();

    int getIncomeTax();

    int getBusinessTax();

    int getExciseIncome();

    int getOtherIncome();

private slots:
    void on_enterGDP_textChanged(const QString &arg1);

    void on_enterNominalGrow_textChanged(const QString &arg1);

    void on_enterInflation_textChanged(const QString &arg1);

    void on_enterDebt_textChanged(const QString &arg1);

    void on_enterDebtPercentage_textChanged(const QString &arg1);

    void on_enterIncomeTax_textChanged(const QString &arg1);

    void on_enterBusinessTax_textChanged(const QString &arg1);

    void on_enterExciseIncome_textChanged(const QString &arg1);

    void on_enterOtherIncome_textChanged(const QString &arg1);

private:
    Ui::DataEditingWindow *ui;

    int inflation;
    int debt;
    int debtPercentage;
    int gdp;
    int gdpNominalGrow;

    int incomeTax;
    int businessTax;
    int exciseIncome;
    int otherIncome;

};

#endif // DATAEDITINGWINDOW_H
