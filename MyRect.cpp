#include "MyRect.h"
#include "Bullet.h"
#include <QDebug>
#include <QGraphicsScene>
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + this->rect().width() < scene()->width())
        {
            setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        if(pos().x() + this->rect().height() < scene()->height())
        {
            setPos(x(), y()+10);
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
