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
#include <QLineEdit>
#include <QTextEdit>
#include <QTextStream>


Game::Game(){
    // scene properties
    scene = new QGraphicsScene();
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1030,768);


    // text and parchment image

    parchmentImage = new QLabel();
    QPixmap img("../Sources/Pictures/Menu/paper.png");
    parchmentImage->setPixmap(img);


    double x = img.width();
    double y = img.height();
    parchmentImage->setGeometry(300,250,x,y);
    scene->addWidget(parchmentImage);

//     game objects
    health = new Health();
    player = new Player();
    score = new Score();
    mainTimer = new QTimer();
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


struct scores{
    QString points;
    QString date;
    int rank;
};

bool compareTwoPlayers(struct scores a, struct scores b){
    //if scored points aren't same then return true for higher points value
    if(a.points.toInt() != b.points.toInt())
        return a.points.toInt() > b.points.toInt();

    //if date that player scored his points aren't same, return true for lower date
    return (a.date < b.date);
}

void compareScores(scores a[], int n){
    std::sort(a, a+n, compareTwoPlayers);

    for(int i=0; i<n; i++){
        a[i].rank = i+1;
    }
}


void Game::showScores() const {

    playButton->setEnabled(false);
    scoreButton->setEnabled(false);
    helpButton->setEnabled(false);
    quitButton->setEnabled(false);



    QString filename = "score.txt";
    QFile file(filename);

    int size=20;
    scores array[size];

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        int i=0;

        QTextStream stream(&file);

        while(!file.atEnd() || i==9){
            QString line = file.readLine();
            std::string text = line.toStdString();
            int pos = text.find(",");
            std::string cutDate = text.substr(pos + 1);
            cutDate.erase(std::remove(cutDate.begin(), cutDate.end(), '\n'), cutDate.end());
            std::string cutScore = text.substr(0, pos);
            array[i].points = QString::fromStdString(cutScore);
            array[i].date = QString::fromStdString(cutDate);
            i++;

        }
    }
    file.close();

    compareScores(array, size);


    QString text = "Rank\tPoints\tDate\n";
    for(int i=0; i<10; i++){
        if(array[i].points == "") break;
        text += QString::number(array[i].rank);
        text += "\t";
        text += (QString) array[i].points;
        text += "\t";
        text += (QString) array[i].date;
        text += "\n";
    }

    info->setText(text);

    parchmentImage->setVisible(true);
    scene->addItem(info);
    scene->addItem(backButton);


}

void Game::counting(unsigned long msecs) const
{
    QTime dieTime;
    info->setProperties(Qt::black,"arial",36,400,180);

    for(int i=3; i>=0; i--){
        if(i==0) {
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

int points;
void Game::ShowGameOverWindow(){
    points = score->getScore();
    scene->clear();
    setBackgroundBrush(QImage("../Sources/Pictures/gameover.png"));
    int height = window()->height();
    int width = window()->width();

    std::cout << "You have got score "<< points <<" points!";
    drawPanel(0,0,860,600,Qt::black,0.35);
    drawPanel((float)width/4+30,(float)height/4,400,400,Qt::lightGray,0.75);

    backMenuButton = new Button(QString("../Sources/Pictures/Menu/back-inactive.png"),
                            QString("../Sources/Pictures/Menu/back-active.png"));
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

    auto * pointsInfo = new TextInformation();
    pointsInfo->setProperties(Qt::black, "arial", 14, pxPos-5, height/4+20);
    pointsInfo->setText(QString("\t          Congratulations!\n\t    You have scored %1 points\nIf you want to save your score click button below").arg(points));
    scene->addItem(pointsInfo);


//    QLineEdit * nicknameField = new QLineEdit();
//    nicknameField->setPlaceholderText("Enter your nickname");
//    nicknameField->setGeometry(pxPos,260,200,30);
//    nicknameField->setFocus();
//    scene->addWidget(nicknameField);


    Button * submit = new Button(QString("../Sources/Pictures/Menu/ok-inactive.png"),
                                 QString("../Sources/Pictures/Menu/ok-active.png"));
    submit->setPos(pxPos+220, 260);
    submit->setSize(77,55);
    connect(submit,SIGNAL(clicked()), this, SLOT(saveScore()));
    scene->addItem(submit);

}

void Game::saveScore(){
    QString filename = "score.txt";
    QFile file(filename);

    QDateTime local(QDateTime::currentDateTime());

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);
        stream <<points<<","<<local.time().toString()<<Qt::endl;
    }

    file.close();
}
