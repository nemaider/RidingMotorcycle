//
// Created by exort on 23.03.2021.
//

#include <QBrush>
#include <QGraphicsTextItem>
#include "Button.h"

Button::Button(QString graphInactiveFileName, QString graphActiveFileName, QGraphicsItem *parent): QGraphicsRectItem(parent){

    this->foregroundImg = graphInactiveFileName;
    this->backgroundImg = graphActiveFileName;


    setRect(0,0,143,54);
    QBrush brush;
    brush.setTexture(QPixmap(foregroundImg));
    setBrush(brush);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QBrush brush;
    brush.setTexture(QPixmap(backgroundImg));
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    QBrush brush;
    brush.setTexture(QPixmap(foregroundImg));
    setBrush(brush);
}


