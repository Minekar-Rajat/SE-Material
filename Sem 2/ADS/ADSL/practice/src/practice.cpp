//============================================================================
// Name        : practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class sll
{
	class node
	{
		int data;
		node *next;

	public:
		node(int x)
		{
			data=x;
			next=NULL;
		}
		int getdata()
		{
			return data;
		}
		node* getnext()
		{
			return next;
		}
		void setnext(node *q)
		{
			next=q;
		}
	};

	node *head;

public :
	sll()
	{
		head=NULL;
	}
	void create();
	void show();
	int count();
	void addatbeg(int );
	void addatend(int );
	void addatpos(int ,int );


};

void sll::create()
{
	int x;
	node *p,*q;
	cout<<"\n\n\tEnter data for 1st Node or 0(to stop)	:	";
	cin>>x;
	if(x==0)
	{
		return ;
	}
	head=new node(x);
	p=head;
	while(1)
	{
		cout<<"\n\n\tEnter data for next node or 0(to stop)	:	";
		cin>>x;
		if(x!=0)
		{
			q=new node(x);
			p->setnext(q);
		}
		else
		{
			break;
		}
		p=p->getnext();
	}

}

void sll::show()
{
	node *p;
	p=head;
	cout<<"\n\n\tLinked List is	:	";
	if(head==NULL)
	{
		cout<<"\n\n\tList is Empty";
	}
	else
	{
		while(p!=NULL)
		{
			cout<<"\n\n\tData	:	"<<p->getdata();
			p=p->getnext();
		}
	}
}

int sll::count()
{
	int cnt=0;
	node *p;
	p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->getnext();
	}
	return cnt;
}

void sll::addatpos(int x,int pos)
{
	int c;
	c=count();
	node *p,*q,*r;

	if(pos<1 || pos>c+1)
	{
		cout<<"\n\n\tPosition is Invalid";
	}
	else if(pos==1)
	{
		addatbeg(x);
	}
	else if(pos==c+1)
	{
		addatend(x);
	}
	else
	{
		p=head;
		c=count();
		for(int i=1;i<c;i++)
		{
			q=p;
			p=p->getnext();
		}
		r=new node(x);
		q->setnext(r);
		r->setnext(p);
	}


}

void sll::addatbeg(int x)
{
	node *q;
	q=new node(x);

	if(head!=NULL)
	{
		q->setnext(head);
		head=q;
	}
	else
	{
		head=q;
	}
}

void sll::addatend(int x)
{
	node *p,*q;

	if(head==NULL)
	{
		head=new node(x);
	}
	else
	{
		p=head;
		while(p->getnext()!=NULL)
		{
			p=p->getnext();
		}
		q=new node(x);
		p->setnext(q);
	}
}



int main()
{
	int x,pos,ch;
	sll l1;


	cout<<"\n\n\n\t#Creating a Linked List .........\n";

	l1.create();


	do
	{
		cout<<"\n\t1.Show	\
			   \n\t2.Add at Beg \
			   \n\t3.Add at End \
			   \n\t4.Add at pos \
			   \n\t5.Count	 	\
			   \n\t0.Exit		";
		cout<<"\n\n\tEnter choice	:	";
		cin>>ch;

		switch(ch)
		{
			case 1:
				l1.show();
				break;

			case 2:
				cout<<"\n\n\tEnter an element to add at Beg	:	";
				cin>>x;
				l1.addatbeg(x);
				break;

			case 3:
				cout<<"\n\n\tEnter an element to add at End	:	";
				cin>>x;
				l1.addatend(x);
				break;

			case 4:
				cout<<"\n\n\tEnter an element to add at pos	:	";
				cin>>x;
				cout<<"\tPosition	:	";
				cin>>pos;
				l1.addatpos(x,pos);
				break;

			case 5:
				cout<<"\n\n\tNumber of Elements	:	"<<l1.count();
				break;
			default:
				if(ch!=0)
				{
					cout<<"\n\n\tInvalid Input";
				}

		}
	}while(ch!=0);


	return 0;
}
