#ifndef BULLET
#define BULLET

#include <QObject>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Bullet();
    public slots:
        void move();
};


#endif // BULLET

