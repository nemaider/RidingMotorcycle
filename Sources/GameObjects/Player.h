//
// Created by exort on 20.10.2020.
//

#ifndef RIDINGMOTORCYCLE_PLAYER_H
#define RIDINGMOTORCYCLE_PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>


class Player: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};


#endif //ICEHOCKEY_PLAYER_H
