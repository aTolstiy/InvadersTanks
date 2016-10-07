#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include <typeinfo>

Bullet::Bullet()
{
    //Drew the rect
    setRect(0,0, 25, 25);

    //Connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet collides with enemy - destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //remove both of them
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both of them
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //move bullet up
    setPos(x(), y()-10);

    if(pos().y() < 0 )
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";
    }

}

