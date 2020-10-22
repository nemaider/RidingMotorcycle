//
// Created by exort on 22.10.2020.
//

#ifndef RIDINGMOTORCYCLE_HURDLE_H
#define RIDINGMOTORCYCLE_HURDLE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

class Hurdle: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Hurdle();
public slots:
    void move();
};

#endif //RIDINGMOTORCYCLE_HURDLE_H
