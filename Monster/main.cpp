#include "brain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;    
    w.showFullScreen();

    BRAIN brain(&w);
    brain.start();

    return a.exec();
}
