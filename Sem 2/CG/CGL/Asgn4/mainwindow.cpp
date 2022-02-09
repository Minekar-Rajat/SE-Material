#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMouseEvent"
#include"QColorDialog"

QImage img(500,500,QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i=0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    color = QColorDialog::getColor();
}

void MainWindow::mousePressEvent(QMouseEvent *eve)
{
    int p,q;
    if(start)
    {
       p=eve->pos().x();
       q=eve->pos().y();
       ax[i]=p;
       ay[i]=q;

        if(eve->button()==Qt::RightButton)
        {
            Bresenhems(ax[i-1],ay[i-1],ax[0],ay[0]);
            start=false;
        }
        else
        {
            if(i>0)
            {
                Bresenhems(ax[i-1],ay[i-1],ax[i],ay[i]);
            }
        }
        i++;


    }
    ui->label->setPixmap(QPixmap::fromImage(img));

}




int MainWindow::sign(int n)
{
    if(n<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}

void MainWindow::Bresenhems(int x1, int y1, int x2, int y2)
{
    float dx,dy,x,y,i,p;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    i=0;

    x=x1;
    y=y1;

    if(dx>=dy)
    {
        p=2*dy-dx;
        while(i<=dx)
        {
            img.setPixel(x,y,color.rgb());
            if(p<0)
            {
                p=p+2*dy;
            }
            else
            {
                p=p+2*(dy-dx);
                y=y+1*sign(y2-y1);
            }
            x=x+1*sign(x2-x1);
            i++;
        }
    }
    else
    {
        p=2*dx-dy;
        while(i<=dy)
        {
            img.setPixel(x,y,color.rgb());
            if(p<0)
            {
                p=p+2*dx;
            }
            else
            {
                p=p+2*(dx-dy);
                x=x+1*sign(x2-x1);
            }
            y=y+1*sign(y2-y1);
            i++;
        }
    }

}


/* DDA is in Question

void MainWindow::ddaline(int x1, int y1, int x2, int y2)
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
        img.setPixel(x,y,color.rgb());
        x=x+xinc;
        y=y+yinc;
        i++;
    }


}

*/


/*
 *It is in Asgn 5
 *
 * void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QRgb bg = qRgb(0,0,0);
    int p = event->pos().x();
    int q = event->pos().y();
    seedfill(p,q,bg);
    ui->label->setPixmap(QPixmap::fromImage(img));


}

void MainWindow::seedfill(int x, int y, QRgb bg)
{
    QRgb current = img.pixel(x,y);
    if(current==bg)
      {
        img.setPixel(x,y,color.rgb());
        seedfill(x+1,y,bg);
        seedfill(x-1,y,bg);
        seedfill(x,y+1,bg);
        seedfill(x,y-1,bg);
      }
}*/
