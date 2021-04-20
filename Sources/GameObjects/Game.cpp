//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"
#include <QGraphicsTextItem>
#include <QLabel>


Game::Game(QWidget * parent){

    // scene tools
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1030,768);
    setBackgroundBrush(QImage("../Sources/Pictures/Menu/background.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1030,768);


    // buttons and properties
    playButton = new Button(QString("../Sources/Pictures/Menu/start-inactive.png"),
                            QString("../Sources/Pictures/Menu/start-active.png"));
    int bxPos = playButton->boundingRect().width()/8 + 3;
    int byPos = 380;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    scoreButton = new Button(QString("../Sources/Pictures/Menu/scores-inactive.png"),
                             QString("../Sources/Pictures/Menu/scores-active.png"));
    int sxPos = scoreButton->boundingRect().width()/8 + 3;
    int syPos = 450;
    scoreButton->setPos(sxPos, syPos);
    connect(scoreButton,SIGNAL(clicked()), this, SLOT(showScores()));
    scene->addItem(scoreButton);

    helpButton = new Button(QString("../Sources/Pictures/Menu/help-inactive.png"),
                            QString("../Sources/Pictures/Menu/help-active.png"));
    int hxPos = helpButton->boundingRect().width()/8 + 3;
    int hyPos = 520;
    helpButton->setPos(hxPos, hyPos);
    connect(helpButton,SIGNAL(clicked()), this, SLOT(showHelp()));
    scene->addItem(helpButton);


    quitButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
                            QString("../Sources/Pictures/Menu/quit-active.png"));
    int qxPos = quitButton->boundingRect().width()/8 + 3;
    int qyPos = 610;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

    backButton = new Button(QString("../Sources/Pictures/Menu/back-inactive.png"),
                            QString("../Sources/Pictures/Menu/back-active.png"));
    int backxPos = scene->width()/2 - 40;
    int backyPos = 610;
    backButton->setPos(backxPos, backyPos);
    connect(backButton,SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backButton);

    // text and parchment image

    parchmentImage = new QLabel();
    QPixmap img("../Sources/Pictures/Menu/paper.png");
    parchmentImage->setPixmap(img);


    double x = img.width();
    double y = img.height();
    parchmentImage->setGeometry(300,250,x,y);
    scene->addWidget(parchmentImage);

    info = new TextInformation();
    info->setPos(300,270);
    scene->addItem(info);

}

void Game::displayMainMenu() {


    scene->removeItem(backButton);
    scene->removeItem(info);
    parchmentImage->setHidden(true);


    playButton->setEnabled(true);
    scoreButton->setEnabled(true);
    helpButton->setEnabled(true);
    quitButton->setEnabled(true);


}



void Game::showHelp() {

    playButton->setEnabled(false);
    scoreButton->setEnabled(false);
    helpButton->setEnabled(false);
    quitButton->setEnabled(false);


    info->setText("\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n");


    parchmentImage->setVisible(true);
    scene->addItem(info);
    scene->addItem(backButton);


}

void Game::showScores() {



    playButton->setEnabled(false);
    scoreButton->setEnabled(false);
    helpButton->setEnabled(false);
    quitButton->setEnabled(false);


    info->setText("SCORE SCORE SCORE");

    parchmentImage->setVisible(true);
    scene->addItem(info);
    scene->addItem(backButton);

}


void Game::start() {
    scene->clear();

    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setBackgroundBrush(QImage("../Sources/Pictures/gameBackground.png"));
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



    auto * timerHurdle = new QTimer();
    QObject::connect(timerHurdle,SIGNAL(timeout()),player,SLOT(spawnHurdle()));
    timerHurdle->start(2000);

    auto * timerHeart = new QTimer();
    QObject::connect(timerHeart,SIGNAL(timeout()),player,SLOT(spawnHeart()));
    timerHeart->start(10000);
}
