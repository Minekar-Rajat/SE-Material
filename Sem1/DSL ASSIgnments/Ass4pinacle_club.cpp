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
	int c;
public:
	sll()
	{
		head=NULL;
	}

	void create();
	int count();
	void show(int);
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
	int findpos(int );



};

void sll::create()
{
	char str[20];
	int x;
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


}

void sll::show(int x)
{
	node *p;
	node *q,*r;
	p=head;

	c=0;
	cout<<"\n\t============= Pinacle Club "<<x<<" =============\n";
	if(p!=NULL)
	{
		c++;
		q=head->next;
		cout<<"\n\t"<<c<<"\tPresident : "<<p->name<<"   PRN  :  "<<p->PRN<<"\n\t";
		if(q!=NULL)
		{
			if(q->next!=NULL)
			{
				while(q->next!=NULL)
				{
					r=q;
					c++;
					cout<<"\n\t"<<c<<"\tMembers   : "<<r->name<<"   PRN  :  "<<r->PRN<<"\n\t";
					q=q->next;
				}
			}
			c++;
			cout<<"\n\t"<<c<<"\tSecretary : "<<q->name<<"   PRN  :  "<<q->PRN<<"\n\n\t";
		}
	}
	else
	{
		cout<<"\n\n\t****** List is empty ****** ";
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

int sll::findpos(int prn)
{
	node *p=head;
	int cnt=0;
	if(p==NULL)
	{
		cout<<"\n\n\tEmpty List ";
	}
	else
	{
			p=head;
			while(p!=NULL)
			{
				cnt++;
				if(p->PRN==prn)
				{
					return cnt;
				}
				p=p->next;
			}
	}
	cout<<"\n\n\tInvalid Input PRN ";


}

int main()
{
	int ch,x,prn,n,cnt=0;
	char nm[20];
	sll obj1,obj2;
	//obj.create();
	//obj.show();

	do
	{
		cout<<"\n\n\t 1.Enter data        \
				\n\t 2.Display Club1      \
				\n\t 3.Display Club2      \
				\n\t 4.New President      \
				\n\t 5.New Secretary      \ 
				\n\t 6.Add Member         \
				\n\t 7.Remove president   \
				\n\t 8.Remove Secretary   \
				\n\t 9.Cancel Memebership \
				\n\t 0.Exit           ";
		cout<<"\n\n\tEnter your choice \n\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"\n\tWhich club do you want to join Club1(1) or Club2(2) : ";
					cin>>n;
					if(n==1)
					{
						obj1.create();
					}
					else if(n==2)
					{
						obj2.create();
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}

					break;

			case 2:
					obj1.show(1);

					break;

			case 3:
					obj2.show(2);

					break;
			case 4:
					cin.ignore(1);
					cout<<"\n\n\tEnter data for new president  :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;
					cin.ignore(1);

					if(n==1)
					{
						obj1.addatbeg(nm,x);
					}
					else if(n==2)
					{
						obj2.addatbeg(nm,x);
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}

					break;

			case 5:
					cin.ignore(1);
					cout<<"\n\n\tEnter data for new secretary  :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;
					cin.ignore(1);
					if(n==1)
					{
						obj1.addatend(nm,x);
					}
					else if(n==2)
					{
						obj2.addatend(nm,x);
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}

					break;

			case 6:
					cin.ignore(1);
					cout<<"\n\n\tEnter data   :  ";
					cout<<"\n\n\tEnter NAME   :   ";
					cin.getline(nm,19);
					cout<<"\n\tEnter PRN    :   ";
					cin>>x;
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;
					cin.ignore(1);
					if(n==1)
					{
						obj1.addbeforesec(nm,x);
					}
					else if(n==2)
					{
						obj2.addbeforesec(nm,x);
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}

					break;

			case 7:
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;
					if(n==1)
					{
						obj1.deleteatbeg();
					}
					else if(n==2)
					{
						obj2.deleteatbeg();
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}

					break;

			case 8:
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;
					if(n==1)
					{
						obj1.deleteatend();
					}
					else if(n==2)
					{
						obj2.deleteatend();
					}
					else
					{
						cout<<"\n\tInvalid Input";
					}


					break;

			case 9:
					cout<<"\n\tWhich club ? Club1(1) or Club2(2) : ";
					cin>>n;

					if(n==1)
					{
						cnt=obj1.count();
						if(cnt!=0)
						{
							cout<<"\n\n\tEnter PRN no : ";
							cin>>prn;
							x=obj1.findpos(prn);
							obj1.deleteatpos(x);
						}
						else
						{
							cout<<"\n\n\tList is empty  ";
						}
					}
					else if(n==2)
					{
						cnt=obj2.count();
						if(cnt!=0)
						{
							cout<<"\n\n\tEnter PRN no : ";
							cin>>prn;
							x=obj2.findpos(prn);
							obj2.deleteatpos(x);
						}
						else
						{
							cout<<"\n\n\tList is empty  ";
						}
					}
					else
					{
						cout<<"\n\n\tInvalid Input";
					}

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
