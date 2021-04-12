//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"
#include "Button.h"
#include <QGraphicsTextItem>


Game::Game(QWidget * parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QImage("../Sources/Pictures/startBackground.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

}

void Game::displayMainMenu() {
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Riding motorcycle!"));
    QFont titleFont("comic sans", 42);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2 + 20;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2 + 20;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2 + 20;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start() {
    scene->clear();

//    setBackgroundBrush(QImage("../Sources/Pictures/gameBackground.png"));
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
//
//    score = new Score();
//    score->setPos(score->x()+600, score->y()+9);
//    scene->addItem(score);
//
//    health = new Health();
//    health->setPos(health->x()+380, health->y()+9);
//    scene->addItem(health);
//
//
//
//    QTimer * timerHurdle = new QTimer();
//    QObject::connect(timerHurdle,SIGNAL(timeout()),player,SLOT(spawnHurdle()));
//    timerHurdle->start(2000);
//
//    QTimer * timerHeart = new QTimer();
//    QObject::connect(timerHeart,SIGNAL(timeout()),player,SLOT(spawnHeart()));
//    timerHeart->start(10000);
}