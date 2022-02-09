#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class node
{
	public:
	int data;
	node *next;
		
		node()
		{
			next=NULL;
		}
		node(int x)
		{
			data=x;
			next=NULL;
		}
	
	
};


class ssl
{
	node *head;
	public:
		ssl()
		{
			head=NULL;
		}
		void create();
		void show();
		int count();
		int search(int);
		void addatbeg(int);
		void addbyprior(int);
		void addbypos(int,int);
		void lastnode();
		void sort();
		void show_rec(node *p);
		void show_rec1()
		{
			show_rec(head);
		}
		void show_rev(node *p);
		void show_rev1()
		{
			show_rev(head);
		}
		
		void deleteatbeg();
		void deleteatend();
		void deleteatpos(int);
		
		
	
	
};

void ssl::create()
{
	node *p;
	int n,x;
	char str[100];
	//cout<<"\n\tEnter no of nodes\n\t";
	//cin>>n;
	cout<<"\n\tEnter data for 1st node or STOP\n\t";
	cin.getline(str,98);
	
	if(strcmp(str,"STOP")==0 || strcmp(str,"stop")==0)
	{
      return ;
    }
	x=atoi(str); 
	
	head=new node(x);  
	p=head;
	
	while(1)
	{
		cout<<"\n\tEnter data for next node or STOP\n\t";
		cin.getline(str,98);
		if(strcmp(str,"STOP")==0 || strcmp(str,"stop")==0)
		{
			break;
		}
		x=atoi(str);
		p->next=new node(x);
	    p=p->next;
		
	}
	
	
}

void ssl::show()
{
	node *p;
	p=head;
	cout<<"\n\n";
	while(p!=NULL)
	{
		cout<<"\t"<<p->data;
		p=p->next;
	}
}

int ssl::count()
{
	int cnt=0;
	node *p;
	p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
		
	}
	return cnt;
	
}

int ssl::search(int x)
{
	node *p;
	p=head;
	
	while(p!=NULL)
	{
		if(p->data==x)
		{
			return 1;
		}
		p=p->next;
	}
	cout<<"\n\tData Not Found";
}

void ssl::addatbeg(int x)
{
	node *p;
	p=new node(x);
	p->next=head;
	head=p;
}

void ssl::addbyprior(int x)
{
	node *p,*q;
	int temp;
	p=new node(x);
	q=head;
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		while(q->next!=NULL && x>q->data)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
		if(q->data > p->data)
		{
			temp=q->data;
			q->data=p->data;
			p->data=temp;
		}
		
	}
	
}

void ssl::lastnode()
{
	node *p;
	p=head;
		if(head==NULL)
	{
		cout<<"\n\tEmpty Linklist";
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		cout<<"\n\tData in last node :  "<<p->data;
		
		
	}
	
}

void ssl::sort()
{
	node *p;
	node *q;
	int temp;
	q=head;
	p=head;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		
		}
		p=p->next;
	}
	
	
}

void ssl::show_rec(node *p)
{

	
	if(p!=NULL)
	{
		cout<<"\n\n\t"<<p->data;
		show_rec(p->next);
		
	}
}

void ssl::show_rev(node *p)
{
	
	
	if(p!=NULL)
	{
		show_rev(p->next);
		cout<<"\n\n\t"<<p->data;
	}
}

void ssl::deleteatbeg()
{
	
	if(head==NULL)
	{
		cout<<"\n\n\tQueue is already empty";
	}
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	
	else
	{
		node *p;
		p=head;
		p=p->next;
		delete head;
		head=p;
		
	}
}


void ssl::deleteatend()
{
	node *p;
	node *q;
		if(head==NULL)
	{
		cout<<"\n\n\tLinklist is already empty";
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


void ssl::deleteatpos(int pos)
{
	node *p;
	node *q;
	int c=count();
	if(pos<1||pos>c)
	{
		cout<<"\n\tDelete can't be performed";
		return ;
	}
	if(pos==1)
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

void ssl::addbypos(int pos,int x)
{
	node *p;
	node *q;
	int i,c;
	c=count();
	if(pos<1 ||pos>c+1)
	{
		cout<<"\n\tInvalid position ";
		return ;
	}
	else if(pos==1)
	{
		addatbeg(x);
	}
	
	else
	{
		q=new node(x);
		p=head;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	}
}

int main()
{
	int n,x,pos,ch,flag=0;
	ssl obj;
	
	
	cout<<"\n\n\t=====================	Queue	========================";
	do
	{

		cout<<"\n\n\t1.Show              ";
		cout<<"\n\t2.Enqueue        	 ";
		cout<<"\n\t3.Dequeue			 ";
		cout<<"\n\t0.Exit                ";
		cout<<"\n\n\tEnter your choice   ";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :
						obj.show();
						break;
			case 2 :
				        cout<<"\n\tEnter data to add at end\n\t";
						cin>>x;
						obj.addbyprior(x);
						obj.show();
						break;
    		
    		case 3 :
    					obj.deleteatbeg();
    					obj.show();
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

