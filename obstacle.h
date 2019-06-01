#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Obstacle : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Obstacle(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // OBSTACLE_H
