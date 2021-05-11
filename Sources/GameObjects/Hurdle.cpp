//
// Created by exort on 22.10.2020.
//

#include <iostream>
#include "Sources/GameObjects/Hurdle.h"
#include "Game.h"



extern Game * game;


Hurdle::Hurdle(): QObject(), QGraphicsPixmapItem(){
    int random = (rand() % 400)+200;
    setPos(random,80);


    setPixmap(QPixmap("../Sources/Pictures/hole.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


    if(game->score->getScore() >= 10) {
        timer->start(35);
    } else if (game->score->getScore() >= 25) {
        timer->start(25);
    } else if (game->score->getScore() >= 50) {
        timer->start(20);
    }


}

void Hurdle::move() {

    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i=0; i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(this);
            delete this;

            if (game->score->getScore() > 0 ){
                int level = game->score->getScore()/10 + 1;
                for (int j=0; j<level; j++)
                    game->health->decrease();
            } else {
                game->health->decrease();
            }

            if (game->health->getHealth() <= 0){
                game->scene->clear();
                playAgain = new Button(QString("../Sources/Pictures/Menu/start-inactive.png"),
                                       QString("../Sources/Pictures/Menu/start-active.png"));
                playAgain->setPos(500,600);
                std::cout << playAgain;
                connect(playAgain,SIGNAL(clicked()), playAgain, SLOT(RestartGame()));
                game->setBackgroundBrush(QImage("../Sources/Pictures/gameover.png"));
//                game->scene->addItem(playAgain);
            }
            return;
        }
    }


    setPos(x(),y()+5);
    if(pos().y() > 600){
        game->score->increase();
        scene()->removeItem(this);
        delete this;
    }


}

//void Hurdle::RestartGame() {
//    game->start();
//    delete this;
//}

