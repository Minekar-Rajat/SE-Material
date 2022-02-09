//============================================================================
// Name        : Asgn1.cpp
// Author      : ameya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : Tree.cpp
// Author      : ameya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 100

class node
{
	int data;
	node *left,*right;
public:
	friend class Tree;
	node(int x)
	{
		data=x;
		left=right=NULL;
	}
};

class stacknode
{
public:
	node *link;
	int flag;
};

class stack1
{
	stacknode data1[MAX];
	int top1;
public:
	stack1()
	{
		top1=-1;
	}
	void push1(stacknode);
	stacknode pop1();
	int empty1();
	int full1();

};


void stack1::push1(stacknode T)
{


	if(!full1())
	{
		top1++;
		data1[top1]=T;
	}
	else
	{
		cout<<"\n\n\tStack is Full";
	}

}

stacknode stack1::pop1()
{
	stacknode st;
	st.flag=-1;
	st.link=NULL;
	if(!empty1())
	{
		stacknode T=data1[top1];
		top1--;
		return T;
	}
	else
	{
		cout<<"\n\n\tStack is empty";
		return st;
	}
}

int stack1::empty1()
{
	if(top1==-1)
	{
		return 1;
	}
	return 0;
}

int stack1::full1()
{
	if(top1==MAX-1)
	{
		return 1;
	}
	return 0;
}


//------------------------------

class stack
{
	node* data[MAX];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(node *);
	node* pop();
	int empty();
	int full();

};

void stack::push(node *T)
{

	if(!full())
	{
		top++;
		data[top]=T;
	}
	else
	{
		cout<<"\n\n\tStack is Full";
	}

}
node* stack::pop()
{
	if(!empty())
	{
		node *T=data[top];
		top--;
		return T;
	}
	else
	{
		cout<<"\n\n\tStack is empty";
		return NULL;
	}
}


int stack::empty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}

int stack::full()
{
	if(top==MAX-1)
	{
		return 1;
	}
	return 0;
}







class Tree
{

	node *root;
public:
	Tree()
	{
		root=NULL;
	}
	void create();
	node* create_rec();
	void show();
	void preorder(node*);
	void inorder(node*);
	void postorder(node*);
	void leaf();
	void leaf_rec(node*);
	void internal();
	void internal_rec(node*);
	void delete_();
	void delete_nodes(node*);
	void operator=(Tree &obj);
	void pre_nonrec();
	void in_nonrec();
	void post_nonrec();
	void show_nonrec();
	node* assign(node* ,node*);
	void create_mirror(Tree &);
	node* mirror(node*,node*);
	void equal(Tree &);
	int equal_rec(node*,node*);



};




void Tree::create()
{
	root=this->create_rec();
}

node* Tree::create_rec()
{
	node *p;
	int x;
	cout<<"\n\n\tEnter data or -1(to stop)	:	";
	cin>>x;
	if(x==-1)
	{
		return NULL;
	}
	p=new node(x);

	cout<<"\n\n\tLeft of "<<x<<" :	";
	p->left=this->create_rec();

	cout<<"\n\n\tRight of "<<x<<" :	";
	p->right=this->create_rec();

	return p;
}


void Tree::show()
{
if(root!=NULL)
{	int ch;
  do{
	cout<<"\n\n\n\tSelect Traversal	:	";
	cout<<"\n\n\t1.PreOrder  \
			 \n\t2.InOrder 	 \
			 \n\t3.PostOrder \
			 \n\t0.Exit		";
	cout<<"\n\n\tEnter Choice :	";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\n\n\tPreOrder Traversal	:	\n\n\t";
		this->preorder(root);
		break;

	case 2:
		cout<<"\n\n\tInOrder Traversal	:	\n\n\t";
		this->inorder(root);
		break;

	case 3:
		cout<<"\n\n\tPostOrder Traversal	:	\n\n\t";
		this->postorder(root);
		break;

	default:
		if(ch!=0)
		{
			cout<<"\n\n\t\tWrong Input";
		}
	}
  }while(ch!=0);
}
else
{
	cout<<"\n\n\n\t\t -----Empty Tree-----";
}
}


