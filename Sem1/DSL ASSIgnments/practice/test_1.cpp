#include <iostream>
#define MAX 20
using namespace std;

class stack
{
	int data[MAX];
	int top;
	char infix[100];
	char postfix[100];
public:
	stack()
	{
		top=-1;
	}
	int full();
	int empty();
	void push(int c);
	int pop();
	int get_priority(int ch);
	void convert(char infix[]);
	void eval();
};

int stack::full()
{
	if(top==MAX-1)
	{
		return 1;
	}
	return 0;
}

int stack::empty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}

void stack::push(int c)
{
	if(!full())
	{
		top++;
		data[top]=c;
	}
	else
	{
		cout<<"Stack is full"<<endl;
	}
}

int stack::pop()
{
	if(!empty())
	{
		int c;
		c=data[top];
		top--;
		return c;
	}
	else
	{
		cout<<"Stack is empty"<<endl;
		return 0;
	}
}


int stack::get_priority(int ch)
{
	if(ch=='*' || ch=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void stack::convert(char infix[])
{
	int st_ch;
	int ex_ch;
	int i,j;
	int flag;
	i=0;
	j=0;
	while(infix[i]!='\0')
	{
		ex_ch=infix[i];
		i++;
		if(ex_ch=='*' || ex_ch=='/' || ex_ch=='+' || ex_ch=='-')
		{
			if(empty())
			{
				push(ex_ch);
			}
			else
			{
				while(!empty())
				{
					int pr_ex=get_priority(ex_ch);
					st_ch=pop();
					int pr_st=get_priority(st_ch);
					if(pr_st>=pr_ex)
					{
						postfix[j]=st_ch;
						j++;
					}
					else
					{
						flag=1;
					    break;
					}
				}
				if(flag==1)
				{
				push(st_ch);
				flag=0;
				}
				push(ex_ch);
			}
		}

		else
		{
			postfix[j]=ex_ch;
			j++;
		}
	}

	while(!empty())
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	cout<<"Postfix expression is:\t"<<postfix;
}
