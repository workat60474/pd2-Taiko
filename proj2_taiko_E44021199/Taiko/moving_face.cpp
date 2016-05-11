#include"moving_face.h"
#include<QTimer>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QDebug>
//#include<QGraphicsEllipseItem>
#include<stdlib.h>
#include"mycircle.h"
#include"score.h"
extern int rand_num;
extern mycircle *myCircle;
extern score *score_graph;
extern score *finalscore;
extern mycircle *myrandCircle;
moving_face::moving_face()
{
  // setRect(650,150,50,50);
   // setPos(650,150);

if(myrandCircle->randnumber==0)  { setPixmap(QPixmap(":/image_load/face1.PNG"));tag=0; }
else {setPixmap(QPixmap(":/image_load/face2.PNG"));tag=1; }
    //connect
    QTimer *timer=new QTimer();
    connect( timer,SIGNAL(timeout()),this,SLOT(move()) );
    myCircle->choose=2;
    timer->start(150);
}

void moving_face::move()
{
    //move the face left
    setPos(x()-10,y());

      if(pos().x()<-500){    //even if the moving face didn't destroy by the drum ,it will still disappaer
        scene()->removeItem(this);
        delete this;
      //  qDebug()<<"delete itself";
    }
      else if(pos().x()<-415 && pos().x()>-475 && myCircle->choose==0 &&this->tag==0 )
      {
          scene()->removeItem(this);
          delete this;
         // qDebug()<<"delete by space";
             myCircle->choose=2;
              score_graph->increase();
              finalscore->increase();
      }
      else if(pos().x()<-415 && pos().x()>-475 && myCircle->choose==1 &&this->tag==1 )
      {
          scene()->removeItem(this);
          delete this;
        //  qDebug()<<"delete by j";
             myCircle->choose=2;
             score_graph->increase();score_graph->increase();//pius 2 points
             finalscore->increase();finalscore->increase();
      }

};
