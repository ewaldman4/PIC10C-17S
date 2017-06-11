#include "twentyfortyeight.h"
#include "ui_twentyfortyeight.h"

TwentyFortyEight::TwentyFortyEight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TwentyFortyEight)
{
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
            changeColor(verticalIterator, horizontalIterator);
            grid->addWidget(valuesOfGrid[verticalIterator][horizontalIterator], verticalIterator + 1, horizontalIterator);
            }
        }

    setFixedSize(400,400);
}

TwentyFortyEight::~TwentyFortyEight()
{
    delete ui;
}

void TwentyFortyEight::changeColor(int verticalPosition, int horizontalPosition)
{
    switch(valuesOfGrid[verticalPosition][horizontalPosition]->text().toInt()){
        case 0:
        valuesOfGrid[verticalPosition][horizontalPosition]->setStyleSheet("QLabel{background-color: white; color: black; font: 15pt; border-radius: 7px}");
    }
}
