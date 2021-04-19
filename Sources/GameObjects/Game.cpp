//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include <QLabel>


Game::Game(QWidget * parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1030,768);
    setBackgroundBrush(QImage("../Sources/Pictures/Menu/background.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1030,768);

}

void Game::displayMainMenu() {

    scene->clear();

    Button* playButton = new Button(QString("../Sources/Pictures/Menu/start-inactive.png"),
                                     QString("../Sources/Pictures/Menu/start-active.png"));
    int bxPos = playButton->boundingRect().width()/8 + 3;
    int byPos = 380;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    Button* scoresButton = new Button(QString("../Sources/Pictures/Menu/scores-inactive.png"),
                                    QString("../Sources/Pictures/Menu/scores-active.png"));
    int sxPos = scoresButton->boundingRect().width()/8 + 3;
    int syPos = 450;
    scoresButton->setPos(sxPos, syPos);
    connect(scoresButton,SIGNAL(clicked()), this, SLOT(showScores()));
    scene->addItem(scoresButton);

    Button* helpButton = new Button(QString("../Sources/Pictures/Menu/help-inactive.png"),
                                    QString("../Sources/Pictures/Menu/help-active.png"));
    int hxPos = helpButton->boundingRect().width()/8 + 3;
    int hyPos = 520;
    helpButton->setPos(hxPos, hyPos);
    connect(helpButton,SIGNAL(clicked()), this, SLOT(showHelp()));
    scene->addItem(helpButton);


    Button* quitButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
                                    QString("../Sources/Pictures/Menu/quit-active.png"));
    int qxPos = quitButton->boundingRect().width()/8 + 3;
    int qyPos = 610;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

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


void Game::showHelp() {


    QLabel *mylabel = new QLabel();
    QPixmap img("../Sources/Pictures/Menu/paper.png");
    mylabel->setPixmap(img);


    double x = img.width();
    double y = img.height();
    mylabel->setGeometry(300,250,x,y);
    scene->addWidget(mylabel);



    Button* backButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
                                    QString("../Sources/Pictures/Menu/quit-active.png"));
    int qxPos = scene->width()/2 - 40;
    int qyPos = 610;
    backButton->setPos(qxPos, qyPos);
    connect(backButton,SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backButton);

}

void Game::showScores() {



    Button* backButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
                                    QString("../Sources/Pictures/Menu/quit-active.png"));
    int qxPos = scene->width()/2 - backButton->boundingRect().width();
    int qyPos = 610;
    backButton->setPos(qxPos, qyPos);
    connect(backButton,SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backButton);

}