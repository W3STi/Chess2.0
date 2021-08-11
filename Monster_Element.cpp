class Monster_Element                                               
// класс общий (для наследования)
{
    Monster_Element(); 
    // конструктор по умолчанию

    Monster_Element(MainWindow* Prnt);                              
    // конструктор 
    // вход которого подаётся родительское окно в
    // котором будет использоваться данный класс

    void SetParent(MainWindow* Prnt);                               
    // установка родительского окна
    // - на вход подается родительское окно класса MainWindow

    QVector<QGraphicsItem*> GetData();                              
    // возвращает данные элемента
};


class MTable : public Monster_Element                    
// наследный класс с таблицами в который можно 
// добавлять множество других элементов
{
    void setSize(int x = 1, int y = 1, int w = 20, int h = 20);     
    // задание размеров таблицы
    // на вход подаётся:
    // - X и Y размер в кол-ве ячеек таблицы
    // - W и H размер в пикселях 1 ячейки

    void setPosition(int x, int y);                                 
    // задание положения левого верхнего пикселя таблицы

    void setAutoSize();                                             
    // автоматическое задание размеров ячейки таблицы
    // зависит от размеров графического окна

    void setRectStyle(QPen *pen, QBrush *brush);                    
    // заполняет всю таблицу квадратами с одним и тем же стилем
    // на вход подаётся ручка и кисть

    void setDeleteCell(int x, int y);                               
    // удаляет элемент таблицы с координатами X и Y (закрашивает белым)

    void setRect(int x, int y, QPen *pen, QBrush *brush);        
    // добавить квадрат по координатам ячеек в таблице
    // на вход подаются:
    // - координаты ячейки X и Y
    // - ручка и кисть

    void setPicture(int x, int y, QString str);                     
    // добавить картинку по координатам ячеек в таблице
    // на вход подаются:
    // - координаты ячейки X и Y
    // - ссылка на картинку

    void setText(int x, int y, QFont fnt, QString str);             
    // добавить текст по координатам ячеек в таблице
    // на вход подаются:
    // - координаты ячейки X и Y
    // - стиль текста и сам текст
};


class MText : public Monster_Element{                               
// наследник класс с текстом
// для вывода текста в графическом окне

public:
    MText(QFont fnt);                                               
    // конструктор с входным параметром стиля текста

    MText(QFont fnt , MainWindow* Prnt);                            
    // конструктор с входными параметрами: стиль текста и родительское окно

    void SetFont(QFont fnt);                                        
    // задать стиль текста
    // на вход подаётся стиль текста

    void SetFont(int size, bool bold = false, bool italic = false, QString family = "Calibri"); 
    // (перегрузка)задать стиль текста, через конкретные параметры
    // на вход подаются параметры присущие стилю теста

    void addText(int x, int y, QString str);                        
    // добавить элемент с текстом
    // на вход подаются:
    // - координаты в пикселях
    // - текст
};

class MButton : public Monster_Element{                             
// наследник класс с кнопками
// CreateButton возвращает указатель на кнопку,
// тем самым можно сделать слот и отслеживать нажатие

public:
    QString Style_Sheet = "";                                       
    // CSS стиль кнопок

    QWidget* CreateButton(int x, int y, int w, int h, QString name); 
    // создать кнопку
    // на вход подаются:
    // - X и Y координаты кнопки в пикселях
    // - W и H размер кнопки
    // - и название

    QWidget* CreateButton(int x, int y, int w, int h, QString style,QString name); 
    //(перегрузка) создать кнопку со своим стилем
    // на вход подаются:
    // - X и Y координаты кнопки в пикселях
    // - W и H размер кнопки
    // - CSS стиль и название кнопки

    QVector<QWidget*> GetData();                                    
    // (перегрузка) возврат данных
};
