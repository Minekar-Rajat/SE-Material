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

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    ddaline(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

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
        img.setPixel(x,y,qRgb(250,250,250));
        x=x+xinc;
        y=y+yinc;
        i++;
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    ddaline(x1,y1,x2,y2);
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

void MainWindow::Bresenhams(int x1, int x2, int y1, int y2)
{
    float dx,dy,x,y,j,p;
    dx=x2-x1;
    dy=y2-y1;


    x=x1;
    y=y1;

    if(dx>=dy)
    {
        p=2*dy-dx;
        while(j<=dx)
        {
            img.setPixel(x,y,qRgb(250,250,250));
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
            j++;
        }
    }
    else
    {
        p=2*dx-dy;
        while(j<=dy)
        {
            img.setPixel(x,y,qRgb(250,250,250));
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
            j++;
        }
    }

}
