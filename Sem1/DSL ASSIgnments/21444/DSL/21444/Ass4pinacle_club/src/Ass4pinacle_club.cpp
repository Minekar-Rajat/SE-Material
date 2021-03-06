//============================================================================
// Name        : Ass4pinacle_club.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Add and delete the members as well as president or even secretary.
Compute total number of members of club
Display members
Display list in reverse order using recursion
Two linked lists exists for two divisions. Concatenate two lists Sort the singly linked list. */

#include <iostream>
#include<string.h>
using namespace std;

class node
{
public:
	int PRN;
	char name[20];
	node *next;

	node(char *nm,int x)
	{
		PRN=x;
		strcpy(name,nm);
		next=NULL;
	}

};


class sll
{
	node *head;

public:
	sll()
	{
		head=NULL;
	}

	void create();
	int count();
	void show();
	void show_rev(node *);
	void show_rev1(node *head)
	{
		show_rev(head);
	}
	void addatbeg(char *,int );
	void addbypos(int ,char *,int);
	void addatend(char *,int );
	void addbeforesec(char *,int );
	void deleteatbeg();
	void deleteatend();
	void deleteatpos(int );



};

void sll::create()
{
	char str[20];
	int x,n;
	cout<<"\n\n\tEnter data for President  :  ";
	cout<<"\n\n\tEnter NAME   :   ";
	cin.ignore(1);
	cin.getline(str,19);
	cout<<"\n\tEnter PRN    :   ";
	cin>>x;
	cin.ignore(1);
	head=new node(str,x);

	cout<<"\n\n\tEnter data for Secretary  :  ";
	cout<<"\n\n\tEnter NAME   :   ";
	cin.getline(str,19);
	cout<<"\n\tEnter PRN    :   ";
	cin>>x;
	cin.ignore(1);
	head->next=new node(str,x);


	cout<<"\n\tHow many Members  :  ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin.ignore(1);
		cout<<"\n\n\tEnter data for member  :  ";
		cout<<"\n\n\tEnter NAME   :   ";
		cin.getline(str,19);
		cout<<"\n\tEnter PRN    :   ";
		cin>>x;
		cin.ignore(1);
		addbeforesec(str,x);
	}
}

void sll::show()
{
	int c=0;
	node *p;
	node *q,*r;
	p=head;
	q=head->next;
	if(p!=NULL)
	{
		c++;
		cout<<"\n\n\tMembers Of PINACLE CLUB   :   \n\n\n";
		cout<<"\tMember No "<<"   Information   \n";
		cout<<"\n\t"<<c<<"\t     President : "<<p->name<<"\n\t\t     PRN       :  "<<p->PRN<<"\n\t";

	if(q->next!=NULL)
	{
		while(q->next!=NULL)
		{
			r=q;
			c++;
			cout<<"\n\t"<<c<<"\t     Members   : "<<r->name<<"\n\t\t     PRN       :  "<<r->PRN<<"\n\t";
			q=q->next;
		}
	}
//	q=head->next;
//	while(q->next!=NULL)
//	{
//		q=q->next;
//	}
	if(head->next!=NULL)
	{
		c++;
		cout<<"\n\t"<<c<<"\t     Secretary : "<<q->name<<"\n\t\t     PRN       :  "<<q->PRN<<"\n\n\t";
	}
	}
	else
	{
		cout<<"\n\n\tList is empty  ";
	}
}

int sll::count()
{
	node *p;
	int cnt=0;
	p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

void sll::show_rev(node *p)
{
	cout<<"\n\n\nMembers Of PINACLE CLUB   :   \n\n\n";
	if(p!=NULL)
	{
		show_rev(p->next);
		cout<<"\n\tMembers   : "<<p->name<<"   PRN  :  "<<p->PRN<<"\n\t";

	}
}

void sll::addatbeg(char *nm,int prn)
{
	node *q;
	q=new node(nm,prn);
	q->next=head;
	head=q;

}

void sll::addbypos(int pos,char *nm,int prn)
{
	int c;
	node *p;
	node *q;
	c=count();
	if(pos<1 || pos>c+1)
	{
		cout<<"\n\n\tInvalid Position";
	}
	else if(pos==1)
	{
		addatbeg(nm,prn);
	}
	else
	{
		q=new node(nm,prn);
		p=head;
		for(int i=1;i<pos-1;pos++)
		{
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	}

}

void sll::addatend(char *nm,int prn)
{
	node *p;
	node *q;
	q=new node(nm,prn);
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;

}

void sll::addbeforesec(char *nm,int prn)
{
	node *p;
	node *q,*r;
	q=new node(nm,prn);
	p=head;
	while(p->next!=NULL)
	{
		r=p;
		p=p->next;
	}
	q->next=p;
	r->next=q;

}

void sll::deleteatbeg()
{
	node *p;
	if(head==NULL)
	{
		cout<<"\n\n\tNo Members in club ";
	}
	else if(head->next==NULL)
	{
		p=head;
		head=NULL;
		delete p;
	}
	else
	{
		p=head;
		head=p->next;
		delete p;
	}
}

void sll::deleteatend()
{
	node *p;
	node *q;

	if(head==NULL)
	{
		cout<<"\n\n\tNo Members in club ";
	}
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		delete p;
	}
}


void sll::deleteatpos(int pos)
{
	int c=count();
	node *p;
	node *q;
	if(pos<1 || pos>c)
	{
		cout<<"\n\n\tInvalid Position";
	}
	else if(pos==1)
	{
		deleteatbeg();
	}
	else
	{
		p=head;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;

		}
		q=p->next;
		p->next=q->next;
		delete q;
	}

}

int main()
{
	int ch,x;
	char nm[20];
	sll obj;
	//obj.create();
	//obj.show();

	do
	{
		cout<<"\n\n\t 1.Enter data        \
				\n\t 2.Display            \
				\n\t 3.New President      \
				\n\t 4.New Secretary      "; 
		cout<<"\n\t 5.Add Member         \
				\n\t 6.Remove president   \
				\n\t 7.Remove Secretary   \
				\n\t 8.Cancel Memebership \
				\n\t 0.Exit           ";
		cout<<"\n\n\tEnter your choice \n\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
					obj.create();
					break;

			case 2:
					obj.show();
					break;
			case 3:
					cin.ignore(1);
					cout<<"\n\n\tEnter data for new president  :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cin.ignore(1);
					obj.addatbeg(nm,x);
					break;

			case 4:
					cin.ignore(1);
					cout<<"\n\n\tEnter data for new secretary  :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cin.ignore(1);
					obj.addatend(nm,x);
					break;

			case 5:
					cin.ignore(1);
					cout<<"\n\n\tEnter data   :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cin.ignore(1);
					obj.addbeforesec(nm,x);
					break;

			case 6:
					obj.deleteatbeg();
					break;

			case 7:
					obj.deleteatend();
					break;

			case 8:
					obj.show();
					cout<<"\n\n\tEnter Member No to cancel membership \n\t";
					cin>>x;
					obj.deleteatpos(x);
					break;

			default:
					if(ch!=0)
					{
						cout<<"\n\tInvalid Input ";
					}

		}


	}while(ch!=0);

	return 0;
}
