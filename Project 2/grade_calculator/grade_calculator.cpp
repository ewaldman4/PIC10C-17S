#include "grade_calculator.h"
#include "ui_grade_calculator.h"

//The constructor. This constructor sets the connections between slots and signals
//as well as sets the maxima of all the slot boxes in the program
Grade_Calculator::Grade_Calculator(QWidget *parent) :
    typePIC10C(false),
    typeMath131BH(false),
    QMainWindow(parent),
    ui(new Ui::Grade_Calculator)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(submitClicked()));
    QObject::connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));
    QObject::connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(radioButton2Clicked()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(resetClicked()));

    ui->HW1_Received_Score->setMaximum(100);
    ui->HW1_Total_Score->setMaximum(100);
    ui->HW2_Received_Score->setMaximum(100);
    ui->HW2_Total_Score->setMaximum(100);
    ui->HW3_Received_Score->setMaximum(100);
    ui->HW3_Total_Score->setMaximum(100);
    ui->HW4_Received_Score->setMaximum(100);
    ui->HW4_Total_Score->setMaximum(100);
    ui->HW5_Received_Score->setMaximum(100);
    ui->HW5_Total_Score->setMaximum(100);
    ui->HW6_Received_Score->setMaximum(100);
    ui->HW6_Total_Score->setMaximum(100);
    ui->HW7_Received_Score->setMaximum(100);
    ui->HW7_Total_Score->setMaximum(100);
    ui->HW8_Received_Score->setMaximum(100);
    ui->HW8_Total_Score->setMaximum(100);
    ui->Midterm_Received_Score->setMaximum(100);
    ui->Midterm_Total_Score->setMaximum(100);
    ui->FinalExam_Received_Score->setMaximum(100);
    ui->FinalExam_Total_Score->setMaximum(100);
    ui->FinalProject_Received_Score->setMaximum(100);
    ui->FinalProject_Total_Score->setMaximum(100);
}

//The destructor. Through RAII properties, this will delete everything.
Grade_Calculator::~Grade_Calculator()
{
    delete ui;
}

//This program computes the PIC10C grade by taking inputs from values given to the spin boxes and
//using a formula given on the rubric to compute grades.
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

    if(std::isnan(overallGradeScheme1)||std::isnan(overallGradeScheme2))
    {
        return -1;
    }

    if(overallGradeScheme1 >= overallGradeScheme2)
    {
        return overallGradeScheme1;
    }
    else
    {
        return overallGradeScheme2;
    }
}

//This program computes the Math131BH grade by taking inputs from values given to the spin boxes and
//using a formula given on the rubric to compute grades.
double Grade_Calculator:: calculateMath131BHGrade(){
    double hw1Score = (ui->HW1_Received_Score->text()).toDouble()/(ui->HW1_Total_Score->text()).toDouble();
    double hw2Score = (ui->HW2_Received_Score->text()).toDouble()/(ui->HW2_Total_Score->text()).toDouble();
    double hw3Score = (ui->HW3_Received_Score->text()).toDouble()/(ui->HW3_Total_Score->text()).toDouble();
    double hw4Score = (ui->HW4_Received_Score->text()).toDouble()/(ui->HW4_Total_Score->text()).toDouble();
    double hw5Score = (ui->HW5_Received_Score->text()).toDouble()/(ui->HW5_Total_Score->text()).toDouble();
    double hw6Score = (ui->HW6_Received_Score->text()).toDouble()/(ui->HW6_Total_Score->text()).toDouble();
    double hw7Score = (ui->HW7_Received_Score->text()).toDouble()/(ui->HW7_Total_Score->text()).toDouble();
    double hw8Score = (ui->HW8_Received_Score->text()).toDouble()/(ui->HW8_Total_Score->text()).toDouble();
    int numberOfHWAssignments = 8;
    double averageHomeworkScore = (hw1Score + hw2Score + hw3Score + hw4Score + hw5Score + hw6Score + hw7Score + hw8Score)/numberOfHWAssignments;

    double midtermScore = (ui->Midterm_Received_Score->text()).toDouble()/(ui->Midterm_Total_Score->text()).toDouble();

    double finalExamScore = (ui->FinalExam_Received_Score->text()).toDouble()/(ui->FinalExam_Total_Score->text()).toDouble();

    double overallGradeScheme = (.4 * averageHomeworkScore + .2 * midtermScore + .4 * finalExamScore) * 100;


    if(std::isnan(overallGradeScheme))
    {
        return -1;
    }

    return overallGradeScheme;
}

//This slot changes the grading scheme used depending on whether the button labelled "PIC10C" is clicked
void Grade_Calculator:: radioButtonClicked(){
    typePIC10C = true;
    typeMath131BH = false;
}

//This slot changes the grading scheme used depending on whether the button labelled "Math131BH" is clicked
void Grade_Calculator:: radioButton2Clicked(){
    typeMath131BH = true;
    typePIC10C = false;
}

//This slot resets all values on the spin boxes to 0 if reset is clicked
void Grade_Calculator:: resetClicked(){
    ui->HW1_Received_Score->setValue(0);
    ui->HW1_Total_Score->setValue(0);
    ui->HW2_Received_Score->setValue(0);
    ui->HW2_Total_Score->setValue(0);
    ui->HW3_Received_Score->setValue(0);
    ui->HW3_Total_Score->setValue(0);
    ui->HW4_Received_Score->setValue(0);
    ui->HW4_Total_Score->setValue(0);
    ui->HW5_Received_Score->setValue(0);
    ui->HW5_Total_Score->setValue(0);
    ui->HW6_Received_Score->setValue(0);
    ui->HW6_Total_Score->setValue(0);
    ui->HW7_Received_Score->setValue(0);
    ui->HW7_Total_Score->setValue(0);
    ui->HW8_Received_Score->setValue(0);
    ui->HW8_Total_Score->setValue(0);
    ui->Midterm_Received_Score->setValue(0);
    ui->Midterm_Total_Score->setValue(0);
    ui->FinalExam_Received_Score->setValue(0);
    ui->FinalExam_Total_Score->setValue(0);
    ui->FinalProject_Received_Score->setValue(0);
    ui->FinalProject_Total_Score->setValue(0);
    ui->lineEdit->setText("0%");
}

//This slot displays the grade value in a text box if submit is clicked, and will display an error under certain conditions
void Grade_Calculator:: submitClicked(){
    double grade = -2;
    if(typePIC10C == true)
    {
        grade = calculatePIC10CGrade();
    }
    else if(typeMath131BH == true)
    {
        grade = calculateMath131BHGrade();
    }
    if(grade == -1)
    {
       ui->lineEdit->setText("Invalid Input");
    }
    else if(grade == -2)
    {
      ui->lineEdit->setText("Please choose a class scheme.");
    }
    else
    {
      ui->lineEdit->setText(QString::number(grade) + "%");
    }
}
