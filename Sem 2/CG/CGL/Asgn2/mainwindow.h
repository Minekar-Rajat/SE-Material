#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void Bresenham_circle(float xc,float yc,float r);

    void draw(float xc,float yc,float x,float y);

    void dda_line(int x1, int y1, int x2, int y2);

    void dda_circle(float xc,float yc,float r);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
