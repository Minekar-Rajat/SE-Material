#include<iostream>
using namespace std;

class mean_node
{
	public:
		string mean;
		mean_node *next;
		mean_node(string x)
		{
			mean=x;
			next=NULL;
		}
		
};



class dict_node
{
	public:
		string keyword;
		mean_node *meaning;
		dict_node *left,*right;
		dict_node(string x)
		{
			keyword=x;
			left=right=NULL;
			create_mean();
		}	
		void create_mean();
		void show_mean();
};

void dict_node::create_mean()
{
	mean_node *p;
	string x;
	
	cout<<"\n\n\n\t\tMeaning			:	";
	getline(cin,x);
	meaning=new mean_node(x);
	p=meaning;
	
	while(1)
	{
		cout<<"\n\n\t\tMeaning	or -1		:	";
		getline(cin,x);
		if(x=="-1")
		{
			break;
		}
		p->next=new mean_node(x);
		p=p->next;	
	}
}


void dict_node::show_mean()
{
	mean_node *p;
	p=meaning;
	while(p!=NULL)
	{
		cout<<"\n\n\t\tMeaning	:	"<<p->mean;
		p=p->next;
	}
}


class Dictionary
{
	dict_node* root;
	public:
		Dictionary()
		{
			root=NULL;
		}
		void create();
		dict_node* insert(dict_node*,string);
		
		void show();
		void show_rec(dict_node *);
	
		
};



void Dictionary::create()
{
	string x;
	while(1)
	{
		cout<<"\n\n\tEnter Keyword or -1	:	";
		getline(cin,x);
		if(x=="-1")
		{
			break;	
		}
		root=insert(root,x);	
	}	
}


dict_node* Dictionary::insert(dict_node *T,string x)
{
	if(T==NULL)
	{
		T=new dict_node(x);
		return T;
	}
	else if(x<T->keyword)
	{
		T->left=insert(T->left,x);
		return T;
	}
	else if(T->keyword<x)
	{
		T->right=insert(T->right,x);
		return T;
	}
	else
	{
		cout<<"\n\n\tDuplicate Keyword	";
		return T;
	}
	
}



void Dictionary::show()
{
	cout<<"\n\n\tDictionary :	\n\n\t";
	show_rec(root);
}



void Dictionary::show_rec(dict_node *T)
{
	if(T!=NULL)
	{
		show_rec(T->left);
		cout<<"\n\tKeyword		:	"<<T->keyword;
		T->show_mean();
		show_rec(T->right);
	}
}


int main()
{
	Dictionary t;
	t.create();
	t.show();
}
