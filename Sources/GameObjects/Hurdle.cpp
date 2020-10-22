//
// Created by exort on 22.10.2020.
//

#include "Hurdle.h"


Hurdle::Hurdle(): QObject(), QGraphicsRectItem(){
    int random = (rand() % 300)+200;
    setPos(random,0);

    setRect(0,0,50,50);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Hurdle::move() {
    setPos(x(),y()+5);
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }


}