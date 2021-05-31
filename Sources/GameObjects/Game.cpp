//
// Created by exort on 23.10.2020.
//

#include "Sources/GameObjects/Game.h"
#include <QGraphicsTextItem>
#include <QLabel>
#include <QCoreApplication>
#include <QThread>
#include <QTime>
#include <iostream>


Game::Game(){

    // scene tools
    scene = new QGraphicsScene();
//    scene->setSceneRect(0,0,1030,768);
//    setBackgroundBrush(QImage("../Sources/Pictures/Menu/background.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1030,768);


    // buttons and properties
//    playButton = new Button(QString("../Sources/Pictures/Menu/start-inactive.png"),
//                            QString("../Sources/Pictures/Menu/start-active.png"));
//    int bxPos = playButton->boundingRect().width()/8 + 3;
//    int byPos = 380;
//    playButton->setPos(bxPos, byPos);
//    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
//    scene->addItem(playButton);

//    scoreButton = new Button(QString("../Sources/Pictures/Menu/scores-inactive.png"),
//                             QString("../Sources/Pictures/Menu/scores-active.png"));
//    int sxPos = scoreButton->boundingRect().width()/8 + 3;
//    int syPos = 450;
//    scoreButton->setPos(sxPos, syPos);
//    connect(scoreButton,SIGNAL(clicked()), this, SLOT(showScores()));
//    scene->addItem(scoreButton);

//    helpButton = new Button(QString("../Sources/Pictures/Menu/help-inactive.png"),
//                            QString("../Sources/Pictures/Menu/help-active.png"));
//    int hxPos = helpButton->boundingRect().width()/8 + 3;
//    int hyPos = 520;
//    helpButton->setPos(hxPos, hyPos);
//    connect(helpButton,SIGNAL(clicked()), this, SLOT(showHelp()));
//    scene->addItem(helpButton);


//    quitButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
//                            QString("../Sources/Pictures/Menu/quit-active.png"));
//    int qxPos = quitButton->boundingRect().width()/8 + 3;
//    int qyPos = 610;
//    quitButton->setPos(qxPos, qyPos);
//    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));
//    scene->addItem(quitButton);

//    backButton = new Button(QString("../Sources/Pictures/Menu/back-inactive.png"),
//                            QString("../Sources/Pictures/Menu/back-active.png"));
//    int backxPos = scene->width()/2 - 40;
//    int backyPos = 610;
//    backButton->setPos(backxPos, backyPos);
//    connect(backButton,SIGNAL(clicked()), this, SLOT(displayMainMenu()));
//    scene->addItem(backButton);

    // text and parchment image

    parchmentImage = new QLabel();
    QPixmap img("../Sources/Pictures/Menu/paper.png");
    parchmentImage->setPixmap(img);


    double x = img.width();
    double y = img.height();
    parchmentImage->setGeometry(300,250,x,y);
    scene->addWidget(parchmentImage);

    info = new TextInformation();
    info->setPosition(300,270);
    scene->addItem(info);

//     game objects
    health = new Health();
    player = new Player();
    score = new Score();

    mainTimer = new QTimer();
//    connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainLoop()));

//    backMenuButton = new Button(QString("../Sources/Pictures/Menu/ok-inactive.png"),
//                                QString("../Sources/Pictures/Menu/ok-active.png"));
//    int bmxPos = 320;
//    int bmyPos = 110;
//    backMenuButton->setPos(bmxPos, bmyPos);
//    connect(backMenuButton, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
//
//    playAgainButton = new Button(QString("../Sources/Pictures/Menu/again-inactive.png"),
//                                 QString("../Sources/Pictures/Menu/again-active.png"));
//    int pxPos = 220;
//    int pyPos = 110;
//    playAgainButton->setPos(pxPos, pyPos);
//    playAgainButton->setSize(200,51);
//    connect(playAgainButton,SIGNAL(clicked()), this, SLOT(start()));
}

