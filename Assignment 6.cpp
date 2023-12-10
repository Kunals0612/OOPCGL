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
