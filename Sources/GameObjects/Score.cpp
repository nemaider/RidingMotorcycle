//
// Created by exort on 23.10.2020.
//

#include "Score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    score = 0;

    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",36));

}

void Score::increase() {
    score++;
    setPlainText(QString::number(score));
}

int Score::getScore() {
    return score;
}

void Score::resetScore() {
    this->score = 0;
}