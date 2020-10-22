#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Sources/GameObjects/Player.h>

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


    return a.exec();
}
