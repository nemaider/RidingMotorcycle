//
// Created by exort on 20.10.2020.
//

#ifndef RIDINGMOTORCYCLE_PLAYER_H
#define RIDINGMOTORCYCLE_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>


class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
//    void keyPressEvent(QKeyEvent * event);
    void resetPos();


    void keyReact(QKeyEvent * event);
    void keyRelease(QKeyEvent * event);

    void move();
    void calculateAngle();
    void calculateMove();
    void calculateXY();

public slots:
    void spawnHurdle();
    void spawnHeart();

private:
    bool thrust;
    bool braking;
    double speed;
    double maxSpeed;
    double shipAcceleration;
    double shipBreak;
    double shipAgility;
    bool rotateLeft;
    bool rotateRight;
    double angle;


};


#endif //ICEHOCKEY_PLAYER_H
