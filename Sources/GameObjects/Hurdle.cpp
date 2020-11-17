//
// Created by exort on 22.10.2020.
//

#include "Sources/GameObjects/Hurdle.h"
#include "Game.h"
#include <Sources/GameObjects/Player.h>

#include <QList>

extern Game * game;

Hurdle::Hurdle(): QObject(), QGraphicsPixmapItem(){
    int random = (rand() % 300)+200;
    setPos(random,0);


    setPixmap(QPixmap("../Sources/Pictures/hole.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Hurdle::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i=0; i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(this);
            delete this;
            game->health->decrease();
            if(game->health->getHealth() == 0)
                exit(-1);
            else
                return;
        }
    }


    setPos(x(),y()+5);
    if(pos().y() > 600){
        game->score->increase();
        scene()->removeItem(this);
        delete this;
    }


}