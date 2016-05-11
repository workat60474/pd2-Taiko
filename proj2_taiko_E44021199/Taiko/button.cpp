#include"button.h"
#include<QBrush>
#include<QGraphicsTextItem>
button::button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //draw the text
    text=new QGraphicsTextItem(name,this);
    int xpos=rect().width()/5;
    int ypos=rect().height()/5;

    text->setPos(xpos,ypos);

    setAcceptHoverEvents(true);
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();

}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
