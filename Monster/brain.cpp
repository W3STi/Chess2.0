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
QBrush *chess_black_Brush =                      new QBrush(chess_black, Qt::SolidPattern);

BRAIN::BRAIN(){

}

BRAIN::BRAIN(MainWindow* mainwind)
{
    wnd = mainwind;
    table.SetParent(wnd);
    connect(wnd, SIGNAL(KeyPress(QPointF)), this, SLOT(read_data(QPointF)));
}

// функция старта
void BRAIN::start(){
    toolbar = createToolBar();
    wnd->setTopToolBar(toolbar);

    redpen->setWidth(3); // толщина ручки
    wnd->addItem(table.GetData());
    wnd->ResetScene();
    table.setSize(10, 10, 80, 80); // поле 8 на 8
    table.setAutoPosition();
    startPosition();
    printBoard();

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

void BRAIN::printBoard(){
    wnd->ClearSceneFull();
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (board[i][j] != -1){
                if ((i + j) % 2 != 0){
                    table.setRect(i , j , chess_black_Pen , chess_black_Brush);
                }else{
                    table.setRect(i , j , chess_black_Pen , chess_white_Brush);
                }
                if (board[i][j] > 0 && board[i][j] < 10){
                    table.setPicture(i, j, ":img/figures/" + chess_style[Style] + "/w" + chess_char[board[i][j] - 1] + ".png");
                }
                if (board[i][j] > 10){
                    table.setPicture(i, j, ":img/figures/" + chess_style[Style] + "/b" + chess_char[board[i][j] - 11] + ".png");
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

QToolBar* BRAIN::createToolBar(){
    QToolBar* ptb = new QToolBar("Linker ToolBar");

    QPushButton *but = new QPushButton(wnd);
    //but->show();

    QPixmap pixmap(":/img/figures/" + chess_style[Style] + "/wN.png");
    but->setIcon(QIcon(QPixmap(":/img/figures/" + chess_style[Style] + "/wN.png")));
    but->setIconSize(pixmap.rect().size() / 1.5);

    QMenu *menu = new QMenu();

    QWidgetAction *labelAct;
    QLabel *label;

    for (int i = 0; i < chess_style.size(); i++){
        labelAct = new QWidgetAction(menu);
        label = new QLabel(chess_style[i] , menu);
        QPixmap mypix (":/img/figures/" + chess_style[i] + "/wN.png");
        label->setText(chess_style[i]);
        label->setPixmap(mypix);
        labelAct->setDefaultWidget(label);
        _actionToInt.insert(labelAct, i);
        menu->addAction(labelAct);
    }

    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(changeStyle(QAction*)));
    but->setMenu(menu);
    ptb->addWidget(but);

    return ptb;
}

void BRAIN::changeStyle(QAction* action){
    if (action && _actionToInt.contains(action)) {
        Style = _actionToInt.value(action);
    }
    printBoard();

    /*
    QPixmap pixmap(":/img/figures/" + chess_style[Style] + "/wN.png");
    but->setIcon(QIcon(":/img/figures/" + chess_style[Style] + "/wN.png"));
    but->setIconSize(pixmap.rect().size() / 1.5);
    */
    //but->setStyleSheet( "*{border-image: url(:/img/figures/" + chess_style[Style] + "/wN.png);}");
}

void BRAIN::read_data(QPointF kekW){
    kekW = table.SeachCell(kekW);
    wnd->Log(QString::number(kekW.x()) + " " + QString::number(kekW.y()));
}

bool BRAIN::checkForRookInFront(int &xCoord, int &yCoord,
                           int &xMove, int &yMove, QVector<QVector<int>>& board, int &temp){
    if((xMove != xCoord) && (yMove == yCoord)){
        temp = abs(xMove - xCoord);
        for(int i = xCoord; i < temp - 1; ++i){
            if(board[xCoord][yCoord] != voidcell){
                return 0;
            }
        }
    }
    else if ((xMove == xCoord) && (yMove != yCoord)){
        temp = abs(yMove - yCoord);
        for(int i = yCoord; i < temp - 1; ++i){
            if(board[xCoord][yCoord] != voidcell){
                return 0;
            }
        }
    }
    return 1;
}

bool BRAIN::checkForBishopInFront(int &xCoord, int &yCoord,
                           int &xMove, QVector<QVector<int>>& board, int &flag){
    if(xCoord > xMove){
    for(int i = xCoord - 1, j = yCoord + flag; i > xMove; --i, j += flag){
        if(board[i][j] != voidcell) {
            return 0;
            break;
        }
    }
    return 1;
    }else if(xCoord < xMove){
        for(int i = xCoord + 1, j = yCoord - flag; i < xMove; ++i, j -= flag){
            if(board[i][j] != voidcell) {
                return 0;
                break;
            }
        }
        return 1;
    }
    return 0;
}

void BRAIN::searchMove(int &xCoord, int &yCoord,
                int &xMove, int &yMove, QVector<QVector<int>>& board){
    int temp = 0, flag;
    switch(board[xCoord][yCoord]){
        case Wpawn:
        //допилить проверку с королем
        //проверка на ход в пустую клетку
            if(board[xMove][yMove] == voidcell && (((xMove == ++xCoord) && (yMove == yCoord))||
                    ((xMove == xCoord) && (yMove == --yCoord)))){
                //Проверка на поля превращения
                if((yMove == 1)||(xMove == 8)){
                    //превращение пешки в выбранную фигуру
                }else{
                    //предыдущая клетка очищается
                    board[xCoord][yCoord] = voidcell;
                    //Пешка идет на новые координаты
                    board[xMove][yMove] = Wpawn;
                }
            }
            //Проверка на удар пешкой
            else if((board[xMove][yMove] > 10)
                     && (((xMove == ++xCoord) && (yMove == --yCoord))
                     ||((xMove == --xCoord) && (yMove == --yCoord)))){
                //delete figure
                //предыдущая клетка очищается
                board[xCoord][yCoord] = voidcell;
                //Проверка на превращения при ударе
                if((yMove == 1)||(xMove == 8)){
                    //превращение пешки в выбранную фигуру
                    //Иначе пешка идет на новые координаты
            }else board[xMove][yMove] = Wpawn;
    }
            break;

         case Wrook:
            if((board[xMove][yMove] == voidcell) &&
               (checkForRookInFront(xCoord, yCoord, xMove, yMove, board, temp))){
                board[xCoord][yCoord] = voidcell;
                board[xMove][yMove] = Wrook;
            }
            //Проверка на взятие фигуры
            else if ((checkForRookInFront(xCoord, yCoord, xMove, yMove, board, temp)) &&
                     (board[xMove][yMove] > 10)){
                board[xCoord][yCoord] = voidcell;
                //delete figure
            }
            break;

         case Wknight:
        if(board[xMove][yMove] == voidcell && (((xMove == xCoord + 2) && ((yMove == --yCoord) || (yMove == ++yCoord))) ||
                                               ((xMove == xCoord - 2) && ((yMove == --yCoord) || (yMove == ++yCoord))) ||
                                               ((yMove == yCoord + 2) && ((xMove == --xCoord) || (xMove == ++xCoord))) ||
                                               ((yMove == yCoord - 2) && ((xMove == --xCoord) || (xMove == ++xCoord))))){
            board[xCoord][yCoord] = voidcell;
            board[xMove][yMove] = Wknight;
        }
        //Проверка на взятие фигуры
        else if ((board[xMove][yMove] > 10) && (((xMove == xCoord + 2) && ((yMove == --yCoord) || (yMove == ++yCoord)))||
                                                ((xMove == xCoord - 2) && ((yMove == --yCoord) || (yMove == ++yCoord))) ||
                                                ((yMove == yCoord + 2) && ((xMove == --xCoord) || (xMove == ++xCoord))) ||
                                                ((yMove == yCoord - 2) && ((xMove == --xCoord) || (xMove == ++xCoord))))){
            board[xCoord][yCoord] = voidcell;
            //delete figure
        }

            break;

        case Wbishop:
        if(board[xMove][yMove] == voidcell){
            if((xMove + yMove) == (xCoord + yCoord)){
                flag = 1;
                if(checkForBishopInFront(xCoord, yCoord, xMove, board, flag)){
                    board[xCoord][yCoord] = voidcell;
                    board[xMove][yMove] = Wbishop;
                }
            }else if ((9 - yMove + xMove) == (9 - yCoord + xCoord)){
                flag = -1;
                if(checkForBishopInFront(xCoord, yCoord, xMove, board, flag)){
                    board[xCoord][yCoord] = voidcell;
                    //удалить фигуру
                }
            }
        }
        //Проверка на взятие фигуры
        else if (board[xMove][yMove] > 10){
                 if((xMove + yMove) == (xCoord + yCoord)){
                 flag = 1;
                 if(checkForBishopInFront(xCoord, yCoord, xMove, board, flag)){
                     board[xCoord][yCoord] = voidcell;
                     //удалить фигуру
                 }
             }else if ((9 - yMove + xMove) == (9 - yCoord + xCoord)){
                 flag = -1;
                 if(checkForBishopInFront(xCoord, yCoord, xMove, board, flag)){
                     board[xCoord][yCoord] = voidcell;
                     //удалить фигуру
                 }
             }
        }
        break;
    //В функции добавить удаление фигур, при их взятии, и выбор фигуры при превращении пешки.
    //И сделать проверку хода на короля и проверку на открытие короля при ходе
    }
}

void BRAIN::attackFigures(QVector<QVector<int>>& board, QVector<QVector<char>>& attack){
    int temp = 0;
    char c = 2;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            switch(board[i][j]){
                case Bpawn:
                    if(board[i + 1][j + 1] != wall) attack[i + 1][j + 1] = 1;
                    if(board[i - 1][j + 1] != wall) attack[i - 1][j + 1] = 1;
                break;
                case Brook:
                    if(attack[i][j] != 1) temp = 0;
                    else temp = 1;
                    for(int l = 1; l < 9; ++l){
                        if(board[i][l] != wall) attack[i][l] = 1;
                        if(board[l][j] != wall) attack[l][j] = 1;
                    }
                    attack[i][j] = temp;
                    break;
            /*case Brook:
                temp = 1;
                while(attack[i + temp][j] != wall){
                    if(board[i + temp][j] != voidcell) attack[i + temp][j] = 2;
                    else attack[i + temp][j] = 1;
                    temp++;
                }
                temp = 1;
                while(attack[i - temp][j] != wall){
                    if(board[i][j] != wall) attack[i][l] = 1;
                    temp++;
                }
                temp = 1;
                while(attack[i + temp][j] != wall){
                    if(board[i][j] != wall) attack[i][l] = 1;
                    temp++;
                }
                temp = 1;
                while(attack[i + temp][j] != wall){
                    if(board[i][j] != wall) attack[i][l] = 1;
                    temp++;
                }
                attack[i][j] = temp;
                break;*/
            case Bknight:
                if((i + j != 12) && (i != 8)){
                    if(board[i + 2][j + 1] != wall) attack[i + 2][j + 1] = 1;
                    if(board[i + 2][j - 1] != wall) attack[i + 2][j - 1] = 1;
                }
                if((i + j != 6) && (i != 1)){
                    if(board[i - 2][j + 1] != wall) attack[i - 2][j + 1] = 1;
                    if(board[i - 2][j - 1] != wall) attack[i - 2][j - 1] = 1;
                }
                if((i + j != 6) && (j != 1)){
                    if(board[i + 1][j + 2] != wall) attack[i + 1][j + 2] = 1;
                    if(board[i - 1][j + 2] != wall) attack[i - 1][j + 2] = 1;
                }
                if((i + j != 12) && (j != 8)){
                    if(board[i + 1][j + 2] != wall) attack[i + 1][j + 2] = 1;
                    if(board[i - 1][j + 2] != wall) attack[i - 1][j + 2] = 1;
                }
            break;
            case Bbishop:
                if(attack[i][j] != 1) temp = 0;
                else temp = 1;
                if(i + j == 6){
                    for(int k = 1, l = 5; k <= 5; ++k, --l) attack[k][l] = 1;
                    attack[i + 1][j + 1] = 1;
                    attack[i + 2][j + 2] = 1;
                    attack[i + 3][j + 3] = 1;
                }else if(i + j == 7){
                    for(int k = 1, l = 6; k <= 6; ++k, --l) attack[k][l] = 1;
                    attack[i + 1][j + 1] = 1;
                    attack[i + 2][j + 2] = 1;
                }else if(i + j == 8){
                    for(int k = 1, l = 7; k <= 7; ++k, --l) attack[k][l] = 1;
                    if(i == 1 || i == 7) attack[i + 1][j + 1] = 1;
                    else{
                    attack[i - 1][j - 1] = 1;
                    attack[i + 1][j + 1] = 1;
                    attack[i + 2][j + 2] = 1;
                    }
                }else if(i + j == 9){
                    for(int k = 1, l = 8; k <= 8; ++k, --l) attack[k][l] = 1;
                    if(i != 1 && i != 8){
                    attack[i - 1][j - 1] = 1;
                    attack[i + 1][j + 1] = 1;
                    }
                }else if(i + j == 10){
                    for(int k = 2, l = 8; k <= 8; ++k, --l) attack[k][l] = 1;
                    if(i == 2 || i == 8) attack[i - 1][j - 1] = 1;
                    else{
                    attack[i - 1][j - 1] = 1;
                    attack[i - 2][j - 2] = 1;
                    attack[i + 1][j + 1] = 1;
                    }
                }else if(i + j == 11){
                    for(int k = 3, l = 8; k <= 8; ++k, --l) attack[k][l] = 1;
                    attack[i - 1][j - 1] = 1;
                    attack[i - 2][j - 2] = 1;
                }else if(i + j == 12){
                    for(int k = 4, l = 8; k <= 8; ++k, --l) attack[k][l] = 1;
                    attack[i - 1][j - 1] = 1;
                    attack[i - 2][j - 2] = 1;
                    attack[i - 3][j - 3] = 1;
                }
                attack[i][j] = temp;
            break;
            case Bking:
                if(attack[i + 1][j] != wall) attack[i + 1][j] = 1;
                if(attack[i + 1][j - 1] != wall) attack[i + 1][j - 1] = 1;
                if(attack[i + 1][j + 1] != wall) attack[i + 1][j + 1] = 1;
                if(attack[i - 1][j] != wall) attack[i - 1][j] = 1;
                if(attack[i - 1][j + 1] != wall) attack[i - 1][j + 1] = 1;
                if(attack[i - 1][j - 1] != wall) attack[i - 1][j - 1] = 1;
                if(attack[i][j - 1] != wall) attack[i][j - 1] = 1;
                if(attack[i][j + 1] != wall) attack[i][j + 1] = 1;
            break;
            }
        }
    }

}

