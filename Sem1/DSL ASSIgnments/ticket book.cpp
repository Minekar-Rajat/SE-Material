//============================================================================
// Name        : ticket.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;


class node
{
public :

	node *next;
	node *prev;
	int seat;
	node(int x)
	{

		next=NULL;
		prev=NULL;
		seat=x;
	}

};




class DCLL
{
	node *head;
	node *rear;
public :

	void create();
	void show();
	void booking(int );
	void cancel(int);
	DCLL()
	{
		head=NULL;
		rear=NULL;
	}



};

void DCLL::create()
{

	node *p;
	head=new node(0);
	head->next=head->prev=head;
	rear=head;
	p=head;

	for(int i=1;i<7;i++)
	{
		p->next=new node(0);
		p->next->prev=p;
		p=p->next;
	}
	rear=p;
	rear->next=head;
	head->prev=rear;


}

void DCLL::show()
{


	node *p;

	p=head;

	do
	{
		cout<<"\t"<<p->seat;
		p=p->next;


	}while(p!=head);
	cout<<"\n\t";


}


void DCLL::booking(int col)
{
	node *p=head;

	if(col<1 ||col>7)
	{
		cout<<"\n\tInvalid input";
		return ;

	}

	else
	{
		for(int i=1;i<col;i++)
		{
			p=p->next;
		}
		if(p->seat==1)
		{
			cout<<"\n\n\tSeat is already booked ";
		}
		else
		{
			p->seat=1;
		}
	}
}


void DCLL::cancel(int col)
{
	node *p=head;

	if(col<1 ||col>7)
	{
		cout<<"\n\tInvalid input";
		return ;

	}

	else
	{
		for(int i=1;i<col;i++)
		{
			p=p->next;
		}
		if(p->seat==0)
		{
			cout<<"\n\n\tSeat is not booked yet";
		}
		else
		{
			p->seat=0;
		}
	}
}

int main()
{

	int row,col,ch;
	DCLL ticket[10];

   for(int i=0;i<10;i++)
   {

	   ticket[i].create();

   }
   cout<<"\n\n\t******** The ticket booking system of Cinemax theater ********\n";
   cout<<"\t--------------------------------------------------------------\n";
   cout<<"\n\n\tBooked(1) & Available(0)  : \n\n\t";
  //cout<<"\n\n\tSeats Initially Not Booked  : \n\n\t";
   for(int i=1;i<=7;i++)
   {
	   cout<<"\t"<<i;
   }
   cout<<"\n\n\t";
   for(int i=0;i<10;i++)
   {

	 cout<<"Row "<<i+1;
	 ticket[i].show();
   }


   do
   {
	   cout<<"\n\n\t 0.Exit           ";
	   cout<<"\n\t 1.Book Seats      ";
	   cout<<"\n\t 2.Cancel booking ";
	   cout<<"\n\t 3.Show seats     ";
	   cout<<"\n\n\tEnter Your Choice  :  ";
	   cin>>ch;

	   switch(ch)
	   {
	   	   case 1 :
	   		   	   cout<<"\n\n\tSeat Booking  :  \n";
	   		   	   cout<<"\n\n\tEnter Row and seat number\n\t";
	   		   	   cin>>row;
	   		   	   cout<<endl;
	   		   	   cout<<"\t";
	   		   	   cin>>col;
	   		   	   if(1<=row && row<=10 && 1<=col && col<=7)
	   		   	   {
	   		   		   ticket[row-1].booking(col);
	   		   	   }
	   		   	   else
	   		   	   {
	   		   		   cout<<"\n\tNo such seats are available\n";
	   		   	   }
	   		   	   break;

	   	   case 2 :
	   		   	   cout<<"\n\n\tCancel Booking :  \n";
	   		   	   cout<<"\n\n\tEnter Row and seat number\n\t";
	   		   	   cin>>row;
	   		   	   cout<<endl;
	   		   	   cout<<"\t";
	   		   	   cin>>col;
	   		   	   if(1<=row && row<=10 && 1<=col && col<=7)
	   		   	   {
	   		   		   ticket[row-1].cancel(col);
	   		   	   }
	   		   	   else
	   		   	   {
	   		   		   cout<<"\n\tNo such seats Exist\n";
	   		   	   }

	   		   	   break;
	   	   case 3 :
	   		   	   cout<<"\n\tCurrent status   :  \n\n\n\t";
	   		   	   for(int i=1;i<=7;i++)
	   		   	   {
	   		   		   cout<<"\t"<<i;
	   		   	   }
	   		   	   cout<<"\n\n\t";
	   		   	   for(int i=0;i<10;i++)
	   		   	   {
	   		   		   cout<<"Row "<<i+1;
	   		   		   ticket[i].show();
	   		   	   }


	   }
   }while(ch!=0);





}
