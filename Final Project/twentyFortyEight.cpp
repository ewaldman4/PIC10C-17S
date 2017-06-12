#include "twentyfortyeight.h"
#include "ui_twentyfortyeight.h"

TwentyFortyEight::TwentyFortyEight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TwentyFortyEight)
{
    QTime time = QTime::currentTime();
    srand(time.msec());
    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);
    grid = new QGridLayout(mainWidget);

    newGame = new QPushButton;
    newGame->setText("New Game");
    grid->addWidget(newGame,0,0);

    gameTitle = new QLabel;
    gameTitle->setText("2048");
    gameTitle->setAlignment(Qt::AlignCenter);
    gameTitle->setStyleSheet("QLabel{background-color: #46dbbd; color: white; font: 20pt}");
    grid->addWidget(gameTitle,0,1);

    score = new QLabel;
    score->setText("Score: \n 0");
    score->setAlignment(Qt::AlignCenter);
    score->setStyleSheet("QLabel{background-color: #bbaaa9; color: darkRed; font:15pt;}");
    grid->addWidget(score,0,2);

    for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {
        for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
            valuesOfGrid[verticalIterator][horizontalIterator] = new QLabel("");
            valuesOfGrid[verticalIterator][horizontalIterator]->setAlignment(Qt::AlignCenter);
            changeTile(verticalIterator, horizontalIterator);
            grid->addWidget(valuesOfGrid[verticalIterator][horizontalIterator], verticalIterator + 1, horizontalIterator);
            }
        }

    setFixedSize(400,400);
    setFocus();
    placeRandomValueInGrid();
    valuesOfGrid[1][0]->setText("2");
    changeTile(1,0);
    valuesOfGrid[2][0]->setText("2");
    changeTile(2,0);

}

TwentyFortyEight::~TwentyFortyEight()
{
    delete ui;
}

void TwentyFortyEight::changeTile(int verticalPosition, int horizontalPosition)
{
    switch(valuesOfGrid[verticalPosition][horizontalPosition]->text().toInt()){
        case 0:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: #ccc79b;}");
            break;
        case 2:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: blue; color: black; font: 15pt; border-radius: 7px}");
            break;
        case 4:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: red; color: black; font: 15pt; border-radius: 7px}");
            break;
    }
}

 void TwentyFortyEight:: placeRandomValueInGrid(){
     bool gridIsEmpty = true;
     bool gridIsFull = true;
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {
         for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
             {
                 gridIsEmpty = false;
             }
         }
     }

     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {
         for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "")
             {
                 gridIsFull = false;
             }
         }
     }

     if(gridIsEmpty == true){
         int randomVerticalPosition = qrand()%4;
         int randomHorizontalPosition = qrand()%4;
         valuesOfGrid[randomVerticalPosition][randomHorizontalPosition]->setText("2");
         changeTile(randomVerticalPosition, randomHorizontalPosition);
     }

     if(gridIsFull == false && gridIsEmpty == false)
     {
         int randomVerticalPosition = 0;
         int randomHorizontalPosition = 0;
         do{
             randomVerticalPosition = qrand()%4;
             randomHorizontalPosition = qrand()%4;
           }while(valuesOfGrid[randomVerticalPosition][randomHorizontalPosition]->text() != "");
         int twoOrFour = (qrand()%2+1) * 2;
         valuesOfGrid[randomVerticalPosition][randomHorizontalPosition]->setText(QString::number(twoOrFour));
         changeTile(randomVerticalPosition, randomHorizontalPosition);
     }

     if(gridIsFull == true)
     {
         int x = 0;
     }
 }

 void TwentyFortyEight::keyPressEvent(QKeyEvent *event)
 {
     switch(event->key())
     {
         case Qt::Key_Up:
             upIsPressed();
             break;
             /*
         case Qt::Key_Left():
             leftIsPressed();
             break;
         case Qt::Key_Right():
             rightIsPressed();
             break;
         case Qt::Key_Down():
             downIsPressed();
             break;
             */
         default:
             QMainWindow::keyPressEvent(event);
     }
     placeRandomValueInGrid();
 }

 void TwentyFortyEight::upIsPressed()
 {
     for(int verticalIterator = 3; verticalIterator > 0; verticalIterator--)
        {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
         {
           if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == valuesOfGrid[verticalIterator--][horizontalIterator]->text()
                   && valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
           {
               valuesOfGrid[verticalIterator][horizontalIterator]->setText("");
               changeTile(verticalIterator, horizontalIterator);
               valuesOfGrid[verticalIterator--][horizontalIterator]->setText(QString::number(2*valuesOfGrid[verticalIterator--][horizontalIterator]->text().toInt()));
               changeTile(verticalIterator--, horizontalIterator);
           }
         }
     }
     /*
     for(int verticalIterator = 0; verticalIterator < 3; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator++][horizontalIterator]->text() != "")
             {
                 valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator++][horizontalIterator]->text());
                 changeTile(verticalIterator, horizontalIterator);
                 valuesOfGrid[verticalIterator++][horizontalIterator]->setText("");
                 changeTile(verticalIterator++, horizontalIterator);
             }
            }
     }
     */
 }
