#ifndef TWENTYFORTYEIGHT_H
#define TWENTYFORTYEIGHT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QPushButton>

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
    void changeColor(int verticalPosition, int horizontalPosition);
    Ui::TwentyFortyEight *ui;
    QWidget *mainWidget;
    QPushButton *newGame;
    QGridLayout *grid;
    QLabel *score;
    QLabel *valuesOfGrid[4][4];
    QLabel *gameTitle;

};

#endif // TWENTYFORTYEIGHT_H
