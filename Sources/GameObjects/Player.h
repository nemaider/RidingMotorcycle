//
// Created by exort on 20.10.2020.
//

#ifndef RIDINGMOTORCYCLE_PLAYER_H
#define RIDINGMOTORCYCLE_PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>


class Player: public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent * event);
};


#endif //ICEHOCKEY_PLAYER_H
