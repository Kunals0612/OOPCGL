mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage image(400, 400, QImage::Format_RGB888);
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
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,w,h;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    w=ui->textEdit_3->toPlainText().toInt();
    h=ui->textEdit_4->toPlainText().toInt();

    dda(x1,y1,x1+w,y1);
    dda(x1,y1,x1,y1+h);
    dda(x1+w,y1,x1+w,y1+h);
    dda(x1,y1+h,x1+w,y1+h);
    dda(x1+w/2,y1,x1,y1+h/2);
    dda(x1+w/2,y1,x1+w,y1+h/2);
    dda(x1+w/2,y1+h,x1+w,y1+h/2);
    dda(x1+w/2,y1+h,x1,y1+h/2);

    double r = (pow((h*h + w*w), 0.5))/4.17;
    circle(x1+w/2,y1+h/2,int(r));
}


void MainWindow::on_pushButton_2_clicked()
{
    int x,y,xc,yc;
    float r;

//    xc=ui->textEdit_5->toPlainText().toInt();
//    yc=ui->textEdit_6->toPlainText().toInt();
//    r=ui->textEdit_7->toPlainText().toInt();

    x=0,y=r;

    double d=3-2*r;

    while(x<=y)
    {
        image.setPixel(x+xc,y+yc,qRgb(0,255,0));
        image.setPixel(-x+xc,y+yc,qRgb(0,255,0));
        image.setPixel(x+xc,-y+yc,qRgb(0,255,0));
        image.setPixel(-x+xc,-y+yc,qRgb(0,255,0));
        image.setPixel(y+xc,x+yc,qRgb(0,255,0));
        image.setPixel(-y+xc,x+yc,qRgb(0,255,0));
        image.setPixel(y+xc,-x+yc,qRgb(0,255,0));
        image.setPixel(-y+xc,-x+yc,qRgb(0,255,0));

        if (d<0)
            d=d+4*x+6;
        else
        {
            d = d+4*(x - y)+10;
            y--;

        }
        x=x+1;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

}
void MainWindow::dda(float x1, float y1, float w, float h)
{


    double dx = w - x1;

    double dy = h - y1;

    double step;

    if (abs(dx) > abs(dy))

    step = abs(dx);

    else

    step = abs(dy);


    double del_x= dx/step;

    double del_y= dy/step;


    double x=x1;

    double y=y1;

    for (int i=0;i<step ; i++)

    {

        image.setPixel(x,y,qRgb(255,0,0));

        x=x+del_x;

        y=y+del_y;

    }

    ui->label->setPixmap(QPixmap::fromImage(image));

}

void MainWindow::circle(float xc,float yc,float r)
{
    int x=0,y=r;

    double d=3-2*r;

    while(x<=y)
    {
        image.setPixel(x+xc,y+yc,qRgb(0,255,0));
        image.setPixel(-x+xc,y+yc,qRgb(0,255,0));
        image.setPixel(x+xc,-y+yc,qRgb(0,255,0));
        image.setPixel(-x+xc,-y+yc,qRgb(0,255,0));
        image.setPixel(y+xc,x+yc,qRgb(0,255,0));
        image.setPixel(-y+xc,x+yc,qRgb(0,255,0));
        image.setPixel(y+xc,-x+yc,qRgb(0,255,0));
        image.setPixel(-y+xc,-x+yc,qRgb(0,255,0));

        if (d<0)
            d=d+4*x+6;
        else
        {
            d = d+4*(x - y)+10;
            y--;

        }
        x=x+1;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


mainwindow.h

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
    void dda(float,float,float,float);
    void circle(float,float,float);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H