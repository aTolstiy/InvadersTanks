#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //Create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    //Add item to the scene
    scene->addItem(player);

    //Make an item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0,0, 800, 600);

    player->setPos(view->width()/2, view->height()-player->rect().height());

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
