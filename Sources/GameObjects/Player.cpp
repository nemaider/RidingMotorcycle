//
// Created by exort on 20.10.2020.
//

#include <iostream>
#include <valarray>
#include "Player.h"
#include "Hurdle.h"
#include "Heart.h"

#define MAX_X 620
#define MAX_Y 500
#define MIN_X 180
#define MIN_Y 80


Player::Player(): QObject(), QGraphicsPixmapItem(){

    setPos(400,500);
    setPixmap(QPixmap("../Sources/Pictures/motorcycle.png"));

    thrust = false;
    braking = false;
    speed = 0;
    maxSpeed = 0.0001;
    shipAcceleration = 0.02;
    shipBreak = 0.005;
    shipAgility = 0.0059;
    angle = 0;
    rotateLeft = false;
    rotateRight = false;
}

void Player::resetPos(){
    setPos(400,500);
    angle=0;
    setRotation(angle);
}

void Player::keyReact(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left)
    {
        rotateLeft = true;
    }
    else if (event->key() == Qt::Key_Right)
    {
        rotateRight = true;
    }
    else if (event->key() == Qt::Key_Up)
    {
        thrust = true;
    } else if (event->key() == Qt::Key_Down)
    {
        braking = true;
    }

}

void Player::keyRelease(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left)
    {
        rotateLeft = false;
    }
    else if (event->key() == Qt::Key_Right)
    {
        rotateRight = false;
    }
    else if (event->key() == Qt::Key_Up)
    {
        thrust = false;
    }
    else if (event->key() == Qt::Key_Down)
    {
        braking = false;
    }


}

void Player::move()
{
    calculateAngle();
    calculateMove();
    calculateXY();
}


void Player::calculateMove()
{
    if (thrust) {
        if (speed < maxSpeed) {
            speed += shipAcceleration;
        }
    } else if (braking) {
        if (speed > 0)
            speed -= shipAcceleration;
    }
    else if(!thrust && !braking) {
        if (speed > 0)
            speed -= shipBreak * 0.001;
        else if (speed < 0)
            speed += shipBreak * 0.001;
    }



}

void Player::calculateXY()
{
    double actualX = pos().x();
    double actualY = pos().y();
    double destinationX;
    double destinationY;
    double deltaX;
    double deltaY;
    double pi = 3.14159265359;

    deltaX = speed * sin(angle * (pi / 180));
    deltaY = speed * cos(angle * (pi / 180));

    if (pos().x() > deltaX)
    {
        destinationX = actualX + deltaX;
    }
    else
    {
        destinationX = actualX - deltaX;
    }

    if (pos().y() > deltaY)
    {
        destinationY = actualY - deltaY;
    }
    else
    {
        destinationY = actualY + deltaY;
    }


    double x = destinationX;
    double y = destinationY;

    if(x > MAX_X) x = MAX_X; if(x < MIN_X) x = MIN_X;
    if(y > MAX_Y) y = MAX_Y; if(y < MIN_Y) y = MIN_Y;

    setPos(x,y);

}

void Player::calculateAngle()
{
    if (rotateRight)
    {
        angle += shipAgility;
    }
    else if (rotateLeft)
    {
        angle -= shipAgility;
    }

    setRotation(angle);
}


//void Player::keyPressEvent(QKeyEvent *event) {
//    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
//        if(pos().x() > 180)
//            setPos(x()-10,y());
//    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D ){
//        if(pos().x() < 620)
//            setPos(x()+10,y());
//    } else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W ){
//        if(pos().y() > 0) // 80
//            setPos(x(),y()-10);
//    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S ){
//        if(pos().y() < 500)
//            setPos(x(),y()+10);
//    } else if (event->key() == Qt::Key_Space){
//        if(pos().y() > 0) // 80
//            setPos(x(),y()-20);
//    }
//
//}



void Player::spawnHurdle() {
    Hurdle * hurdle = new Hurdle();
    scene()->addItem(hurdle);
}

void Player::spawnHeart() {
    Heart * heart = new Heart();
    scene()->addItem(heart);
}
