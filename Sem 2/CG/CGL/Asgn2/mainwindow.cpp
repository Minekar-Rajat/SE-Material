#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::draw(float xc,float yc,float x,float y)
{
    img.setPixel(xc+x,yc+y,qRgb(250,250,250));
    img.setPixel(xc+x,yc-y,qRgb(250,250,250));
    img.setPixel(xc+y,yc-x,qRgb(250,250,250));
    img.setPixel(xc+y,xc+x,qRgb(250,250,250));
    img.setPixel(xc-x,yc+y,qRgb(250,250,250));
    img.setPixel(xc-x,yc-y,qRgb(250,250,250));
    img.setPixel(xc-y,yc+x,qRgb(250,250,250));
    img.setPixel(xc-y,yc-x,qRgb(250,250,250));
}





void MainWindow::dda_circle(float xc, float yc, float r)
{
    float i=0,x1=r,y1=0,x2,y2;
    float sx=x1;
    float e;
    float sy=y1;
    e=(1.0)/r;

    do
    {
        x2=x1+e*y1;
        y2=y1-e*x2;
        img.setPixel(xc+x2,yc-y2,qRgb(250,150,150));
        x1=x2;
        y1=y2;


    }while((y1-sy)<e || (sx-x1) > e);

}


void MainWindow::Bresenham_circle(float xc, float yc, float r)
{
    float x=0,y=r,p=3-2*r;

    while(x<=y)
    {

        draw(xc,yc,x,y);
        if(p<0)
        {
            p=p+4*x+6;
        }
        else
        {
            p=p+4*(x-y)+10;
            y=y-1;
        }



        x=x+1;
    }
}


void MainWindow::dda_line(int x1, int y1, int x2, int y2)
{
    float dx,dy,len,xinc,yinc,x,y,i;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
    }
    xinc=dx/len;
    yinc=dy/len;
    x=x1;
    y=y1;
    i=0;
    while(i<len)
    {
        img.setPixel(x,y,qRgb(250,50,50));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}





void MainWindow::on_pushButton_clicked()
{
    float xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    dda_circle(xc,yc,r);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    float xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    Bresenham_circle(xc,yc,r);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dda_line(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked()
{
   //call all functions
    dda_line(250,50,77,350);
    dda_line(77,350,423,350);
    dda_line(250,50,423,350);
    Bresenham_circle(250,250,200);
    dda_circle(250,250,100);
    ui->label->setPixmap(QPixmap::fromImage(img));
}







