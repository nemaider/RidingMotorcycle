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
};

#endif //RIDINGMOTORCYCLE_TEXTINFORMATION_H
