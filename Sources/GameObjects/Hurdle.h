//
// Created by exort on 22.10.2020.
//

#ifndef RIDINGMOTORCYCLE_HURDLE_H
#define RIDINGMOTORCYCLE_HURDLE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Button.h"

class Hurdle: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hurdle();
public slots:
    void move();

};

#endif //RIDINGMOTORCYCLE_HURDLE_H
