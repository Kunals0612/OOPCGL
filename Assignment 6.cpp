#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QTextEdit>
#include<QImage>
#include<QPixmap>
#include<QLine>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage img(500,500,QImage::Format_RGB888);
void MainWindow::paintEvent(QPaintEvent *event)
{
   Q_UNUSED(event);
   QPainter qp(this);
   myFunction(&qp);
}
void MainWindow::myFunction(QPainter *qp)
{
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(200,200,200,350);
    qp->drawLine(200,350,350,350);
    qp->drawLine(350,350,350,200);
    qp->drawLine(350,200,200,200);
    float x1,y1,x2,y2;
    char c[4],d[4];
    x1=250;
    y1=300;
    x2=450;
    y2=450;
    float m = ((y2-y1)/(x2-x1));
    code(c,x1,y1);
    code(d,x2,y2);
    clipping(c,d,x1,y1,m);
    clipping(d,c,x2,y2,m);
    qp->setPen(QPen(Qt::blue));
    qp->drawLine(x1,y1,x2,y2);


}
void MainWindow:: code(char c[4],float x,float y)
{
    c[0] = (x<200)?'1':'0';
    c[1] = (x>350)?'1':'0';
    c[2] = (y<200)?'1':'0';
    c[3] = (y>350)?'1':'0';
}
void MainWindow :: clipping(char c[],char d[],float &x,float &y,float m)
{
    int flag = 0;
    int i;
    for(i=0;i<4;i++)
    {
        if(c[i]!='0' && d[i]!='0')
        {
            flag = 1;
            break;
        }
        if(flag==0)
        {
            if(c[0]!='0')
            {
                x=((200-y)/m)+x;
                y=200;
            }
            else if(c[1]!='0')
            {
                x=((350-y)/m)+x;
                y=350;
            }
            else if(c[2]!='0')
            {
                y=(m*(350-x))+y;
                x=350;
            }
            else if(c[3]!='0')
            {
                y=(m*(200-x)+y);
                x=200;
            }
        }
    }

}
#ifndef MAINWINDOW_H

#define MAINWINDOW_H



#include <QMainWindow>



QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE



class MainWindow : public QMainWindow

{

    Q_OBJECT



public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();



private:

    Ui::MainWindow *ui;

    QString myFilename;



     void paintEvent(QPaintEvent *event);

     void myFunction(QPainter *qp);

     void code(char c[4],float x,float y);

     void clipping(char c[],char d[],float &x,float &y,float m);

};

#endif // MAINWINDOW_H

