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
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if(pos().x() > 180)
            setPos(x()-10,y());
    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D ){
        if(pos().x() < 620)
            setPos(x()+10,y());
    } else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W ){
        if(pos().y() > 0) // 80
            setPos(x(),y()-10);
    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S ){
        if(pos().y() < 500)
            setPos(x(),y()+10);
    } else if (event->key() == Qt::Key_Space){
        if(pos().y() > 0) // 80
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
