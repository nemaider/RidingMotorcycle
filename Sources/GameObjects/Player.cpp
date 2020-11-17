//
// Created by exort on 20.10.2020.
//

#include "Player.h"
#include "Hurdle.h"
#include "Heart.h"

Player::Player(): QObject(), QGraphicsPixmapItem(){

    setPos(400,500);
    setPixmap(QPixmap("../Sources/Pictures/motorcycle.png"));


}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 200)
            setPos(x()-10,y());
    } else if (event->key() == Qt::Key_Right){
        if(pos().x() < 600)
            setPos(x()+10,y());
    } else if (event->key() == Qt::Key_Up){
        if(pos().y() > 80)
            setPos(x(),y()-10);
    } else if (event->key() == Qt::Key_Down){
        if(pos().y() < 500)
            setPos(x(),y()+10);
    } else if (event->key() == Qt::Key_Space){
        if(pos().y() > 80)
            setPos(x(),y()-20);
    }
}

void Player::spawnHurdle() {
    Hurdle * hurdle = new Hurdle();
    scene()->addItem(hurdle);
}

void Player::spawnHeart() {
    Heart * heart = new Heart();
    scene()->addItem(heart);
}
