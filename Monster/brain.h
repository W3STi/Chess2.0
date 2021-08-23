#ifndef BRAIN_H
#define BRAIN_H

#include <QApplication>
#include <QTimer>
#include "mainwindow.h"
#include "monster_element.h"
<<<<<<< HEAD
=======

#include <QMenu>
>>>>>>> feef5fe9eb9ab791d9cc1fd5cfb5207dd9fd8b88
#include <QPen>

class BRAIN : public QObject
{
Q_OBJECT
public:
    MainWindow* wnd;
    QVector<QVector<int>> board;
    MTable table;
    QToolBar* toolbar;
    QMap<QAction*, int> _actionToInt;

    QString chess_char = "PRNBQK";
    QVector<QString> chess_style = {"adventurer" , "alpha" , "berlin" , "cardinal" , "cases" ,
                                    "cheq" , "chess24" , "chess7" , "chess_samara" , "chesscom" ,
                                    "chessnut" , "companion" , "condal" , "dash" , "dilena" ,
                                    "dubrovny" , "fantasy" , "fresca" , "glass" , "graffiti" ,
                                    "graffiti_light" , "kingdom" , "kosal" , "leipzig" , "letter" ,
                                    "lucena" , "maestro" , "magnetic" , "marble" , "maya" ,
                                    "mediaeval" , "merida" ,"metro" , "pirouetti" , "pixel" ,
                                    "reilly" , "riohacha" , "shapes" , "spatial" , "staunty" ,
                                    "symbol" , "symmetric" , "tatiana" , "tournament" , "tournament_metal" ,
                                    "uscf" , "wikipedia"
                                   };
    int Style = 0;

public:
    BRAIN();
    BRAIN(MainWindow* mainwind);

    void start();
    void movingFigure();
    void startPosition();
<<<<<<< HEAD
    void printStartBoard();
    void searchMove(int &xCoord, int &yCoord,
                    int &xMove, int &yMove, QVector<QVector<int>>& board);
=======
    void printBoard();
    QToolBar* createToolBar();

    bool checkForRookInFront(int &xCoord, int &yCoord,
                               int &xMove, int &yMove, QVector<QVector<int>>& board, int &temp);
    bool checkForBishopInFront(int &xCoord, int &yCoord,
                               int &xMove, QVector<QVector<int>>& board, int &flag);
    void searchMove(int &xCoord, int &yCoord,
                    int &xMove, int &yMove, QVector<QVector<int>>& board);
    void attackFigures(QVector<QVector<int>>& board, QVector<QVector<char>>& attack);

public slots:
    void test(){wnd->Log("test - brain");}
    void changeStyle(QAction*);
    void read_data(QPointF);

>>>>>>> feef5fe9eb9ab791d9cc1fd5cfb5207dd9fd8b88
};

#endif // BRAIN_H
