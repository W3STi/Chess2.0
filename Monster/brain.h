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

public:
    BRAIN();
    BRAIN(MainWindow* mainwind);

    void start();

};

#endif // BRAIN_H
