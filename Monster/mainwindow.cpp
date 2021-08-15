#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene_paint_item.resize(1);
    scene_paint_widget.resize(1);
    scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(QRect(9, 9, 980, 741));
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::Log(QString str){
    ui->statusbar->showMessage(str);
}

void MainWindow::showRect(QRect rct, QPen* pen, QBrush* brush){
    scene_paint_item[0].push_back(scene->addRect(rct, *pen, *brush));
}

void MainWindow::showPicture(int x, int y, int w, int h, QString name){
    QPixmap pic(name);
    pic = pic.scaled(QSize(w, h), Qt::IgnoreAspectRatio);
    scene_paint_item[0].push_back(scene->addPixmap(pic));
    scene_paint_item[0][scene_paint_item[0].size() - 1] -> setPos(x, y);
}

void MainWindow::ResetScene(){
    for (int i = 0; i < scene_paint_item.size(); i++){
        for (int j = 0; j < scene_paint_item[i].size(); j++){
            scene->addItem(scene_paint_item[i][j]);
        }
    }
    for (int i = 0; i < scene_paint_widget.size(); i++){
        for (int j = 0; j < scene_paint_widget[i].size(); j++){
            scene->addWidget(scene_paint_widget[i][j]);
        }
    }
}

void MainWindow::ClearSceneFull(){
    scene->clear();
    scene_paint_item.clear();
}

int MainWindow::GraphicsHeight(){
    return ui->graphicsView->height();
}

int MainWindow::GraphicsWidth(){
    return ui->graphicsView->width();
}

void MainWindow::addItem(QVector<QGraphicsItem*> mnstr){
    scene_paint_item.push_back(mnstr);
}

void MainWindow::addItem(QVector<QWidget*> mnstr){
    scene_paint_widget.push_back(mnstr);
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    qDebug() << "real pos = " << event->pos();
    qDebug() << "relative pos = " << event->pos() - ui->graphicsView->geometry().topLeft();
    Q_UNUSED(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
}

