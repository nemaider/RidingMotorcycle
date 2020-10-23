//
// Created by exort on 23.10.2020.
//

#ifndef RIDINGMOTORCYCLE_GAME_H
#define RIDINGMOTORCYCLE_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <Sources/GameObjects/Player.h>
#include <Sources/GameObjects/Score.h>
#include <Sources/GameObjects/Hurdle.h>
#include <Sources/GameObjects/Health.h>

class Game: public QGraphicsView{
public:
    Game (QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};


#endif //RIDINGMOTORCYCLE_GAME_H
