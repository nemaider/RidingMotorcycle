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
#include <QImage>
#include <QBrush>
#include <Sources/GameObjects/Player.h>
#include <Sources/GameObjects/Score.h>
#include <Sources/GameObjects/Hurdle.h>
#include <Sources/GameObjects/Health.h>
#include <Sources/GameObjects/Heart.h>
#include <QLabel>
#include "Button.h"
#include "TextInformation.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game (QWidget * parent=0);



    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    Button * playButton;
    Button * scoreButton;
    Button * helpButton;
    Button * quitButton;
    Button * backButton;

    QLabel * parchmentImage;
    TextInformation * info;

public slots:
    void start();
    void displayMainMenu();
    void showHelp();
    void showScores();
    void mainLoop();

public:
    void counting(unsigned long);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
};


#endif //RIDINGMOTORCYCLE_GAME_H
