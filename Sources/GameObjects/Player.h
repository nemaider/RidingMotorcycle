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
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawnHurdle();
    void spawnHeart();
};


#endif //ICEHOCKEY_PLAYER_H
