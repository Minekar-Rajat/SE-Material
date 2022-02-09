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
		void accept()
		{
			cout<<"\n\tEnter Id				:	";
			cin>>id;
			cout<<"\n\tEnter Roll number	:	";
			cin>>roll;
			cout<<"\n\tEnter Name			: ";
			cin.ignore(1);
			cin.getline(name,19);
			cout<<"\n\tEnter Age			: ";
			cin>>age;
		}
		void display()
		{
			cout<<"\n\tId			:	"<<id<<endl;
			cout<<"\n\tRoll number	:	"<<roll<<endl;
			cout<<"\n\tName			:	"<<name<<endl;
			cout<<"\n\tAge			:	"<<age<<endl;
		}
};		
		
int main()
{
	student s;
	int ch,cnt=0;
	cout<<"\n\n\t======================		File Handling	======================";
	cout<<"\n\n\t-----------------		File creation and opening	---------------\n\n";
	
	
		ofstream fout("asch.txt",ios::binary );
		
			s.accept();
			fout.write((char*)&s,sizeof(student));
		//	fout<<endl;
		
	
		fout.close();
		cout<<"\n\n\t------File closed-----\n\n";

		cout<<"\n\n\t----------File opening again and reading data from file-------\n\n";
		ifstream fin("asch.txt",ios::binary);
		
		while(fin)
		{
			if(cnt==0)
			{
			fin.read((char*)&s,sizeof(student));
			s.display();
			cnt++;
			}
		}
		fin.close();



	return 0;
}		
		
		

