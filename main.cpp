#include <QApplication>
#include <Sources/GameObjects/Game.h>


Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
