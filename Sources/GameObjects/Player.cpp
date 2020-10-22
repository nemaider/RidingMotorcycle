//
// Created by exort on 20.10.2020.
//

#include "Player.h"


void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 200)
            setPos(x()-10,y());
    } else if (event->key() == Qt::Key_Right){
        if(pos().x() < 500)
            setPos(x()+10,y());
    } else if (event->key() == Qt::Key_Up){
        if(pos().y() > 0)
            setPos(x(),y()-10);
    } else if (event->key() == Qt::Key_Down){
        if(pos().y() < 500)
            setPos(x(),y()+10);
    } else if (event->key() == Qt::Key_Space){
        if(pos().y() > 0)
            setPos(x(),y()-20);
    }
}