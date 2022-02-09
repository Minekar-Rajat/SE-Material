#include<iostream>
using namespace std;

class complex
{
	int real,img;
	
	public:
		friend istream & operator >>(istream&in,complex &obj);
		friend ostream & operator <<(ostream&out,complex &obj);
		complex();
		complex(int ,int );
		complex operator+(complex &);
		complex operator-(complex &);	
		complex operator*(complex &);	
		complex operator/(complex &);	
		 
			
};

complex::complex()
{
	this->real=0;
	this->img=0;
}

complex::complex(int real,int img)
{
	this->real=real;
	this->img=img;
}

complex complex::operator+(complex &obj)
{
		complex temp;
		temp.real=this->real+obj.real;
		temp.img=this->img+obj.img;
		
		return temp;
}

complex complex::operator-(complex &obj)
{
		complex temp;
		temp.real=this->real-obj.real;
		temp.img=this->img-obj.img;
		
		return temp;
}

complex complex::operator*(complex &obj)
{
		complex temp;
		temp.real=((this->real*obj.real)-(this->img*obj.img));
		temp.img=((this->real*obj.img)+(this->img*obj.real));
		
		return temp;
}

ostream & operator << (ostream&out ,complex &obj)
{
	if(obj.img<0)
	{
		out<<"\n\t"<<obj.real<<obj.img<<"i";
	}
	else
	{
		out<<"\n\t"<<obj.real<<"+"<<obj.img<<"i";
	}
	
	return out;
}
istream & operator >> (istream&in ,complex &obj)
{
	cout<<"\n\tReal Part :	";
	in>>obj.real;
	cout<<"\n\tImg  Part :	";
	in>>obj.img;
	
	return in;
	
}


int main()
{
	complex c1,c2,ans;
	int ch;
	
	cout<<"\n\t*********** Complex Numbers *************";
	
	
	do
	{
		cout<<"\n\n\n\t0.Exit			\
				\n\t1.Addition		\
				\n\t2.Subtraction	\
				\n\t3.Multiplication\
				\n\t4.Dislay Complex Numbers ";
		cout<<"\n\n\tEnter your Choice	:	";
		cin>>ch;
		
		switch(ch)
		{
			case 1	:
					cout<<"\n\n\tEnter Complex Number 1 :	";
					cin>>c1;
					cout<<"\n\n\tEnter Complex Number 2 :	";
					cin>>c2;
					ans=c1+c2;
					cout<<"\n\tAddition :	\n";
					cout<<ans;
					break;
			case 2	:
					cout<<"\n\n\tEnter Complex Number 1 :	";
					cin>>c1;
					cout<<"\n\n\tEnter Complex Number 2 :	";
					cin>>c2;
					ans=c1-c2;
					cout<<"\n\tSubtraction :	\n";
					cout<<ans;
					break;
					
			case 3	:
					cout<<"\n\n\tEnter Complex Number 1 :	";
					cin>>c1;
					cout<<"\n\n\tEnter Complex Number 2 :	";
					cin>>c2;
					ans=c1*c2;
					cout<<"\n\tMultiplication :	\n";
					cout<<ans;
					break;
					
			case 4	:
					cout<<"\n\n\tEnter Complex Number 1 :	";
					cin>>c1;
					cout<<"\n\n\tEnter Complex Number 2 :	";
					cin>>c2;
					cout<<"\n\tComplex Number 1 :	";
					cout<<"\n\t"<<c1;
					cout<<"\n\tComplex Number 2 :	";
					cout<<"\n\t"<<c2;
					break;		
					
			default	:
					if(ch!=0)
					{
						cout<<"\n\tWrong Input";
					}
					
					
		}
	}while(ch!=0);
	
	return 0;
}