void Tree::preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<"\t"<<p->data;
		this->preorder(p->left);
		this->preorder(p->right);
	}
}

void Tree::inorder(node *p)
{
	if(p!=NULL)
	{
		this->inorder(p->left);
		cout<<"\t"<<p->data;
		this->inorder(p->right);
	}
}

void Tree::postorder(node *p)
{
	if(p!=NULL)
	{
		this->postorder(p->left);
		this->postorder(p->right);
		cout<<"\t"<<p->data;
	}

}


void Tree::leaf()
{
	if(root!=NULL)
	{cout<<"\n\n\n\tLeaf nodes :	\n\n\t\t";
	this->leaf_rec(root);
	}
	else
	{
		cout<<"\n\n\t\t-----Empty Tree-----";
	}
}

void Tree::leaf_rec(node*p)
{
	if(p->left==NULL && p->right==NULL)
	{
		cout<<"\t"<<p->data;

		return ;
	}
	if(p->left!=NULL)
	{
		leaf_rec(p->left);
	}
	if(p->right!=NULL)
	{
		leaf_rec(p->right);
	}
}

void Tree::internal()
{
	if(root!=NULL)
	{
		cout<<"\n\n\n\tInternal nodes :	\n\n\t\t";
		this->internal_rec(root);
	}

	else
	{
			cout<<"\n\n\t\t-----Empty Tree-----";
	}
}

void Tree::internal_rec(node *p)
{
	if(p->left!=NULL || p->right!=NULL)
	{
		cout<<"\t"<<p->data;
		if(p->left!=NULL)
		{
			internal_rec(p->left);
		}
		if(p->right!=NULL)
		{
			internal_rec(p->right);
		}


	}

}

void Tree::delete_()
{
	delete_nodes(root);
}



void Tree::delete_nodes(node *T)
{
	node *l,*r;

	if(T!=NULL)
	{
		l=T->left;
		r=T->right;
		delete T;
		delete_nodes(l);
		delete_nodes(r);

	}

}

void Tree::operator=(Tree &obj)
{

	root=assign(root,obj.root);

}

node* Tree::assign(node *destination,node *source)
{
	if(source!=NULL)
	{
		destination=new node(source->data);
		destination->left=assign(destination->left,source->left);
		destination->right=assign(destination->right,source->right);
		return destination;
	}
	return NULL;
}



void Tree::pre_nonrec()
{
	node *T=root;
	stack s;


	while(T!=NULL)
	{
		cout<<"\t"<<T->data;
		s.push(T);
		T=T->left;
	}

	while(!s.empty())
	{
		T=s.pop();
		T=T->right;
		while(T!=NULL)
		{
			cout<<"\t"<<T->data;
			s.push(T);
			T=T->left;
		}
	}
}


void Tree::in_nonrec()
{
	node *T=root;
	stack s;
	while(T!=NULL)
	{
		s.push(T);
		T=T->left;
	}
	while(!s.empty())
	{
		T=s.pop();
		cout<<"\t"<<T->data;
		T=T->right;
		while(T!=NULL)
		{
			s.push(T);
			T=T->left;
		}

	}

}




void Tree::post_nonrec()
{
	node *T=root;
	stacknode st;
	stack1 s;


	while(T!=NULL)
	{
		st.link=T;
		st.flag=1;
		s.push1(st);
		T=T->left;
	}
	while(!s.empty1())
	{
		st=s.pop1();
		T=st.link;
		if(st.flag==1)
		{
			st.flag=2;
			s.push1(st);
			T=T->right;
			while(T!=NULL)
			{
				st.link=T;
				st.flag=1;
				s.push1(st);
				T=T->left;
			}


		}
		else
		{
			cout<<"\t"<<T->data;
		}
	}
}






