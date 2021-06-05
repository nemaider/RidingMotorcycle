//
// Created by exort on 19.04.2021.
//

#include "TextInformation.h"



TextInformation::TextInformation() : QGraphicsTextItem() {

    setDefaultTextColor(Qt::black);
    setFont(QFont("arial",16));
}

void TextInformation::setText(QString text) {
    setPlainText(text);
}


void TextInformation::setPosition(int x, int y) {
    this->setPos(x,y);
}

void TextInformation::setProperties(QColor color, QString family, int size, int x, int y){
    setDefaultTextColor(color);
    setFont(QFont(family, size));
    this->setPos(x,y);
}


