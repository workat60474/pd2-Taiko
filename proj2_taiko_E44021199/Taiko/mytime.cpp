#include"mytime.h"
#include<QFont>
#include <QProcess>
mytime::mytime(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    //draw the text

    setPlainText(QString("Time: ")+ QString::number(cnt));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
void mytime::showtime()
{
    cnt--;
    setPlainText(QString("Time: ")+ QString::number(cnt));
}




