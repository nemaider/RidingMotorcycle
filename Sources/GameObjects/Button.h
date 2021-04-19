//
// Created by exort on 23.03.2021.
//

#ifndef RIDINGMOTORCYCLE_BUTTON_H
#define RIDINGMOTORCYCLE_BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>


class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Button(QString graphInactiveFileName, QString graphActiveFileName,QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
    QString foregroundImg;
    QString backgroundImg;
};


#endif //RIDINGMOTORCYCLE_BUTTON_H
