//
// Created by exort on 17.11.2020.
//

#include "Heart.h"
#include "Game.h"




extern Game * game;

Heart::Heart(): QObject(), QGraphicsPixmapItem(){
    int random = (rand() % 400)+200;
    setPos(random,80);


    setPixmap(QPixmap("../Sources/Pictures/heart.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30);
}

void Heart::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i=0; i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(this);
            delete this;
            game->health->increase();
            return;
        }
    }

    setPos(x(),y()+5);
    if(pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }


}