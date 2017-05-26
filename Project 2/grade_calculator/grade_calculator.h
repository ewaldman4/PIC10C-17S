#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Grade_Calculator;
}

class Grade_Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grade_Calculator(QWidget *parent = 0);
    ~Grade_Calculator();
    double calculatePIC10CGrade();
    double calculateMath131BHGrade();

private slots:
    void radioButtonClicked();
    void radioButton2Clicked();
    void submitClicked();
    void resetClicked();

private:
    Ui::Grade_Calculator *ui;
    bool typePIC10C;
    bool typeMath131BH;

};

#endif // GRADE_CALCULATOR_H
