//============================================================================
// Name        : TBT.cpp
// Author      : ameya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		int lbit,rbit;
		node *left,*right;
		node(int x)
		{
			data=x;
			lbit=rbit=1;
			left=right=NULL;
		}

};

class TBT
{
	node *root;

	public:
		TBT()
		{
			root=new node(-1);
			root->left=root->right=root;
		}
		void create();
		void create_rec(node *,int);
		void preorder();
		node* pre_succ(node *);
		node* in_succ(node *);
		void inorder();
};

void TBT::create()
{
	create_rec(root,0);
}

void TBT::create_rec(node *father,int child)
{
	int x;
	node *T;
	cout<<"\n\n\tEnter Data or -1	:	";
	cin>>x;
	if(x==-1)
	{
		return ;
	}
	T=new node(x);
	if(child==0)
	{

		T->right=father;
		T->left=father->left;
		father->left=T;
		father->lbit=0;
	}
	else
	{

		T->left=father;
		T->right=father->right;
		father->right=T;
		father->rbit=0;
	}

	cout<<"\n\n\tEnter left of "<<x<<"	:	";
	create_rec(T,0);

	cout<<"\n\n\tEnter right of "<<x<<"	:	";
	create_rec(T,1);

}


void TBT::preorder()
{
	node *T;
	T=root->left;

	while(T!=root)
	{
		cout<<"\t"<<T->data;
		T=pre_succ(T);
	}
}

node* TBT::pre_succ(node *T)
{
	if(T->lbit==0)
	{
		return T->left;
	}
	while(T->rbit==1 && T!=root)
	{
		T=T->right;
	}
	return T->right;
}





void TBT::inorder()
{
	node *T;
	T=root->left;
	while(T->lbit==0)
	{
		T=T->left;
	}
	while(T!=root)
	{
		cout<<"\t"<<T->data;
		T=in_succ(T);
	}
}

node* TBT::in_succ(node *T)
{
	if(T->rbit==1)
	{
		return T->right;
	}
	if(T->rbit==0)
	{
		T=T->right;
	}
	while(T->lbit==0)
	{
		T=T->left;
	}
	return T;



}





int main()
{
	TBT t;
	int ch;
	int flag=0;
	cout<<"\n\n\t----------------Threaded Binary Tree---------------------";
	do
		{
			cout<<"\n\n\n\t1.Create Tree			\
					\n\t2.Preorder Traversal		\
					\n\t3.Inorder Traversal			\
					\n\t0.Exit				";


			cout<<"\n\n\tEnter your choice	:	";
			cin>>ch;

			switch(ch)
			{
				case 1:
					if(flag==0)
					{
						t.create();
						flag=1;
					}
					else
					{
						cout<<"\n\n\tTree is already created  ";
					}
					break;

				case 2:
					if(flag==1)
					{
						cout<<"\n\n\tPreorder	:	\n\n\t";
						t.preorder();
					}
					else
					{
						cout<<"\n\n\tCreate a Tree First ";
					}
					break;

				case 3:
					if(flag==1)
					{
						cout<<"\n\n\tInorder	:	\n\n\t";
						t.inorder();
					}
					else
					{
						cout<<"\n\n\tCreate a Tree First ";
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




