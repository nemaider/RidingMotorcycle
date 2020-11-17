//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"

#include <QMediaPlayer>


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
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();

//    QMediaPlayer * bgMusic = new QMediaPlayer();
//    connect(bgMusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    bgMusic->setMedia(QUrl::fromLocalFile("../Source/Sounds/battle.ogg"));
//    bgMusic->play();



};