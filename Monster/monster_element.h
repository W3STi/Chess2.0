#ifndef MONSTER_ELEMENT_H
#define MONSTER_ELEMENT_H

#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPushButton>
#include "mainwindow.h"

class Monster_Element                                               // класс общий (для наследования)
{
public:
    Monster_Element();                                              // конструктор по умолчанию
    Monster_Element(MainWindow* Prnt);                              // конструктор на вход которого подаётся родительское окно в котором будет использоваться данный класс
    void SetParent(MainWindow* Prnt);                               // установка родительского окна, если оно до этого не было установлено
    QVector<QGraphicsItem*> GetData();                              // возвращает данные элемента

protected:
    MainWindow* Parent;                                             // родительское окно типа MainWindow
    QVector<QGraphicsItem*> data;                                   // вектор с данными
};


class MTable : public Monster_Element{                              // наследный класс с таблицами
public:
    using Monster_Element::Monster_Element;                         // перенос конструкторов из родительского класса

    void setSize(int x = 1, int y = 1, int w = 20, int h = 20);     // задание размеров таблицы
    void setPosition(int x, int y);                                 // задание положения левого верхнего пикселя таблицы
    void setAutoPosition();
    void setAutoSize();                                             // автоматическое задание размеров
    void setRectStyle(QPen *pen, QBrush *brush);                    // заполняет всю таблицу квадратами с одним и тем же стилем
    void setDeleteCell(int x, int y);                               // удаляет элемент таблицы (закрашивает белым)

    void setRect(int x, int y, QPen *pen, QBrush *brush);        // добавить квадрат по координатам ячеек в таблице
    void setPicture(int x, int y, QString str);                     // добавить картинку по координатам ячеек в таблице
    void setText(int x, int y, QFont fnt, QString str);             // добавить текст по координатам ячеек в таблице

private:
    int cell_x = 1;                                                 // кол-во клеток в ширину
    int cell_y = 1;                                                 // кол-во клеток в длину
    int cell_height = 20;                                           // высота 1 клетки в пикселях
    int cell_widht = 20;                                            // ширина 1 клетки в пикселях
    int start_x = 0;                                                // стартовая позиция самый левый пиксель
    int start_y = 0;                                                // стартовая позиция самый верхний пиксель
};


class MText : public Monster_Element{                               // наследник класс с текстом
public:
    using Monster_Element::Monster_Element;                         // перенос конструкторов из родительскоого класса

    MText(QFont fnt);                                               // конструктор с входным параметром стиля текста
    MText(QFont fnt , MainWindow* Prnt);                            // конструктор с входными параметрами: стиль текста и родительское окно

    void SetFont(QFont fnt);                                        // задать стиль текста
    void SetFont(int size, bool bold = false, bool italic = false, QString family = "Temporarium"); // (перегрузка)задать стиль текста, через конкретные параметры
    void addText(int x, int y, QString str);                        // добавить элемент с текстом

private:
    QFont font;                                                     // стиль текста
};

class MButton : public Monster_Element{                             // наследник класс с кнопками
public:
    using Monster_Element::Monster_Element;                         // перенос конструкторов
    QString Style_Sheet = "";                                       // стиль кнопок

    QWidget* CreateButton(int x, int y, int w, int h, QString name); // создать кнопку
    QWidget* CreateButton(int x, int y, int w, int h, QString style,QString name); // (перегрузка) создать кнопку со своим стилем
    QVector<QWidget*> GetData();                                    // (перегрузка) возврат данных

private:
    QVector<QWidget*> data_wdg;                                     // данные
};

#endif // MONSTER_ELEMENT_H
