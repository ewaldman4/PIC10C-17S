#ifndef TWENTYFORTYEIGHT_H
#define TWENTYFORTYEIGHT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QPushButton>
#include <QTime>
#include <QKeyEvent>
#include <iostream>

namespace Ui {
class TwentyFortyEight;
}

class TwentyFortyEight : public QMainWindow
{
    Q_OBJECT

public:
    explicit TwentyFortyEight(QWidget *parent = 0);
    ~TwentyFortyEight();

private:
    void keyPressEvent (QKeyEvent *event);
    void upIsPressed();
    void leftIsPressed();
    void rightIsPressed();
    void downIsPressed();
    void changeTile(int verticalPosition, int horizontalPosition);
    void placeRandomValueInGrid();
    Ui::TwentyFortyEight *ui;
    QWidget *mainWidget;
    QPushButton *newGame;
    QGridLayout *grid;
    QLabel *score;
    QLabel *valuesOfGrid[4][4];
    QLabel *gameTitle;

};

#endif // TWENTYFORTYEIGHT_H
