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



