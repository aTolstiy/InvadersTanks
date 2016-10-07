#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> //rand() -> really large int

Enemy::Enemy()
{
    //Drew the rect
    setRect(0,0, 100, 100);
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    //Connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+5);

    if(pos().y() > scene()->width())
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy reached bottom of scene";
    }

}

