#include"mycircle.h"
#include"moving_face.h"
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QList>
#include<score.h>
#include"mytime.h"
#include<QDebug>
#include <QProcess>
#include<time.h>
extern score *score_graph;
extern mytime *myTimer;
extern int rand_num;
void mycircle::keyPressEvent(QKeyEvent *event)
{
       // srand(time(NULL));
      //  rand_num=rand()%2;


        choose=2;
        if(event->key()== Qt::Key_Space){
                         choose=0;
                     //    qDebug()<<"choose="<<choose;
                       //if moving face hit the drum ,delete the face
                       //   QList<QGraphicsItem *>colliding_items=collidingItems();
                       //       for(int i=0,n=colliding_items.size();i<n;i++){
                                  //remove the face
                       //           scene()->removeItem(colliding_items[i]);
                       //           delete colliding_items[i];
                                  //incresing the score
                       //          score_graph->increase();

                              }

     else   if(event->key()== Qt::Key_J){
                         choose=1;
                       //   qDebug()<<"choose="<<choose;
                       //if moving face hit the drum ,delete the face
                   //       QList<QGraphicsItem *>colliding_items=collidingItems();
                   //           for(int i=0,n=colliding_items.size();i<n;i++){
                                  //remove the face
                   //               scene()->removeItem(colliding_items[i]);
                   //               delete colliding_items[i];
                                  //incresing the score
                   //              score_graph->increase();
                              }

}

void mycircle::spawn(){
    //creat a moving face
    moving_face *move_face =new moving_face();

    move_face->setPos(x(),y());
    scene()->addItem(move_face);

}

void mycircle::start_again()
{
    QProcess *process=new QProcess();
    process->startDetached("Taiko");
    delete process;

}





void mycircle::countdown()
{
    myTimer->showtime();
}

void mycircle::setrad()
{  srand(time(NULL));
    randnumber=rand()%3;

}
