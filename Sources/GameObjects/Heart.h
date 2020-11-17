//
// Created by exort on 17.11.2020.
//

#ifndef RIDINGMOTORCYCLE_HEART_H
#define RIDINGMOTORCYCLE_HEART_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

class Heart: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Heart();
public slots:
    void move();
};

#endif //RIDINGMOTORCYCLE_HEART_H
