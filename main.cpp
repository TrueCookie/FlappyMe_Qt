#include "mainwindow.h"
#include "game.h"
#include <QApplication>

static Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    
    game = new Game();
    //MainWindow w;
    //w.show();
    game->show();

    return a.exec();
}
