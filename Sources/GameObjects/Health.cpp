//
// Created by exort on 23.10.2020.
//

#include "Health.h"




Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    health = 3;

    setPlainText(QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",36));

}

void Health::decrease() {
    health--;
    setPlainText(QString::number(health));
}

void Health::increase() {
    health++;
    setPlainText(QString::number(health));
}

int Health::getHealth() {
    return health;
}