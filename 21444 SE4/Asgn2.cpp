//============================================================================
// Name        : Dictionary.cpp
// Author      : ameya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
		cout<<"\n\n\t\t--Meaning	:	"<<p->mean;
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
		void addnode(string );
		void delete_(string );
		dict_node* delete_rec(dict_node*,string );
		dict_node* findmin(dict_node*);
		void show_rev();
		void show_recv(dict_node *);
		void count(string);
		int count_rec(dict_node* ,string);

		void height();
		int height_rec(dict_node*);




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

void Dictionary::addnode(string x)
{

	if(x=="-1")
	{
		return ;
	}
	root=insert(root,x);


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
	cout<<"\n\n\n\n\t===================== Dictionary =============================	\n\n\t";
	show_rec(root);
}



void Dictionary::show_rec(dict_node *T)
{
	if(T!=NULL)
	{
		show_rec(T->left);
		//cout<<"\n\n------------------------------------------------------------------------------\n\n\tKeyword		: "<<T->keyword;
		cout<<"\n\n\t"<<T->keyword;
		T->show_mean();
		show_rec(T->right);
	}
}




void Dictionary::show_rev()
{
	cout<<"\n\n\n\n\t===================== Dictionary =============================	\n\n\t";
	show_recv(root);
}



void Dictionary::show_recv(dict_node *T)
{
	if(T!=NULL)
	{
		show_recv(T->right);
		//cout<<"\n\n------------------------------------------------------------------------------\n\n\tKeyword		: "<<T->keyword;
		cout<<"\n\n\t"<<T->keyword;
		T->show_mean();
		show_recv(T->left);
	}
}


void Dictionary::delete_(string key)
{
	root = delete_rec(root,key);


}

dict_node* Dictionary::findmin(dict_node *T)
{
	while(T->left!=NULL)
	{
		T=T->left;
	}
	return T;

}


dict_node* Dictionary::delete_rec(dict_node *T,string key)
{
	dict_node *q;
	if(T==NULL)
	{

		return NULL;
	}
	else if(T->keyword>key)
	{
		T->left=delete_rec(T->left,key);
		return T;
	}
	else if(T->keyword<key)
	{
		T->right=delete_rec(T->right,key);
		return T;
	}
	else
	{
		if(T->left==NULL && T->right==NULL)
		{
			delete T;
			return NULL;
		}
		else if(T->left==NULL)
		{
			q=T->right;
			delete T;
			return q;
		}
		else if(T->right==NULL)
		{
			q=T->left;
			delete T;
			return q;
		}
		else
		{
			q=findmin(T->right);
			T->keyword=q->keyword;
			T->right=delete_rec(T->right,T->keyword);
			return T;
		}



	}



}

void Dictionary::count(string key)
{
	int cnt;

	cnt=count_rec(root,key);

	cout<<"\n\n\tNumber of Comparisions are	:	"<<cnt;


	cout<<"\n\n\tHeight of keyword	---	"<<key<<"	:	"<<cnt;

}


int Dictionary::count_rec(dict_node *T,string key)
{
	if(T==NULL)
	{
		return 0;
	}
	else if(T->keyword>key)
	{
		return 1+count_rec(T->left,key);
	}
	else if(T->keyword<key)
	{
		return 1+count_rec(T->right,key);
	}
	else
	{
		return 1;
	}



}

void Dictionary::height()
{
	cout<<"\n\n\tHeight of Dictionary Tree 	:	"<<height_rec(root);

}

int Dictionary::height_rec(dict_node *T)
{
	int x,y;



	if(T!=NULL)
	{
		x=height_rec(T->left);
		y=height_rec(T->right);

		if(x>y)
		{
			return 1+height_rec(T->left);
		}
		else
		{
			return 1+height_rec(T->right);
		}


	}
	return 0;
}




int main()
{
	Dictionary t;
	string x;
	int flag=0;
	int ch;



	do
		{
			cout<<"\n\n\n\t1.Create Dictionary		\
					\n\t2.Show Dictionary			\
					\n\t3.Show Dictionary Descending\
					\n\t4.Add Keyword				\
					\n\t5.Delete Keyword			\
					\n\t6.Update meaning of Keyword \
					\n\t7.Count No. of Comparisions	\
					\n\t8.Height					\
					\n\t0.Exit				";


			cout<<"\n\n\tEnter your choice	:	";
			cin>>ch;

			switch(ch)
			{
				case 1:
					if(flag==0)
					{
						cout<<"\n\n\t--------------------- Create A Dictionary --------------------------\n\n\t";
						cin.ignore(1);
						t.create();
						flag=1;
					}
					else
					{
						cout<<"\n\n\tDictionary is already created  ";
					}
					break;

				case 2:
					if(flag==1)
					{
						t.show();
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;

				case 3:
					if(flag==1)
					{
						cout<<"\n\n\tDictionary in Descending order 	:	";
						t.show_rev();
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;

				case 4:
					if(flag==1)
					{
						cin.ignore(1);
						cout<<"\n\n\tEnter Keyword to add or -1	:	";
						getline(cin,x);
						t.addnode(x);
						t.show();
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;




				case 5:
					if(flag==1)
					{
						cin.ignore(1);
						cout<<"\n\n\tEnter Keyword To Delete 	:	";
						getline(cin,x);
						t.delete_(x);
						t.show();
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;



				case 6:
						if(flag==1)
						{
							cin.ignore(1);
							cout<<"\n\n\tEnter Keyword which wanted to Update 	:	";
							getline(cin,x);
							t.delete_(x);
							t.addnode(x);
							t.show();
						}
						else
						{
							cout<<"\n\n\tCreate a Dictionary First ";
						}
						break;



				case 7:
					if(flag==1)
					{
						cin.ignore(1);
						cout<<"\n\n\tEnter Keyword to find count of comparision	:	";
						getline(cin,x);
						t.count(x);
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;


				case 8:
					if(flag==1)
					{
						t.height();
					}
					else
					{
						cout<<"\n\n\tCreate a Dictionary First ";
					}
					break;

				default:
					if(ch!=0)
					{
						cout<<"\n\n\t\tWrong Input";
					}


			}



		}while(ch!=0);









}