void Tree::show_nonrec()
{
	if(root!=NULL)
	{
	  int ch;

	  do
	  {
		cout<<"\n\n\n\tSelect Traversal	:	";
		cout<<"\n\n\t1.PreOrder  \
				 \n\t2.InOrder 	 \
				 \n\t3.PostOrder \
				 \n\t0.Exit		";
		cout<<"\n\n\tEnter Choice :	";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n\n\tPreOrder Traversal	:	\n\n\t";
			pre_nonrec();
			break;

		case 2:
			cout<<"\n\n\tInOrder Traversal	:	\n\n\t";
			in_nonrec();
			break;

		case 3:
			cout<<"\n\n\tPostOrder Traversal	:	\n\n\t";
			post_nonrec();
			break;

		default:
			if(ch!=0)
			{
				cout<<"\n\n\t\tWrong Input";
			}
		}
	  }while(ch!=0);
}
}


void Tree::create_mirror(Tree &obj)
{
	root=mirror(root,obj.root);
}

node* Tree::mirror(node *destination,node *source)
{
	if(source!=NULL)
	{
		destination=new node(source->data);
		destination->left=assign(destination->left,source->right);
		destination->right=assign(destination->right,source->left);
		return destination;
	}
	return NULL;

}


void Tree::equal(Tree &obj)
{
	if(equal_rec(root,obj.root))
	{
		cout<<"\n\n\tTrees are equal";

	}
	else
	{
		cout<<"\n\n\tTrees are not equal";
	}
}

int Tree::equal_rec(node *T1,node *T2)
{
	if(T1!=NULL && T2!=NULL)
	{
		if(T1->data==T2->data)
		{
			return 1*equal_rec(T1->left,T2->left)*equal_rec(T1->right,T2->right);


		}
		return 0;

	}
	else if(T1==NULL && T2==NULL)
	{
		return 1;
	}
	return 0;

}








int main()
{

	Tree obj;
	Tree T1;
	Tree T2;
	Tree T3,T4;
	int ch,flag=0,flag2=0;

	cout<<"\n\n\t----------------Binary Tree---------------------";
do
{
	do
	{
		cout<<"\n\n\n\t1.Create Tree			\
				\n\t2.Show						\
				\n\t3.Show Non-recursive		\
				\n\t4.Leaf Nodes				\
				\n\t5.Internal Nodes			\
				\n\t6.Delete Nodes				\
				\n\t7.Assigning Trees			\
				\n\t8.Mirror Image				\
				\n\t9.Tress are Equal or not	\
				\n\t0.Exit				";


		cout<<"\n\n\tEnter your choice	:	";
		cin>>ch;

		switch(ch)
		{
			case 1:
				if(flag==0)
				{
					flag=1;
					obj.create();
				}
				else
				{
					cout<<"\n\n\tTree is already created";
				}
				break;

			case 2:
				if(flag==0 && flag2==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					obj.show();
				}
				break;


			case 3:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					obj.show_nonrec();
				}
				break;




			case 4:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					obj.leaf();
				}
				break;

			case 5:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					obj.internal();

				}
				break;

			case 6:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					obj.delete_();
					cout<<"\n\n\tTree is Deleted";
					flag=0;
				}
				break;

			case 7:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					T1=obj;
					cout<<"\n\n\tTraverse New Tree	:	";
					T1.show();
				}
				break;


			case 8:
				if(flag==0)
				{
					cout<<"\n\n\tCreate a Tree First ";
				}
				else
				{
					T2.create_mirror(obj);
					cout<<"\n\n\tTraverse Mirror Tree	:	";
					T2.show();
				}
				break;

			case 9:
				cout<<"\n\n\n\tEnter First Tree		:	";
				T3.create();
				cout<<"\n\n\n\tEnter Second Tree	:	";
				T4.create();
				T3.equal(T4);
				T3.delete_();
				T4.delete_();
				break;


			default:
				if(ch!=0)
				{
					cout<<"\n\n\t\tWrong Input";
				}


		}



	}while(ch!=0);


	cout<<"\n\n\n\t\tWant to Create Another Tree yes(1)/No(0)	:	";
	cin>>ch;



}while(ch!=0);


	return 0;
}

