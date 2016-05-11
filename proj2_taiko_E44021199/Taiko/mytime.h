#ifndef MYTIME_H
#define MYTIME_H
#include<QGraphicsTextItem>

#include<QObject>
class mytime:public QGraphicsTextItem{

public:
    mytime(QGraphicsItem *parent=0);
    void showtime();

int cnt=30;

private:


};
#endif // MYTIME_H
