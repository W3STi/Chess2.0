#include "monster_element.h"

Monster_Element::Monster_Element()
{

}

Monster_Element::Monster_Element(MainWindow* prnt){
    SetParent(prnt);
}

void Monster_Element::SetParent(MainWindow *Prnt){
    Parent = Prnt;
}

QVector<QGraphicsItem*> Monster_Element::GetData(){
    return data;
}


void MTable::setSize(int x, int y, int w, int h){
    cell_x = x;
    cell_y = y;
    data.resize(x * y);

    cell_widht = w;
    cell_height = h;
}

void MTable::setPosition(int x, int y){
    start_x = x;
    start_y = y;
}

void MTable::setAutoSize(){
    int razmer_w = Parent->GraphicsWidth();
    int razmer_h = Parent->GraphicsHeight();
    //if (razmer_h < razmer_w){
    //    razmer_w = razmer_h;
    //}

    razmer_w = razmer_w - razmer_w/50; // уменьшаем размер на 2% для удобства отображения
    razmer_h = razmer_h - razmer_h/50;

    cell_widht = razmer_w / cell_x;
    cell_height = razmer_h / cell_y;
}

void MTable::setRectStyle(QPen *pen, QBrush *brush){
    for(int i = 0; i < cell_x; i++){
        for (int j = 0; j < cell_y; j++){
            setRectPos(i , j , pen, brush);
        }
    }
}

void MTable::setRectPos(int x, int y, QPen *pen, QBrush *brush){
    data[x * y + y] = Parent->scene->addRect(QRect(start_x + x * cell_widht, start_y + y * cell_height ,
                                                    cell_widht, cell_height), *pen, *brush);
}

QPen transparentPen(Qt::transparent);
QBrush transparentBrush(Qt::white, Qt::SolidPattern);
void MTable::setDeleteCell(int x, int y){
    data[x * y + y] = Parent->scene->addRect(QRect(start_x + x * cell_widht, start_y + y * cell_height ,
                                                    cell_widht, cell_height), transparentPen, transparentBrush);
}

void MTable::setPicture(int x, int y, QString str){
    QPixmap pic(str);
    pic = pic.scaled(QSize(cell_widht, cell_height), Qt::IgnoreAspectRatio);
    data[x * y + y] = Parent->scene->addPixmap(pic);
    data[x * y + y]->setPos(start_x + x * cell_widht, start_y + y * cell_height);
}

void MTable::setText(int x, int y, QFont fnt, QString str){
    data[x * y + y] = Parent->scene->addText(str, fnt);
    QFontMetrics fm(fnt);
    int startX = (cell_widht - fm.width(str)) / 2;
    int startY = (cell_height - fm.height()) / 2;
    data[x * y + y]->setPos(startX + start_x + x * cell_widht, startY + start_y + y * cell_height);
}


MText::MText(QFont fnt){
    SetFont(fnt);
}

MText::MText(QFont fnt, MainWindow* Prnt){
    SetFont(fnt);
    SetParent(Prnt);
}

void MText::SetFont(QFont fnt){
    font = fnt;
}

void MText::SetFont(int size, bool bold, bool italic, QString family){
    font.setPointSize(size);
    font.setBold(bold);
    font.setItalic(italic);
    font.setFamily(family);
}

void MText::addText(int x, int y, QString str){
    data.push_back(Parent->scene->addText(str, font));
    data[data.size() - 1]->setPos(x, y);
}

QWidget* MButton::CreateButton(int x, int y, int w, int h, QString style, QString name){
    QWidget* btn = CreateButton(x, y, w, h, name);
    btn->setStyleSheet(style);
    return btn;
}

QWidget* MButton::CreateButton(int x, int y, int w, int h, QString name){
    QPushButton* btn = new QPushButton(name);
    btn->setGeometry(x, y , w, h);
    btn->setStyleSheet(Style_Sheet);
    data_wdg.push_back(btn);
    return btn;
}

QVector<QWidget*> MButton::GetData(){
    return data_wdg;
}
