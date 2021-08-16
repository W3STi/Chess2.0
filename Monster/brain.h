#ifndef BRAIN_H
#define BRAIN_H

#include <QApplication>
#include "mainwindow.h"
#include "monster_element.h"
#include <QPen>

class BRAIN
{
public:
    MainWindow* wnd;
    QVector<QVector<int>> board;
    MTable table;

public:
    BRAIN();
    BRAIN(MainWindow* mainwind);

    void start();
    void movingFigure();
    void startPosition();
    void printStartBoard();
    void searchMove(int &xCoord, int &yCoord,
                    int &xMove, int &yMove, QVector<QVector<int>>& board);
};

#endif // BRAIN_H
