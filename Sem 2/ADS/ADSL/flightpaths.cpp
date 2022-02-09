#include<iostream>
#include<string.h>
using namespace std;
//Path from city "u" to "v"

class pathnode
{
	public:
		int v;//index
		float time;
		pathnode *next;
		pathnode(int x,float t)//x-index t-time
		{
			v=x;
			time=t;
			next=NULL;
		}
		
};




class citynode
{
	public:
	string city;
	int u;//index
	citynode *down;
	pathnode *head;
	citynode(string city,int u)
	{
		this->city=city;
		this->u=u;
		down=NULL;
		head=NULL;
		
	}
		
};


class flight
{
	citynode *G;//graph G
	
	public:
		flight();//make G=NULL
		
		void create();//take cities
		
		void show_cities();//show all cities
		
		void addcity(string );//add city to list
		
		void path();//take data to addpath
		void addpath(int,int,float);//add the path
		
		int giveindex(string );//index city mapping 
		string givecity(int );//index city mapping
		
		
		void showpaths();//show all paths
		
		void delete_();	// take data to delete path
		void deletepath(string,string);//finds path 
		pathnode* delete_pathnode(pathnode *,int);//delete the path
		
		
		
		void deletecity();//delete all paths To given city
		citynode* delete_citynode(citynode *,int );//deletes citynode
	
	
		
	
};


flight::flight()
{
	G=NULL;
}

void flight::addcity(string city)
{
	citynode *p;
	
	
	if(G==NULL)
	{
		G=new citynode(city,0);
	}
	else
	{
		p=G;
		while(p->down!=NULL)
		{
			p=p->down;
		}
		p->down=new citynode(city,p->u+1);
		
	}
	
	
	
}

void flight::create()
{
	string city;
	
	cout<<"\n\n\tEnter the List of Cities	:	";
	
	while(1)
	{
		cout<<"\n\n\tEnter City Name(in capital) or -1	:	";
		getline(cin,city);
		if(city=="-1")
		{
			break;
		}
		addcity(city);
	}
	
	
	
}


void flight::show_cities()
{
	citynode *p;
	p=G;
	
	
	cout<<"\n\n\tFlight service Available in the cities	:	";
	if(G==NULL)
	{
		cout<<"\n\n\t\t----Not Available----";
	}
	else
	{
		while(p!=NULL)
		{
			cout<<"\n\n\t\t"<<p->city;	
			p=p->down;		
		}
	}

}


int flight::giveindex(string city)
{
	citynode *p;
	p=G;
	while(p!=NULL)
	{
		if(p->city==city)
		{
			return p->u;
		}
		p=p->down;
	}
	
	return -1;
}


string flight::givecity(int x)//x-index
{
	citynode *p;
	p=G;
	while(p!=NULL)
	{
		if(p->u==x)
		{
			return p->city;
		}
		p=p->down;
	}
	
	return " ";
	
	
	
}




void flight::path()
{
	string source,dest;
	int u,v;
	float time;
	
	
	while(1)
	{
		cout<<"\n\n\tEnter Path :	";
		cout<<"\n\n\tFrom or -1	:	";
		getline(cin,source);
		if(source=="-1")
		{
			break;
		}
		cout<<"\n\n\tTo		:	";
		getline(cin,dest);
		cout<<"\n\n\tTime req.	:	";
		cin>>time;
		cin.ignore(1);
		u=giveindex(source);
		v=giveindex(dest);
		if(u!=-1 && v!=-1 && time>=0)
		{
			addpath(u,v,time);
		}
		else
		{
			break;
		}
			
			
		
	}
	
	
}



void flight::addpath(int u,int v,float time)
{
	citynode *p;
	pathnode *q;
	p=G;
	while(p!=NULL)
	{
		
		if(p->u==u)
		{
			if(p->head==NULL)
			{
				p->head=new pathnode(v,time);
			}
			else
			{
				q=p->head;
				while(q->next!=NULL)
				{
				
					q=q->next;
					
				}
				
				q->next=new pathnode(v,time);
				break;
			}
		}
		
		
		p=p->down;
	}
}



void flight::showpaths()
{
	citynode *p;
	pathnode *q;
	string source,dest;
	p=G;
	
	if(G!=NULL)
	{
		cout<<"\n\n\t---------------- All Flights -----------------";
	}
	
	while(p!=NULL)
	{
		
		
	
		source=givecity(p->u);
		q=p->head;
		while(q!=NULL)
		{
		
			
			dest=givecity(q->v);
			cout<<"\n\n\t\tFrom	:	"<<source;
			cout<<"\n\t\tTo	:	"<<dest;
			cout<<"\n\t\tTime	:	"<<q->time<<" Hrs";
			
			
			q=q->next;
			
		}
		
		p=p->down;
		
		
	}
	
	
	
}




void flight::delete_()
{
	string source,dest;
	cout<<"\n\n\tEnter cities to delete path	:	";
	cout<<"\n\n\tFrom or -1	:	";
	getline(cin,source);
	cout<<"\n\n\tTo or -1	:	";
	getline(cin,dest);
	if(source=="-1" || dest=="-1")
	{
		return ;
	}
	deletepath(source,dest);
}

void flight::deletepath(string source,string dest)
{
	int u,v;
	citynode *p;
	pathnode *q,*r;
	
	
	u=giveindex(source);
	v=giveindex(dest);
	if(u==-1 || v==-1)
	{
		cout<<"\n\n\tNo path Exist";
		return ;
	}
	
	p=G;
	
	while(p!=NULL)
	{
		if(p->u==u)
		{
			p->head=delete_pathnode(p->head,v);
		}
		
		p=p->down;
	}
	
}

pathnode* flight::delete_pathnode(pathnode *q,int v)
{
	pathnode *r;
	if(q==NULL)
	{
		return NULL;
	}
	else if(q->v==v)
	{
		r=q->next;
		delete q;
		return r;
	}
	else
	{
		q->next=delete_pathnode(q->next,v);
		return q;
	}
}


citynode* flight::delete_citynode(citynode *p,int u)
{
	citynode *q;
	if(p==NULL)
	{
		return NULL;
	}
	else if(p->u==u)
	{
		q=p->down;
		delete p;
		return q;
	}
	else
	{
		p->down=delete_citynode(p->down,u);
		return p;
	}
}

void flight::deletecity()
{
	string city;
	int v;
	int cnt=0;
	citynode *p;
	pathnode *q,*r;
	cout<<"\n\n\tEnter city to Delete 	:	";
	getline(cin,city);
	
	v=giveindex(city);
	p=G;
	
	while(p!=NULL)
	{
		
		if(p->city==city)
		{
			
			q=p->head;
			while(q!=NULL)
			{
				r=q->next;
				delete q;
				q=r;
			}
			p->head=NULL;
		}
		else
		{
			p->head=this->delete_pathnode(p->head,v);	
		}
		
		p=p->down;
	}
	G=delete_citynode(G,v);
	p=G;
//	while(p!=NULL)
//	{
//		p->u=cnt;
//		cnt++;
//		p=p->down;
//	}
	
	
}


int main()
{
	flight t;
	t.create();
	cout<<"\n\n\t----------------------------------------------------";
	t.show_cities();
	cout<<"\n\n\t----------------------------------------------------";
	t.path();
	t.showpaths();
	t.delete_();
	t.showpaths();
	cout<<"\n\n\t----------------------------------------------------";
	t.deletecity();
	cout<<"\n\n\t----------------------------------------------------";
	t.show_cities();
	t.showpaths();
	
	
}
