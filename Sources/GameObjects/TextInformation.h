//
// Created by exort on 19.04.2021.
//

#ifndef RIDINGMOTORCYCLE_TEXTINFORMATION_H
#define RIDINGMOTORCYCLE_TEXTINFORMATION_H

#include <QGraphicsTextItem>
#include <QFont>

class TextInformation: public QGraphicsTextItem{
public:


    TextInformation();

    void setText(QString text);
    void setPosition(int x, int y);
    void setProperties(QColor color, QString family, int size, int x, int y);
};

#endif //RIDINGMOTORCYCLE_TEXTINFORMATION_H
