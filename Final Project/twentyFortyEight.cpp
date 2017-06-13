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
}

TwentyFortyEight::~TwentyFortyEight()
{
    delete ui;
}

void TwentyFortyEight::changeTile(int verticalPosition, int horizontalPosition)
{
    switch(valuesOfGrid[verticalPosition][horizontalPosition]->text().toInt()){
        case 0:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: #ccc79b; color: #ccc79b}");
            break;
        case 2:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: blue; color: black; font: 15pt; border-radius: 7px}");
            break;
        case 4:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: red; color: black; font: 15pt; border-radius: 7px}");
            break;
        case 8:
            valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: green; color: black; font: 15pt; border-radius: 7px}");
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
     bool hasSomethingMoved = false;
     switch(event->key())
     {
         case Qt::Key_Up:
             hasSomethingMoved = upIsPressed();
             break;
         case Qt::Key_Down:
             hasSomethingMoved = downIsPressed();
             break;
         case Qt::Key_Left:
             hasSomethingMoved = leftIsPressed();
             break;
         case Qt::Key_Right:
             hasSomethingMoved = rightIsPressed();
             break;
         default:
             QMainWindow::keyPressEvent(event);
     }
     if(hasSomethingMoved == true)
     {
        placeRandomValueInGrid();
     }
 }

 bool TwentyFortyEight::upIsPressed()
 {
    bool somethingMoved = false;
    for(int verticalIterator = 0; verticalIterator < 3; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator + 1][horizontalIterator]->text() != "")
             {
                 somethingMoved = true;
                 valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator + 1][horizontalIterator]->text());
                 changeTile(verticalIterator, horizontalIterator);
                 valuesOfGrid[verticalIterator + 1][horizontalIterator]->setText("");
                 changeTile(verticalIterator + 1, horizontalIterator);
                 int k = verticalIterator;
                 while(k > 0)
                 {
                    if(valuesOfGrid[k - 1][horizontalIterator]->text() == "" && valuesOfGrid[k][horizontalIterator]->text() != "")
                    {
                        valuesOfGrid[k - 1][horizontalIterator]->setText(valuesOfGrid[k][horizontalIterator]->text());
                        changeTile(k - 1, horizontalIterator);
                        valuesOfGrid[k][horizontalIterator]->setText("");
                        changeTile(k, horizontalIterator);
                    }
                    k--;
                 }
        }
       }
      }
     for(int verticalIterator = 0; verticalIterator < 3; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
         {
           if((valuesOfGrid[verticalIterator][horizontalIterator]->text() == valuesOfGrid[verticalIterator + 1][horizontalIterator]->text())
                   && valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
           {
               somethingMoved = true;
               valuesOfGrid[verticalIterator + 1][horizontalIterator]->setText("");
               changeTile(verticalIterator + 1, horizontalIterator);
               valuesOfGrid[verticalIterator][horizontalIterator]->setText(QString::number(2*valuesOfGrid[verticalIterator][horizontalIterator]->text().toInt()));
               changeTile(verticalIterator, horizontalIterator);
           }
         }
     }
     for(int verticalIterator = 0; verticalIterator < 3; verticalIterator++)
         {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
             {
              if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator + 1][horizontalIterator]->text() != "")
              {
                  valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator + 1][horizontalIterator]->text());
                  changeTile(verticalIterator, horizontalIterator);
                  valuesOfGrid[verticalIterator + 1][horizontalIterator]->setText("");
                  changeTile(verticalIterator + 1, horizontalIterator);
         }
        }
       }
     return somethingMoved;
}

bool TwentyFortyEight::downIsPressed()
 {
    bool somethingMoved = false;
     for(int verticalIterator = 3; verticalIterator > 0; verticalIterator--)
         {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
             {
              if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator - 1][horizontalIterator]->text() != "")
              {
                  somethingMoved = true;
                  valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator - 1][horizontalIterator]->text());
                  changeTile(verticalIterator, horizontalIterator);
                  valuesOfGrid[verticalIterator - 1][horizontalIterator]->setText("");
                  changeTile(verticalIterator - 1, horizontalIterator);
                  int k = verticalIterator;
                  while(k < 3)
                  {
                     if(valuesOfGrid[k + 1][horizontalIterator]->text() == "" && valuesOfGrid[k][horizontalIterator]->text() != "")
                     {
                         valuesOfGrid[k + 1][horizontalIterator]->setText(valuesOfGrid[k][horizontalIterator]->text());
                         changeTile(k + 1, horizontalIterator);
                         valuesOfGrid[k][horizontalIterator]->setText("");
                         changeTile(k, horizontalIterator);
                     }
                     k++;
                  }
              }
         }
        }
     for(int verticalIterator = 3; verticalIterator > 0; verticalIterator--)
        {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
         {
           if((valuesOfGrid[verticalIterator][horizontalIterator]->text() == valuesOfGrid[verticalIterator - 1][horizontalIterator]->text())
                   && valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
           {
               somethingMoved = true;
               valuesOfGrid[verticalIterator - 1][horizontalIterator]->setText("");
               changeTile(verticalIterator - 1, horizontalIterator);
               valuesOfGrid[verticalIterator][horizontalIterator]->setText(QString::number(2*valuesOfGrid[verticalIterator][horizontalIterator]->text().toInt()));
               changeTile(verticalIterator, horizontalIterator);
           }
         }
     }
     for(int verticalIterator = 3; verticalIterator > 0; verticalIterator--)
         {for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
             {
              if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator - 1][horizontalIterator]->text() != "")
              {
                  valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator - 1][horizontalIterator]->text());
                  changeTile(verticalIterator, horizontalIterator);
                  valuesOfGrid[verticalIterator - 1][horizontalIterator]->setText("");
                  changeTile(verticalIterator - 1, horizontalIterator);
              }
         }
        }
     return somethingMoved;
}

