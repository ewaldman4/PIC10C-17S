#include "grade_calculator.h"
#include "ui_grade_calculator.h"

Grade_Calculator::Grade_Calculator(QWidget *parent) :
    typePIC10C(false),
    typeMath131BH(false),
    QMainWindow(parent),
    ui(new Ui::Grade_Calculator)
{
    ui->setupUi(this);
}

Grade_Calculator::~Grade_Calculator()
{
    delete ui;
}

double Grade_Calculator:: calculatePIC10CGrade(){
    double hw1Score = (ui->HW1_Received_Score->text()).toDouble()/(ui->HW1_Total_Score->text()).toDouble();
    double hw2Score = (ui->HW2_Received_Score->text()).toDouble()/(ui->HW2_Total_Score->text()).toDouble();
    double hw3Score = (ui->HW3_Received_Score->text()).toDouble()/(ui->HW3_Total_Score->text()).toDouble();
    int numberOfHWAssignments = 3;
    double averageHomeworkScore = (hw1Score + hw2Score + hw3Score)/numberOfHWAssignments;

    double midtermScore = (ui->Midterm_Received_Score->text()).toDouble()/(ui->Midterm_Total_Score->text()).toDouble();

    double finalExamScore = (ui->FinalExam_Received_Score->text()).toDouble()/(ui->FinalExam_Total_Score->text()).toDouble(); \

    double finalProjectScore = (ui->FinalProject_Received_Score->text()).toDouble()/(ui->FinalProject_Total_Score->text()).toDouble();

    double overallGradeScheme1 = (.15 * averageHomeworkScore + .25 * midtermScore + .3 * finalExamScore + .3 * finalProjectScore) * 100;
    double overallGradeScheme2 = (.15 * averageHomeworkScore + .5 * finalExamScore + .35 * finalProjectScore) * 100;

    if(overallGradeScheme1 >= overallGradeScheme2)
    {
        return overallGradeScheme1;
    }
    else
    {
        return overallGradeScheme2;
    }
}

void Grade_Calculator:: radioButtonClicked(){
    typePIC10C = true;
}

void Grade_Calculator:: radioButton2Clicked(){
    typeMath131BH = true;
}

void Grade_Calculator:: submitClicked(){
    double grade = 0;
    if(typePic10C == true)
    {
        grade = calculatePIC10CGrade();
    }
    else if(typeMath131BH == true)
    {
        grade = calculateMath131BHGrade();
    }
    ui->lineEdit->setText(grade + "%");
}
