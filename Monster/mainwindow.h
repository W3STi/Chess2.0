#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QCursor>
#include <QDebug>
#include <QMouseEvent>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QWidgetAction>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Scene : public QGraphicsScene {
    Q_OBJECT
public:
    using QGraphicsScene::QGraphicsScene;
    //explicit Scene(QObject *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void SceneKeyPress(QPointF);
};

class MainWindow : public QMainWindow                                   // класс главного окна
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);                              // хз-конструктор
    ~MainWindow();

                               // функция записи информации в statusBar
    void showRect(QRect rct, QPen *pen, QBrush *brush);                 // отрисовать квавдрат
    void showPicture(int x, int y, int w, int h, QString name);         // отрисовать изображение в заданном месте с заданными размерами
    void ResetScene();                                                  // отрисовать сцену из буфера
    void ClearSceneFull();                                              // полностью чистит сцену и буфер
    int GraphicsHeight();                                               // возвращает высоту графического окна
    int GraphicsWidth();                                                // возвращает ширину графического окна

    void addItem(QVector<QGraphicsItem*> mnstr);                        // добавляет графические элементы в буфер
    void addItem(QVector<QWidget*> mnstr);                              // (перегрузка) добавляет виджеты в буфер

    void setTopToolBar(QToolBar* toolbar);
    void setBottomToolBar(QToolBar* toolbar);
    void setLeftToolBar(QToolBar* toolbar);
    void setRightToolBar(QToolBar* toolbar);

public slots:
    void Log(QString str);

private slots:

signals:
    void KeyPress(QPointF);

public:
    Scene *scene;    // графическая сцена

private:
    Ui::MainWindow *ui;                                                 // окно приложения

    QVector<QVector<QGraphicsItem*>> scene_paint_item;                  // буфер графических элементов
    QVector<QVector<QWidget*>> scene_paint_widget;                      // буфер виджетов

};
#endif // MAINWINDOW_H
