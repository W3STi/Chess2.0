#include "brain.h"

#define wall -1
#define voidcell 0
#define Wpawn 1
#define Wrook 2
#define Wknight 3
#define Wbishop 4
#define Wqueen 5
#define Wking 6

#define Bpawn 11
#define Brook 12
#define Bknight 13
#define Bbishop 14
#define Bqueen 15
#define Bking 16

// два цвета белый и черный (условно)
QColor chess_white(237,208,177);
QColor chess_black(115,19,10);

// ручки
QPen *chess_black_Pen = new QPen(chess_black);
QPen *whitepen = new QPen(Qt::white);
QPen *redpen = new QPen(Qt::red);
QPen *transparentpen = new QPen(Qt::transparent);

// кисти
QBrush *transparent_Brush = new QBrush(Qt::transparent, Qt::SolidPattern);
QBrush *chess_white_Brush = new QBrush(chess_white, Qt::SolidPattern);
QBrush *chess_black_Brush = new QBrush(chess_black, Qt::SolidPattern);

// конструктор
BRAIN::BRAIN(){

}

// конструктор при вводе  формы на запуск
BRAIN::BRAIN(MainWindow* mainwind)
{
    wnd = mainwind;
    table.SetParent(wnd);
}

// функция старта
void BRAIN::start(){
    redpen->setWidth(3); // толщина ручки
    wnd->addItem(table.GetData());
    wnd->ResetScene();
    table.setSize(10, 10, 60, 60); // поле 8 на 8
    table.setAutoPosition();


    startPosition();
    printStartBoard();

    // отрисовка (делать 1 раз, больше можно не прописывать, если не добавляются новые элементы)
    MButton btn;

}

void BRAIN::startPosition(){
    board.resize(10);
    for (int i = 0; i < 10; i++){
        board[i].resize(10);
    }
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if ((i + j) >= 6 && (i + j) <= 12 && i != 0 &&
                    i != 9 && j != 0 && j != 9){
                board[i][j] = voidcell;
            }
            else board[i][j] = wall;
            }
    }
    board[5][2] = Bpawn;
    board[6][2] = Bpawn;
    board[7][2] = Bpawn;
    board[7][3] = Bpawn;
    board[7][4] = Bpawn;
    board[5][1] = Brook;
    board[8][4] = Brook;
    board[6][1] = Bknight;
    board[8][3] = Bknight;
    board[8][2] = Bbishop;
    board[8][1] = Bbishop;
    board[7][1] = Bking;

    board[2][5] = Wpawn;
    board[2][6] = Wpawn;
    board[2][7] = Wpawn;
    board[3][7] = Wpawn;
    board[4][7] = Wpawn;
    board[1][5] = Wrook;
    board[4][8] = Wrook;
    board[1][6] = Wknight;
    board[3][8] = Wknight;
    board[1][7] = Wbishop;
    board[1][8] = Wbishop;
    board[2][8] = Wking;

}

void BRAIN::printStartBoard(){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (board[i][j] != -1){
                if ((i + j) % 2 != 0){
                    table.setRect(i , j , chess_black_Pen , chess_black_Brush);
                }else{
                    table.setRect(i , j , chess_black_Pen , chess_white_Brush);
                }
                if (board[i][j] > 0 && board[i][j] < 10){
                    table.setPicture(i, j, ":img/white_" + QString::number(board[i][j]) + ".png");
                }
                if (board[i][j] > 10){
                    table.setPicture(i, j, ":img/black_" + QString::number(board[i][j] - 10) + ".png");
                }
            }
        }
    }
    QFont fnt;
    fnt.setPointSize(20);
    fnt.setItalic(true);
    fnt.setFamily("Temporarium");
    table.setText(0 , 8, fnt, "1");
    table.setText(0 , 7, fnt, "2");
    table.setText(0 , 6, fnt, "3");
    table.setText(0 , 5, fnt, "4");
    table.setText(9 , 4, fnt, "5");
    table.setText(9 , 3, fnt, "6");
    table.setText(9 , 2, fnt, "7");
    table.setText(9 , 1, fnt, "8");

    table.setText(1 , 9, fnt, "a");
    table.setText(2 , 9, fnt, "b");
    table.setText(3 , 9, fnt, "c");
    table.setText(4 , 9, fnt, "d");
    table.setText(5 , 0, fnt, "e");
    table.setText(6 , 0, fnt, "f");
    table.setText(7 , 0, fnt, "g");
    table.setText(8 , 0, fnt, "h");

}












