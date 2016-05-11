#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QGraphicsEllipseItem>
#include<QObject>
#include <QProcess>

class mycircle: public QObject,public QGraphicsEllipseItem
{   Q_OBJECT
public :
    void keyPressEvent(QKeyEvent *event);
    int choose;
    int randnumber;
public slots:
    void spawn();
    void start_again();
    void countdown();
    void setrad();
};
#endif // MYCIRCLE_H
