//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"



Game::Game(QWidget * parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QImage("../Sources/Pictures/background.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    score->setPos(score->x()+600, score->y()+9);
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+380, health->y()+9);
    scene->addItem(health);



    QTimer * timerHurdle = new QTimer();
    QObject::connect(timerHurdle,SIGNAL(timeout()),player,SLOT(spawnHurdle()));
    timerHurdle->start(2000);

    QTimer * timerHeart = new QTimer();
    QObject::connect(timerHeart,SIGNAL(timeout()),player,SLOT(spawnHeart()));
    timerHeart->start(10000);






    show();



};