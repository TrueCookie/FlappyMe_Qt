#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,360, 640);
    
    setBackgroundBrush(QBrush(QImage(":/sprites/background.png")));

    QGraphicsView *view = new QGraphicsView(scene);

    view->show();
    view->setFixedSize(360, 640);

    player = new Player();
    player->setPixmap(QPixmap(":/sprites/bird.png"));
    player->setPos(20, parent->window()->height()/2);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    
    score = new Score();
    scene->addItem(score);
    
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
    
    //add some rhytmic music
    //QMediaPlayer *music = new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/sounds/BGMusic.mp3"));
    //music->play();
}
