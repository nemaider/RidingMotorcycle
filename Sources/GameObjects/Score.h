//
// Created by exort on 23.10.2020.
//

#ifndef RIDINGMOTORCYCLE_SCORE_H
#define RIDINGMOTORCYCLE_SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
class Score: public  QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent =0);
    void increase();
    int getScore();
private:
    int score;
};



#endif //RIDINGMOTORCYCLE_SCORE_H
