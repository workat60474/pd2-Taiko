#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>

class score:public QGraphicsTextItem{
public:
    score(QGraphicsItem *parent=0);
    void increase();
    int getscore(); //return the score
    int score_value;
private:


};
#endif // SCORE_H
