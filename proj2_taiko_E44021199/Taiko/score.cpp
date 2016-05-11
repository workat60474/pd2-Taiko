#include"score.h"
#include<QFont>

score::score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize the score to 0
    score_value=0;
    //draw the text
    setPlainText(QString("Score: ")+ QString::number(score_value));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void score::increase()
{
    score_value++;
    setPlainText(QString("Score: ")+ QString::number(score_value));
}

int score::getscore()
{
    return score_value;
}
