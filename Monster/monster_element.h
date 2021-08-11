#ifndef MONSTER_ELEMENT_H
#define MONSTER_ELEMENT_H

#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPushButton>
#include "mainwindow.h"

class Monster_Element
{
public:
    Monster_Element();
    Monster_Element(MainWindow* Prnt);
    void SetParent(MainWindow* Prnt);
    QVector<QGraphicsItem*> GetData();

protected:
    MainWindow* Parent;
    QVector<QGraphicsItem*> data;
};

class MTable : public Monster_Element{
public:
    using Monster_Element::Monster_Element;

    void setSize(int x = 1, int y = 1, int w = 20, int h = 20);
    void setPosition(int x, int y);
    void setAutoSize();
    void setRectStyle(QPen *pen, QBrush *brush);
    void setDeleteCell(int x, int y); // не реализована

    void setRectPos(int x, int y, QPen *pen, QBrush *brush);
    void setPicture(int x, int y, QString str);
    void setText(int x, int y, QFont fnt, QString str);

private:
    int cell_x = 1;
    int cell_y = 1;
    int cell_height = 20;
    int cell_widht = 20;
    int start_x = 0;
    int start_y = 0;
};

class MText : public Monster_Element{
public:
    using Monster_Element::Monster_Element;
    MText(QFont fnt);
    MText(QFont fnt , MainWindow* Prnt);

    void SetFont(QFont fnt);
    void SetFont(int size, bool bold, bool italic, QString family);
    void addText(int x, int y, QString str);

private:
    QFont font;
};

class MButton : public Monster_Element{
public:
    using Monster_Element::Monster_Element;
    QString Style_Sheet = "color: red;";

    QWidget* CreateButton(int x, int y, int w, int h, QString name);
    QWidget* CreateButton(int x, int y, int w, int h, QString style,QString name);
    QVector<QWidget*> GetData();

private:
    QVector<QWidget*> data_wdg;
};

#endif // MONSTER_ELEMENT_H
