#include<iostream>
#include<fstream>
using namespace std;

class student
{

	
	public:
		int id;
		char name[20];
		int roll;
		int age;
		
		student()
		{
			roll=age=id=0;	
		}	
};		
		
int main()
{
	student s;
	int ch;
	cout<<"\n\n\t======================		File Handling	======================";
	cout<<"\n\n\t-----------------		File creation and opening	---------------\n\n";
do
{
	cout<<"\n\n\t1.Write data	\
			\n\t2.Read data		\
			\n\t0.Exit			";
			cout<<"\n\tEnter Choice		:	";
			cin>>ch;
switch(ch)
{
	case 1 :
		ofstream fout;
		fout.open("practice.txt");
		for(int i=0;i<3;i++)
		{
			cout<<"\n\tEnter Id				:	";
			cin>>s.id;
			fout<<s.id<<"\n";
			cout<<"\n\tEnter Roll number	:	";
			cin>>s.roll;
			fout<<s.roll<<"\n";
			cout<<"\n\tEnter Name			: ";
			cin.ignore(1);
			cin.getline(s.name,19);
			fout<<s.name<<"\n";
			cout<<"\n\tEnter Age			: ";
			cin>>s.age;
			fout<<s.age<<"\n";
		}
	
		fout.close();
		cout<<"\n\n\t------File closed-----\n\n";
		break;
		
	case 2 :
		cout<<"\n\n\t----------File opening again and reading data from file-------\n\n";
		ifstream fin;
		fin.open("practice.txt");
		for(int i=0;i<3;i++)
		{
		
			fin>>s.id;
			fin>>s.roll;
			fin>>s.name;
			fin>>s.age;
			cout<<"\n\tId			:	"<<s.id<<endl;
			cout<<"\n\tRoll number	:	"<<s.roll<<endl;
			cout<<"\n\tName			:	"<<s.name<<endl;
			cout<<"\n\tAge			:	"<<s.age<<endl;
		}
		break;
		
	default:
			if(ch!=0)
			{
				cout<<"\n\tInvalid input";
			}
}

}while(ch!=0);

	return 0;
}		
		
		

