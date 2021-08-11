#include "brain.h"

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
}

// функция старта
void BRAIN::start(){
    redpen->setWidth(3); // толщина ручки
    MTable table(wnd);
    table.setSize(9, 9, 60, 60); // поле 8 на 8

    //разметка поля
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if ((i + j) >= 4 && (i + j) <= 10){
                if ((i + j) % 2 != 0){
                    table.setRectPos(i , j , chess_black_Pen , chess_black_Brush);
                }else{
                    table.setRectPos(i , j , chess_black_Pen , chess_white_Brush);
                }
            }
        }
    }
    table.setPicture(4, 1, ":/img/black_1.png");
    table.setPicture(5, 1, ":/img/black_1.png");
    table.setPicture(6, 1, ":/img/black_1.png");
    table.setPicture(6, 2, ":/img/black_1.png");
    table.setPicture(6, 3, ":/img/black_1.png");
    table.setPicture(4, 0, ":/img/black_2.png");
    table.setPicture(7, 3, ":/img/black_2.png");
    table.setPicture(5, 0, ":/img/black_3.png");
    table.setPicture(7, 2, ":/img/black_3.png");
    table.setPicture(7, 1, ":/img/black_4.png");
    table.setPicture(7, 0, ":/img/black_4.png");
    table.setPicture(6, 0, ":/img/black_6.png");

    table.setPicture(1, 4, ":/img/white_1.png");
    table.setPicture(1, 5, ":/img/white_1.png");
    table.setPicture(1, 6, ":/img/white_1.png");
    table.setPicture(2, 6, ":/img/white_1.png");
    table.setPicture(3, 6, ":/img/white_1.png");
    table.setPicture(0, 4, ":/img/white_2.png");
    table.setPicture(3, 7, ":/img/white_2.png");
    table.setPicture(0, 5, ":/img/white_3.png");
    table.setPicture(2, 7, ":/img/white_3.png");
    table.setPicture(0, 6, ":/img/white_4.png");
    table.setPicture(0, 7, ":/img/white_4.png");
    table.setPicture(1, 7, ":/img/white_6.png");

    QFont fnt;
    fnt.setPointSize(25);
    fnt.setItalic(true);
    fnt.setFamily("Calibri");
    table.setText(8 , 7, fnt, "1");
    table.setText(8 , 6, fnt, "2");
    table.setText(8 , 5, fnt, "3");
    table.setText(8 , 4, fnt, "4");
    table.setText(8 , 3, fnt, "5");
    table.setText(8 , 2, fnt, "6");
    table.setText(8 , 1, fnt, "7");
    table.setText(8 , 0, fnt, "8");

    table.setText(0 , 8, fnt, "a");
    table.setText(1 , 8, fnt, "b");
    table.setText(2 , 8, fnt, "c");
    table.setText(3 , 8, fnt, "d");
    table.setText(4 , 8, fnt, "e");
    table.setText(5 , 8, fnt, "f");
    table.setText(6 , 8, fnt, "g");
    table.setText(7 , 8, fnt, "h");

    // отрисовка (делать 1 раз, больше можно не прописывать, если не добавляются новые элементы)
    MButton btn;
    btn.CreateButton(10,10,100,100,"LOL");
    btn.CreateButton(100,100,100,100, "background-color: red;","LOL");
    btn.CreateButton(200,200,100,100,"LOL");
    btn.CreateButton(300,300,100,100,"LOL");

    //wnd->scene->addWidget(btn.CreateButton(10,10,100,100,"LOL"));

    wnd->addItem(btn.GetData());
    wnd->addItem(table.GetData());
    wnd->ResetScene();
}

