#ifndef MOVING_FACE_H
#define MOVING_FACE_H
#include<QGraphicsPixmapItem>
#include<QGraphicsEllipseItem>
#include<QObject>
class moving_face: public QObject, public QGraphicsPixmapItem
{   Q_OBJECT
public:
    moving_face();
    int tag;
 public slots:
    void move();
};
#endif // MOVING_FACE_H

