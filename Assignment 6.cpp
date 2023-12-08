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
QImage img1(500,500,QImage::Format_RGB888);
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dx,dy,xinc,yinc;
    float length;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }else{
        length = abs(dy);
    }

    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    while(i<=length){
        img1.setPixel(x1,y1,qRgb(255,255,255));
        x1+=xinc;
        y1+=yinc;
        i++;
    }
}
void MainWindow::dda1(float x1, float y1, float x2, float y2)
{
    float dx,dy,xinc,yinc;
    float length;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }else{
        length = abs(dy);
    }

    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    while(i<=length){
        img.setPixel(x1,y1,qRgb(255,255,255));
        x1+=xinc;
        y1+=yinc;
        i++;
    }
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
void MainWindow::on_pushButton_clicked()
{
      dda(200,200,200,350);
      dda(200,350,350,350);
      dda(350,350,350,200);
      dda(350,200,200,200);
      float x1,y1,x2,y2;
      char c[4],d[4];
      x1=ui->textEdit->toPlainText().toInt();
      y1=ui->textEdit_2->toPlainText().toInt();
      x2=ui->textEdit_3->toPlainText().toInt();
      y2=ui->textEdit_4->toPlainText().toInt();
      float m = ((y2-y1)/(x2-x1));
      code(c,x1,y1);
      code(d,x2,y2);
      clipping(c,d,x1,y1,m);
      clipping(d,c,x2,y2,m);
      dda(x1,y1,x2,y2);
      ui->label_2->setPixmap(QPixmap::fromImage(img1));
}
void MainWindow::boundary()
{
    float x1,y1,x2,y2;
    dda1(200,200,200,350);
    dda1(200,350,350,350);
    dda1(350,350,350,200);
    dda1(350,200,200,200);
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dda1(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::on_pushButton_2_clicked()
{
    boundary();
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



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;

    QString myFilename;







     void code(char c[4],float x,float y);

     void clipping(char c[],char d[],float &x,float &y,float m);
     void dda(float,float,float,float);
     void dda1(float,float,float,float);
     void boundary();
};

#endif // MAINWINDOW_H