void Game::displayMainMenu() {
    scene->clear();

    scene->setSceneRect(0,0,1030,768);
    setFixedSize(1030,768);
    setBackgroundBrush(QImage("../Sources/Pictures/Menu/background.png"));

    // buttons and properties
    playButton = new Button(QString("../Sources/Pictures/Menu/start-inactive.png"),
                            QString("../Sources/Pictures/Menu/start-active.png"));
    double bxPos = playButton->boundingRect().width()/8 + 3;
    double byPos = 380;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    scoreButton = new Button(QString("../Sources/Pictures/Menu/scores-inactive.png"),
                             QString("../Sources/Pictures/Menu/scores-active.png"));
    double sxPos = scoreButton->boundingRect().width()/8 + 3;
    double syPos = 450;
    scoreButton->setPos(sxPos, syPos);
    connect(scoreButton,SIGNAL(clicked()), this, SLOT(showScores()));
    scene->addItem(scoreButton);

    helpButton = new Button(QString("../Sources/Pictures/Menu/help-inactive.png"),
                            QString("../Sources/Pictures/Menu/help-active.png"));
    double hxPos = helpButton->boundingRect().width()/8 + 3;
    double hyPos = 520;
    helpButton->setPos(hxPos, hyPos);
    connect(helpButton,SIGNAL(clicked()), this, SLOT(showHelp()));
    scene->addItem(helpButton);


    quitButton = new Button(QString("../Sources/Pictures/Menu/quit-inactive.png"),
                            QString("../Sources/Pictures/Menu/quit-active.png"));
    double qxPos = quitButton->boundingRect().width()/8 + 3;
    double qyPos = 610;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

    backButton = new Button(QString("../Sources/Pictures/Menu/back-inactive.png"),
                            QString("../Sources/Pictures/Menu/back-active.png"));
    double backxPos = scene->width()/2 - 40;
    double backyPos = 610;
    backButton->setPos(backxPos, backyPos);
    connect(backButton,SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backButton);

    // text and parchment image

    parchmentImage = new QLabel();
    QPixmap img("../Sources/Pictures/Menu/paper.png");
    parchmentImage->setPixmap(img);


    int x = img.width();
    int y = img.height();
    parchmentImage->setGeometry(300,250,x,y);
    scene->addWidget(parchmentImage);

    info = new TextInformation();
    info->setPosition(300,270);
    scene->addItem(info);


    // other no to del


    if(backButton->isVisible()) { scene->removeItem(backButton); }
    if(info->isVisible())       { scene->removeItem(info); }


    info->setProperties(Qt::black,"arial",16,300,270);
    parchmentImage->setHidden(true);


    playButton->setEnabled(true);
    scoreButton->setEnabled(true);
    helpButton->setEnabled(true);
    quitButton->setEnabled(true);
}



void Game::showHelp() const {

    playButton->setEnabled(false);
    scoreButton->setEnabled(false);
    helpButton->setEnabled(false);
    quitButton->setEnabled(false);


    info->setText("\n\tHelp Information\n\nUse WSAD keys or arrow \nto move your motorcycle\nAvoid the hurdles \n"
                  "to get score\nPick hearts for earn\nmore health points.\n\n\n\tEnjoy the game!");


    parchmentImage->setVisible(true);
    scene->addItem(info);
    scene->addItem(backButton);


}

void Game::showScores() const {

    playButton->setEnabled(false);
    scoreButton->setEnabled(false);
    helpButton->setEnabled(false);
    quitButton->setEnabled(false);


    info->setText("\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n");

    parchmentImage->setVisible(true);
    scene->addItem(info);
    scene->addItem(backButton);


}

void Game::counting(unsigned long msecs) const
{
    QTime dieTime;
    info->setProperties(Qt::black,"arial",36,400,180);

    for(int i=3; i>=0; i--){
        if(i==0) { // set right text
            info->setText("START!!!");
            info->setPosition(340,180);
        } else
            info->setText(QString::number(i));

        scene->addItem(info); // show text

        dieTime= QTime::currentTime().addMSecs((int)msecs); // calculate how long app may be delayed
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        scene->removeItem(info); // remove text
    }
}

void Game::keyPressEvent(QKeyEvent* event){
    player->keyReact(event);
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyRelease(event);
}



void Game::mainLoop() {
    if(health->getHealth() > 0){
        player->move();
    }
}




void Game::start() {
    scene->clear();

    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setBackgroundBrush(QImage("../Sources/Pictures/gameBackground.png"));

    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->resetPos();
    scene->addItem(player);

    score = new Score();
    score->resetScore();
    score->setPos(score->x()+600, score->y()+9);
    scene->addItem(score);

    health = new Health();
    health->resetHealth();
    health->setPos(health->x()+380, health->y()+9);
    scene->addItem(health);


    mainTimer->disconnect();
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainLoop()));
    if(!mainTimer->isActive()){
        mainTimer->start(0);
    }

    counting(1000);

    auto * timerHurdle = new QTimer();
    QObject::connect(timerHurdle,SIGNAL(timeout()),player,SLOT(spawnHurdle()));
    timerHurdle->start(2000);

    auto * timerHeart = new QTimer();
    QObject::connect(timerHeart,SIGNAL(timeout()),player,SLOT(spawnHeart()));
    timerHeart->start(10000);
}

void Game::drawPanel(float x, float y, int width, int height, const QColor& color, double opacity) const{
    // draws a panel at the specified location with the specified properties
    auto* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}


void Game::ShowGameOverWindow(int points){
    setBackgroundBrush(QImage("../Sources/Pictures/gameover.png"));
    int height = window()->height();
    int width = window()->width();

    std::cout << "You have got score "<< points <<" points!";
    drawPanel(0,0,860,600,Qt::black,0.35);
    drawPanel((float)width/4+30,(float)height/4,400,400,Qt::lightGray,0.75);

    backMenuButton = new Button(QString("../Sources/Pictures/Menu/ok-inactive.png"),
                            QString("../Sources/Pictures/Menu/ok-active.png"));
    int qxPos = width-320;
    int qyPos = height-110;
    backMenuButton->setPos(qxPos, qyPos);
    connect(backMenuButton, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backMenuButton);

    playAgainButton = new Button(QString("../Sources/Pictures/Menu/again-inactive.png"),
                            QString("../Sources/Pictures/Menu/again-active.png"));
    int pxPos = width/3-30;
    int pyPos = height-110;
    playAgainButton->setPos(pxPos, pyPos);
    playAgainButton->setSize(200,51);
    connect(playAgainButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playAgainButton);
}
