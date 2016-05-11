
#include <QApplication>
#include "score.h"
#include<QGraphicsScene>
#include"mycircle.h"
#include"mytime.h"
#include<QGraphicsView>
#include<QTimer>
#include<QImage>
#include<QBrush>
#include<QFont>
#include<QWidget>
#include<QMouseEvent>
#include<QString>
#include<stdlib.h>
#include<QDebug>
#include<QPainter>
#include"button.h"
#include <QProcess>
mytime *myTimer;
mycircle *myCircle;
mycircle *myrandCircle;
QGraphicsScene  *scene;
score *score_graph;
score *finalscore;
QTimer *rand_timer;
int rand_num;

int main(int argc, char *argv[])
{


    QApplication a(argc,argv);

    //set random timer
    rand_timer=new QTimer();
    myrandCircle=new mycircle();
    QObject::connect(rand_timer,SIGNAL(timeout()),myrandCircle,SLOT(setrad()));
    rand_timer->start(80);
    mycircle *restartCircle=new mycircle();
    //creat a quit button
    button *mybutton;
    mybutton =new button(QString("quit"));
    mybutton->setPos(mybutton->x()+40,mybutton->y()-20);
    QObject::connect(mybutton,SIGNAL(clicked()),&a,SLOT(quit()));
     //creat a restart button
    button *mybutton_restart;
    mybutton_restart =new button(QString("restart"));
    mybutton_restart->setPos(mybutton_restart->x()+100,mybutton_restart->y()-20);

    //creat a scene
   scene=new QGraphicsScene();

    //creat an item to add to the scene
    myCircle= new mycircle();
    myCircle->setRect(-450,0,70,70);

    //add item to the scene
    scene->addItem(myCircle);

    //MAKE THE ITEM FOCUSE
    myCircle->setFlag(QGraphicsItem::ItemIsFocusable);
    myCircle->setFocus();

    //creat a view to visulize the scene
   QGraphicsView *view= new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //show

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(-500,-200,800,600);
    //change background color
    scene->setBackgroundBrush(QBrush(QImage(":/image_load/bg.png")));
    //creat moving face
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),myCircle,SLOT(spawn()));
    timer->start(2000);



     score_graph= new score();
     score_graph->setPos(score_graph->x(),score_graph->y()-150);
     scene->addItem(score_graph);

    myTimer=new mytime();
    myTimer->setPos(myTimer->x(),myTimer->y()-200);
    scene->addItem(myTimer);
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),myCircle,SLOT(countdown()));
    timer2->start(1000);
    QTimer::singleShot(35000,&a,SLOT(quit()));

    QTimer::singleShot(30000,scene,SLOT(clear()));
    //setup close scene
     finalscore =new score();

     finalscore->setPos(finalscore->x()-70,finalscore->y()-50);
     QGraphicsScene  *closescene=new QGraphicsScene();
     closescene->setSceneRect(-250,-200,400,300);
     QGraphicsView *closeview= new QGraphicsView(closescene);
     closeview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     closeview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      //show
     closeview->setFixedSize(400,300);
     closescene->addItem(finalscore);
     closescene->addItem(mybutton);
     closescene->addItem(mybutton_restart);
     QTimer::singleShot(30000,closeview,SLOT(show()));
   // closeview->show();
     QObject::connect(mybutton_restart,SIGNAL(clicked()),restartCircle,SLOT(start_again()));



    return a.exec();
}

