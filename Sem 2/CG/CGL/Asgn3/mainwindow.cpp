#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage img(500,500,QImage::Format_RGB888);
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

void MainWindow::on_pushButton_clicked()   //dotted
{  int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    x2=ui->textEdit_2->toPlainText().toInt();
    y1=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaline(x1,y1,x2,y2);

}
void MainWindow::ddaline(int x1, int y1, int x2, int y2)  //dotted
{
   float dx=x2-x1;
   float dy=y2-y1;

   float len,xinc,yinc;
   if(abs(dx)>=abs(dy))
       len=abs(dx);
   else
       len=abs(dy);
   xinc=dx/len;
   yinc=dy/len;
   float x,y;
   x=x1;
   y=y1;


   int i=0;
   while(i<len)
   {   if(i%2==0)
        {
           img.setPixel(x,y,qRgb(255,255,255));
         }
       x=x+xinc;
       y=y+yinc;
       i++;
   }


   ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked()     //solid
{
    int x1,y1,x2,y2;
        x1=ui->textEdit->toPlainText().toInt();
        x2=ui->textEdit_2->toPlainText().toInt();
        y1=ui->textEdit_3->toPlainText().toInt();
        y2=ui->textEdit_4->toPlainText().toInt();

        ddaline1(x1,y1,x2,y2);
 }

void MainWindow::ddaline1(int x1, int y1, int x2, int y2)   //solid
{
   float dx=x2-x1;
   float dy=y2-y1;

   float len,xinc,yinc;
   if(abs(dx)>=abs(dy))
       len=abs(dx);
   else
       len=abs(dy);
   xinc=dx/len;
   yinc=dy/len;
   float x,y;
   x=x1;
   y=y1;


   int i=0;
   while(i<len)
   {
       img.setPixel(x,y,qRgb(255,255,255));
       x=x+xinc;
       y=y+yinc;
       i++;
   }

 ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()    //dash-dot
{   int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    x2=ui->textEdit_2->toPlainText().toInt();
    y1=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaline2(x1,y1,x2,y2);


}
void MainWindow::ddaline2(int x1, int y1, int x2, int y2)   //dash-dot
{   int s=0,k=0,j=1;
   float dx=x2-x1;
   float dy=y2-y1;

   float len,xinc,yinc;
   if(abs(dx)>=abs(dy))
       len=abs(dx);
   else
       len=abs(dy);
   xinc=dx/len;
   yinc=dy/len;
   float x,y;
   x=x1;
   y=y1;


   int i=0;
   while(i<len)
   {   if(k%2==0)
       {   s=0;
           while(s<2)
           {
               if(s%2==0)
               {
                   img.setPixel(x,y,qRgb(255,255,255));
                   x=x+xinc;
                   y=y+yinc;
               }
               s++;

           }
           k++;
           x=x+3*xinc;
           y=y+3*yinc;
       }
       else if(k%2!=0)
       { j=1;
           while(j%4!=0)
           {
               img.setPixel(x,y,qRgb(255,255,255));
               j++;
               x=x+xinc;
               y=y+yinc;
           }
           k++;
           x=x+3*xinc;
           y=y+3*yinc;
       }

       i++;
   }

 ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()   //dash
{
    int x1,y1,x2,y2;
        x1=ui->textEdit->toPlainText().toInt();
        x2=ui->textEdit_2->toPlainText().toInt();
        y1=ui->textEdit_3->toPlainText().toInt();
        y2=ui->textEdit_4->toPlainText().toInt();

        ddaline3(x1,y1,x2,y2);
}
void MainWindow::ddaline3(int x1, int y1, int x2, int y2)   //dash
{
   float dx=x2-x1;
   float dy=y2-y1;

   float len,xinc,yinc;
   if(abs(dx)>=abs(dy))
       len=abs(dx);
   else
       len=abs(dy);
   xinc=dx/len;
   yinc=dy/len;
   float x,y;
   x=x1;
   y=y1;


   int i=0;
   while(i<len)
   {   if(i%4!=0)
        {
         img.setPixel(x,y,qRgb(255,255,255));
        }
       x=x+xinc;
       y=y+yinc;
       i++;
   }

 ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_5_clicked()  //thick
{
    int x1,y1,x2,y2;
    float w,wy,wx;
        x1=ui->textEdit->toPlainText().toInt();
        x2=ui->textEdit_2->toPlainText().toInt();
        y1=ui->textEdit_3->toPlainText().toInt();
        y2=ui->textEdit_4->toPlainText().toInt();
        w=ui->textEdit_5->toPlainText().toInt();



        if((y2-y1) < (x2-x1))
        {
            wy=((w-1)/2)* ( (sqrt(pow((x2-x1),2) + pow((y2-y1),2)) ) / abs(x2-x1) );
            for(int i=0;i<wy;i++)
            {
                ddaline4(x1,y1+i,x2,y2+i);
                ddaline4(x1,y1-i,x2,y2-i);
            }

        }
        else
        {
            wx=((w-1)/2)* ( (sqrt(pow((x2-x1),2) + pow((y2-y1),2)) ) / abs(x2-x1) );
            for(int i=0;i<wx;i++)
            {
                ddaline4(x1+i,y1,x2+i,y2);
                ddaline4(x1-i,y1,x2-1,y2);
            }

        }
        //ddaline4(x1,y1,x2,y2);

}
void MainWindow::ddaline4(int x1, int y1, int x2, int y2)   //thick
{
   float dx=x2-x1;
   float dy=y2-y1;

   float len,xinc,yinc;
   if(abs(dx)>=abs(dy))
       len=abs(dx);
   else
       len=abs(dy);
   xinc=dx/len;
   yinc=dy/len;
   float x,y;
   x=x1;
   y=y1;


   int i=0;
   while(i<len)
   {

         img.setPixel(x,y,qRgb(255,255,255));

       x=x+xinc;
       y=y+yinc;
       i++;
   }

 ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_6_clicked()
{
    ddaline(100,30,200,30);
    ddaline1(100,60,200,60);
    ddaline2(100,90,200,90);
    ddaline3(100,120,200,120);

}
