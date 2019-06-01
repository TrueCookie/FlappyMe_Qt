#include "obstacle.h"
#include "game.h"
#include <QTimer>
//#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
//#include <stdlib.h>

extern Game* game;

Obstacle::Obstacle(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    setPos(parent->scene()->width() + this->pixmap().width() ,rand()%300+300);

    setPixmap(QPixmap(":/sprites/Sprites/Enemy.png"));
    //setTransformOriginPoint(184, 185);
    //setRotation(180);

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Obstacle::move(){
    setPos(x()-5, y());
    if(pos().x() < -this->pixmap().width()){
        scene()->removeItem(this);
        delete this;
    }
}
