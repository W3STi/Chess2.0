#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsObject>
#include <QVector>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow                                   // класс главного окна
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);                              // хз-конструктор
    ~MainWindow();

    void Log(QString str);                                              // функция записи информации в statusBar
    void showRect(QRect rct, QPen *pen, QBrush *brush);                 // отрисовать квавдрат
    void showPicture(int x, int y, int w, int h, QString name);         // отрисовать изображение в заданном месте с заданными размерами
    void ResetScene();                                                  // отрисовать сцену из буфера
    void ClearSceneFull();                                              // полностью чистит сцену и буфер
    int GraphicsHeight();                                               // возвращает высоту графического окна
    int GraphicsWidth();                                                // возвращает ширину графического окна

    void addItem(QVector<QGraphicsItem*> mnstr);                        // добавляет графические элементы в буфер
    void addItem(QVector<QWidget*> mnstr);                              // (перегрузка) добавляет виджеты в буфер

public slots:


private slots:

public:
    QGraphicsScene *scene;                                              // графическая сцена

private:
    Ui::MainWindow *ui;                                                 // окно приложения

    QVector<QVector<QGraphicsItem*>> scene_paint_item;                  // буфер графических элементов
    QVector<QVector<QWidget*>> scene_paint_widget;                      // буфер виджетов

};
#endif // MAINWINDOW_H
