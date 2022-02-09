#include<iostream>
#include<fstream>
using namespace std;


class student
{
	int roll;
	char div[5];
	string name,address;
	public:
		void accept();
		void insert();
		void display();
		void search();
		void _delete();
}s;

void student::accept()
{
	ofstream fout;
	int n;
	cout<<"\n\n\tEnter the no. of students"<<endl;
	cin>>n;
	fout.open("Student.txt",ios::out|ios::app);
	for(int i=0;i<n;i++)
	{
		cout<<"\n\n\tEnter the Roll No. of student"<<endl;
		cin>>roll;
		cin.ignore(1);
		cout<<"\n\n\tEnter the Name of student"<<endl;
		getline(cin,name);
		cout<<"\n\n\tEnter the Division of student"<<endl;
		cin>>div;
		cin.ignore(1);
		cout<<"\n\n\tEnter the Address of student"<<endl;
		getline(cin,address);	
		fout<<roll<<"\t"<<name<<"\t"<<div<<"\t"<<address<<endl;
	}
	fout.close();
}

void student::insert()
{
	ofstream fout;
	fout.open("Student.txt",ios::out|ios::app);
	cout<<"\n\n\tEnter the Roll No. of student you want to insert"<<endl;
	cin>>roll;
	cin.ignore(1);
	cout<<"\n\n\tEnter the Name of student you want to insert"<<endl;
	getline(cin,name);
	cout<<"\n\n\tEnter the Division of student you want to insert"<<endl;
	cin>>div;
	cin.ignore(1);
	cout<<"\n\n\tEnter the Address of student you want to insert"<<endl;
	getline(cin,address);
	fout<<roll<<"\t"<<name<<"\t"<<div<<"\t"<<address<<endl;
	fout.close();
	
}

void student::display()
{
	string temp;
	ifstream fin;
	fin.open("Student.txt",ios::in|ios::app);
	while(!fin.eof())
	{
		getline(fin,temp);
		cout<<temp<<endl;
	}
	fin.close();
}

void student::search()
{
	ifstream fin;
	fin.open("Student.txt",ios::in);
	string search,temp;
	bool flag=0;
	cin.ignore();
	cout<<"\n\n\tEnter the Name you want to search"<<endl;
	getline(cin,search);
	//fin.seekg(0,ios::beg);
	while(!fin.eof())
	{
		fin>>temp;
		if(temp==search)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"\n\n\tData found"<<endl;
		fin.close();
	}
	else
	{
		cout<<"\n\n\tData not found"<<endl;
	}
}


void student::_delete()
{
	ifstream fin;
	fin.open("Student.txt",ios::in|ios::app);
	string temp,name,temp2;
	cout << "\n\n\tEnter name of student whose record is to be deleted: ";
	getline(cin,name);
	fin.seekg(0,ios::beg);
	int flag = 0;
	ofstream fout;
	fout.open("abc.txt", ios::out);
	int cnt = 0;
	while(fin.eof() == 0 && fin.tellg() != -1)
	{
		fin >> temp;
		if(temp == name)
		{
			flag = 1;
		}
		if(flag == 1)
		{
			for(int i=0;i<4;i++)
			{
				fin >> temp;
			}
			flag = 0;
            cnt = 0;
		}
		fout << temp;
		if(cnt == 3)
        {
            cnt = 0;
            fout << "\n";
        }
        else
        {
            cnt++;
            fout << "\t";
        }
	}
	fout.close();
	fin.close();
	
}


int main()
{
	int ch;
	while(1)
	{
		cout<<"\n\n\t1.Create the Student Data Base"<<endl;
		cout<<"\n\t2.Insert the data"<<endl;
		cout<<"\n\t3.Display the data"<<endl;
		cout<<"\n\t4.Search the data"<<endl;
		cout<<"\n\t5.Delete the data"<<endl;
		cout<<"\n\n\tEnter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.accept();
				break;
				
			case 2:
				s.insert();
				break;
				
			case 3:
				s.display();
				break;
				
			case 4:
				s.search();
				break;	
				
			case 5:
				cin.ignore();
				s._delete();
				break;			
		}
	}
}



