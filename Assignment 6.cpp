#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMouseEvent"
#include "QColorDialog"
using namespace std;
QImage image(500,500,QImage::Format_RGB888);
QColor color;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    ver = 0;
    boundary();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dda(float x1, float y1, float x2, float y2){
    double dx = x2-x1;
    double dy = y2-y1;
    double length;
    if (abs(dx)>abs(dy)){
        length = abs(dx);
    }
    else{
        length = abs(dy);
    }
    double xinc = dx/length;
    double yinc = dy/length;
    double x = x1;
    double y = y1;
    int i = 0;
    while(i<length){
        image.setPixel(x,y,qRgb(255,165,0));
        x = x+xinc;
        y = y+yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::boundary(){
    dda(x_min,y_min,x_max,y_min);
    dda(x_min,y_min,x_min,y_max);
    dda(x_min,y_max,x_max,y_max);
    dda(x_max,y_max,x_max,y_min);
}

void MainWindow::clear(){
//    for(int i=0; i<500; i++){
//        for(int j=0; j<500; j++){
//            image.setPixel(i,j,qRgb(0,0,0));
//        }
//    }
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(start){
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[ver] = p;
        b[ver] = q;
        if(ver>0 && ver%2!=0){
            dda(a[ver],b[ver],a[ver-1],b[ver-1]);
        }
        if(ev->button()==Qt::RightButton){
            start = false;
        }
        ver ++;
    }
}

int MainWindow::compute(double x, double y){
    int code = inside;

    if (x<x_min){
        code|=left;
    }
    else if(x>x_max){
        code|=right;
    }
    if (y<y_min){
        code|=bottom;
    }
    else if(y>y_max){
        code|=top;
    }
    return code;
}

void MainWindow::clipp(double x1, double y1, double x2, double y2){
    int code1 = compute(x1, y1);
    int code2 = compute(x2, y2);

    bool accept = false;

    while(true){
        if((code1 == 0) && (code2 == 0)){
            accept = true;
            break;
        }

        else if (code1 & code2){
            break;
        }

        else{
            int code_out;
            double x, y;

            if(code1 != 0){
                code_out = code1;
            }
            else{
                code_out = code2;
            }
            if(code_out & top){
                y = y_max;
                x = x1 + (x2-x1)*(y_max-y1)/(y2-y1);
            }
            else if(code_out & bottom){
                y = y_min;
                x = x1 + (x2-x1)*(y_min-y1)/(y2-y1);
            }
            else if (code_out & right){
                x = x_max;
                y = y1 + (y2-y1)*(x_max-x1)/(x2-x1);
            }
            else if (code_out & left){
                x = x_min;
                y = y1 + (y2-y1)*(x_min-x1)/(x2-x1);
            }
            if(code_out == code1){
                x1=x;
                y1=y;
                code1 = compute(x1,y1);
            }
            else{
                x2=x;
                y2=y;
                code2 = compute(x2,y2);
            }
        }
    }
    if(accept){
        dda(x1,y1,x2,y2);
    }

}

void MainWindow::on_pushButton_clicked()
{
    clear();
    boundary();
    for(int i=1; i<=ver; i++){
        if(i%2!=0){
            clipp(a[i],b[i],a[i-1],b[i-1]);
        }
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clear();
    void boundary();
    void dda(float, float, float, float);
    void clipp(double, double, double, double);
    void mousePressEvent(QMouseEvent *);
    int compute(double, double);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool start;
    int ver;
    int a[10];
    int b[10];

    const int inside = 0;
    const int left = 1;
    const int right = 2;
    const int bottom = 4;
    const int top = 8;

    const int x_max = 400;
    const int x_min = 100;
    const int y_max = 400;
    const int y_min = 100;
};

#endif // MAINWINDOW_H
