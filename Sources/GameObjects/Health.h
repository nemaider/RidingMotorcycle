//
// Created by exort on 23.10.2020.
//

#ifndef RIDINGMOTORCYCLE_HEALTH_H
#define RIDINGMOTORCYCLE_HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent =0);
    void decrease();
    int getHealth();
private:
    int health;
};


#endif //RIDINGMOTORCYCLE_HEALTH_H
