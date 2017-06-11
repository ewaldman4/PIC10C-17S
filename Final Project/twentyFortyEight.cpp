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

    score = new QLabel("Score: \n 0");
    score->setAlignment(Qt::AlignCenter);
    score->setStyleSheet("QLabel{background-color: #bbaaa9; color: darkRed; font:15pt;}");
    grid->addWidget(score,0,1);

    for(int verticalIterator = 0; verticalIterator < 4; verticalIterator++)
        {
        for(int horizontalIterator = 0; horizontalIterator < 4; horizontalIterator++)
            {
            valuesOfGrid[verticalIterator][horizontalIterator] = new QLabel("1");
            valuesOfGrid[verticalIterator][horizontalIterator] ->setAlignment(Qt::AlignCenter);
            valuesOfGrid[verticalIterator][horizontalIterator] ->setStyleSheet("QLabel{background-color: white; color: black; font: 15pt; border-radius: 7px}");
            grid->addWidget(valuesOfGrid[verticalIterator][horizontalIterator], verticalIterator + 1, horizontalIterator);
            }
        }

    setFixedSize(400,400);
}

TwentyFortyEight::~TwentyFortyEight()
{
    delete ui;
}