bool TwentyFortyEight::leftIsPressed()
 {
    bool somethingMoved = false;
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 3; horizontalIterator++)
         {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator][horizontalIterator + 1]->text() != "")
             {
                 somethingMoved = true;
                 valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator][horizontalIterator + 1]->text());
                 changeTile(verticalIterator, horizontalIterator);
                 valuesOfGrid[verticalIterator][horizontalIterator + 1]->setText("");
                 changeTile(verticalIterator, horizontalIterator + 1);
                 int k = horizontalIterator;
                 while(k > 0)
                 {
                    if(valuesOfGrid[verticalIterator][k - 1]->text() == "" && valuesOfGrid[verticalIterator][k]->text() != "")
                    {
                        valuesOfGrid[verticalIterator][k - 1]->setText(valuesOfGrid[verticalIterator][k]->text());
                        changeTile(verticalIterator, k - 1);
                        valuesOfGrid[verticalIterator][k]->setText("");
                        changeTile(verticalIterator, k);
                    }
                    k--;
                 }
     }
     }
     }
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 3; horizontalIterator++)
         {
           if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == valuesOfGrid[verticalIterator][horizontalIterator + 1]->text()
                   && valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
           {
               somethingMoved = true;
               valuesOfGrid[verticalIterator][horizontalIterator + 1]->setText("");
               changeTile(verticalIterator, horizontalIterator + 1);
               valuesOfGrid[verticalIterator][horizontalIterator]->setText(QString::number(2*valuesOfGrid[verticalIterator][horizontalIterator]->text().toInt()));
               changeTile(verticalIterator, horizontalIterator);
           }
     }
     }
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {for(int horizontalIterator = 0; horizontalIterator < 3; horizontalIterator++)
         {
             if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator][horizontalIterator + 1]->text() != "")
             {
                 valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator][horizontalIterator + 1]->text());
                 changeTile(verticalIterator, horizontalIterator);
                 valuesOfGrid[verticalIterator][horizontalIterator + 1]->setText("");
                 changeTile(verticalIterator, horizontalIterator + 1);
             }
         }
     }
     return somethingMoved;
 }

bool TwentyFortyEight::rightIsPressed()
 {
    bool somethingMoved = false;
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
         {for(int horizontalIterator = 3; horizontalIterator > 0; horizontalIterator--)
             {
              if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator][horizontalIterator - 1]->text() != "")
              {
                  somethingMoved = true;
                  valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator][horizontalIterator - 1]->text());
                  changeTile(verticalIterator, horizontalIterator);
                  valuesOfGrid[verticalIterator][horizontalIterator - 1]->setText("");
                  changeTile(verticalIterator, horizontalIterator - 1);
                  int k = horizontalIterator;
                  while(k < 3)
                  {
                     if(valuesOfGrid[verticalIterator][k + 1]->text() == "" && valuesOfGrid[verticalIterator][k]->text() != "")
                     {
                         valuesOfGrid[verticalIterator][k + 1]->setText(valuesOfGrid[verticalIterator][k]->text());
                         changeTile(verticalIterator, k + 1);
                         valuesOfGrid[verticalIterator][k]->setText("");
                         changeTile(verticalIterator, k);
                     }
                     k++;
                  }
              }
         }
        }
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {for(int horizontalIterator = 3; horizontalIterator > 0; horizontalIterator--)
         {
           if((valuesOfGrid[verticalIterator][horizontalIterator]->text() == valuesOfGrid[verticalIterator][horizontalIterator - 1]->text())
                   && valuesOfGrid[verticalIterator][horizontalIterator]->text() != "")
           {
               somethingMoved = true;
               valuesOfGrid[verticalIterator][horizontalIterator - 1]->setText("");
               changeTile(verticalIterator, horizontalIterator - 1);
               valuesOfGrid[verticalIterator][horizontalIterator]->setText(QString::number(2*valuesOfGrid[verticalIterator][horizontalIterator]->text().toInt()));
               changeTile(verticalIterator, horizontalIterator);
           }
         }
     }
     for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
         {for(int horizontalIterator = 3; horizontalIterator > 0; horizontalIterator--)
             {
              if(valuesOfGrid[verticalIterator][horizontalIterator]->text() == "" && valuesOfGrid[verticalIterator][horizontalIterator - 1]->text() != "")
              {
                  valuesOfGrid[verticalIterator][horizontalIterator]->setText(valuesOfGrid[verticalIterator][horizontalIterator - 1]->text());
                  changeTile(verticalIterator, horizontalIterator);
                  valuesOfGrid[verticalIterator][horizontalIterator - 1]->setText("");
                  changeTile(verticalIterator, horizontalIterator - 1);
              }
         }
        }
     return somethingMoved;
}
