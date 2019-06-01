#include "obstacle.h"
#include "game.h"
#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTime>

extern Game* game;

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent){
    setPixmap(QPixmap(":/sprites/bird.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        jump();
    }
}

void Player::spawn(){
    Obstacle *obstacle = new Obstacle();
    scene()->addItem(obstacle);
}

void Player::jump(){
    //TODO: add physics for jump

    QTime* dTimer = new QTime();
    static int delta = dTimer->currentTime().msec();
    delta = dTimer->currentTime().msec() - delta; 
    if(delta < 0){
        //delta = dTimer->;
    }
    if(this->y() < (scene()->height() - this->pixmap().height())){
        setPos(x(), y()+delta);
    }else{
        //GAME_OVER
    }

}
