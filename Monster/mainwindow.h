#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsObject>
#include <QVector>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Log(QString str);
    void showRect(QRect rct, QPen *pen, QBrush *brush);
    void showPicture(int x, int y, int w, int h, QString name);
    void ResetScene();
    void ClearSceneFull();
    int GraphicsHeight();
    int GraphicsWidth();

    void addItem(QVector<QGraphicsItem*> mnstr);
    void addItem(QVector<QWidget*> mnstr);

public slots:


private slots:

public:
    QGraphicsScene *scene;

private:
    Ui::MainWindow *ui;

    QVector<QVector<QGraphicsItem*>> scene_paint_item;
    QVector<QVector<QWidget*>> scene_paint_widget;

};
#endif // MAINWINDOW_H
