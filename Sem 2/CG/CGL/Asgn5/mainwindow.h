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
    void mousePressEvent(QMouseEvent *eve);
    int sign(int n);
    void Bresenhems(int x1, int x2, int y1, int y2);
   // void ddaline(int x1, int y1, int x2, int y2);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void seedfill(int x,int y, QRgb bg);

private:
    Ui::MainWindow *ui;
    int ax[50],ay[50],x1,x2,y1,y2,i;
    bool start;

};

#endif // MAINWINDOW_H

