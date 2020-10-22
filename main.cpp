#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include <Sources/GameObjects/Player.h>
#include <Sources/GameObjects/Hurdle.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    auto *player1 = new Player();

    player1->setRect(0,0,100,100);

    scene->addItem(player1);

    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    player1->setPos(view->width()/2, view->height() - player1->rect().height());

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player1,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
