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
    //the explicit constructor
    explicit Grade_Calculator(QWidget *parent = 0);
    //the destructor
    ~Grade_Calculator();
    //this function returns a double cooresponding to the PIC10C overall grade
    double calculatePIC10CGrade();
    //this function returns a double cooresponding to the Math131BH overall grade
    double calculateMath131BHGrade();

private slots:
    //this slot changes the grading scheme to PIC10C when the radio button labeled as such is pressed
    void radioButtonClicked();
    //this slot changes the grading scheme to Math131BH when the radio button labeled as such is pressed
    void radioButton2Clicked();
    //this slot displays the grade when the push button "Submit" is clicked
    void submitClicked();
    //this slot resets all values to 0 when the push button "Reset" is clicked
    void resetClicked();

private:
    Ui::Grade_Calculator *ui;
    bool typePIC10C;
    bool typeMath131BH;

};

#endif // GRADE_CALCULATOR_H
