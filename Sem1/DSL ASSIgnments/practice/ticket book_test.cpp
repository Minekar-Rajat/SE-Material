#include<iostream>
using namespace std;


class node 
{
	public	:
		int seat;
		node *prev;
		node *next;
		node(int s=0)
		{
			seat=s;
			next=NULL;
			prev=NULL;
		}
	
};


class cinema_DCLL
{
	node *head;
	node *rear;
	
	public	:
		void create();
		void show();
		void booking(int );
		void cancel_booking(int );
		
		
};

void cinema_DCLL::create()
{
	node *p;
	head=rear=new node(0);
	head->next=head->prev=head;
	p=head;
	for(int i=0;i<6;i++)
	{
		p->next=new node(0);
		p->next->prev=p;
		p=p->next;
		p->next=head;
		rear=p;
	}
	
}

void cinema_DCLL::show()
{
	node *p;
	p=head;
	while(p!=rear)
	{
		cout<<"\t"<<p->seat;
		p=p->next;
	}
	cout<<"\t"<<p->seat;
	
}

void cinema_DCLL::booking(int column)
{
	node *p;
	p=head;
	for(int i=1;i<column;i++)
	{
		p=p->next;
	}
	if(p->seat==1)
	{
		cout<<"\n\tThe seat is already booked , try for another seat ";
		return ;
	}
	else
	{
		p->seat=1;
		cout<<"\n\n\tYour Booking is Successful. ";
	}
}

void cinema_DCLL::cancel_booking(int column)
{
	node *p;
	p=head;
	for(int i=1;i<column;i++)
	{
		p=p->next;
	}
	if(p->seat==0)
	{
		cout<<"\n\tThe seat is not booked yet. ";
		return ;
	}
	else
	{
		p->seat=0;
		cout<<"\n\n\tYour Cancellation of Booking is Successful. ";
	}
}

int main()
{
	int ch,row,column;
	cout<<"\n\n\t==================	Cinemax	Theater	==================\n\n\t";
	cout<<"\n\tintially seats are not booked";
	cout<<"\n\tseat status	:	\n\t\tBooked(1)\n\t\tNot Booked(0)";
	
	cinema_DCLL c[10];
	for(int i=0;i<10;i++)
	{
		c[i].create();
	}
	cout<<"\n\n\n";
	cout<<"\n\tColumn\t\t1	2	3	4	5	6	7\n";
	for(int i=0;i<10;i++)
	{
		cout<<"\n\tRow "<<i+1<<"\t";
		c[i].show();
	}
	
	
	do
	{
		cout<<"\n\n\n\t0.Exit	\
				\n\t1.Show Seats	\
				\n\t2.Book a seat	\
				\n\t3.Cancel booking";
		cout<<"\n\n\tEnter your choice	:	";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :
				cout<<"\n\n\n";
				cout<<"\n\tColumn\t\t1	2	3	4	5	6	7\n";
				for(int i=0;i<10;i++)
				{
					cout<<"\n\tRow "<<i+1<<"\t";
					c[i].show();
				}
				break;
				
			case 2	:
				cout<<"\n\tEnter Row	:	";
				cin>>row;
				cout<<"\n\tEnter Column	:	";
				cin>>column;
				if(row<1 || row >10)
				{
					cout<<"\n\tInvalid Input (No such Row Exist)";
					break;
				}
				else if(column<1 || column>7)
				{
					cout<<"\n\tInvalid Input (No such Column Exist)";
					break;
				}
				c[row-1].booking(column);
				break;
				
			case 3	:
				cout<<"\n\tEnter Row	:	";
				cin>>row;
				cout<<"\n\tEnter Column	:	";
				cin>>column;
				if(row<1 || row >10)
				{
					cout<<"\n\tInvalid Input (No such Row Exist)";
					break;
				}
				else if(column<1 || column>7)
				{
					cout<<"\n\tInvalid Input (No such Column Exist)";
					break;
				}
				c[row-1].cancel_booking(column);
				break;
				
			default	:
				if(ch!=0)
				{
					cout<<"\n\tInvalid Input";
				}
		}
	}while(ch!=0);
	
	
return 0;

	
}
