#include <iostream>
#include <fstream>
using namespace std;
 
class IO
{
int read, insert;
char name[50], tel_no[10];
fstream fin;
 
public:
void file_insert();
void read_file();
};
 
void IO::file_insert()
{
fin.open("teldir.txt");
if(!fin.is_open())
{
cout<<"Error occur while openining file.";
}
else
{
cont:
 
cout<<"\nEnter name:";
cin>>name;
fin<<"Name :"<<name;
cout<<"\nEnter Tel no.(10 digit)";
cin>>tel_no;
fin<<"\t Tel no: "<<tel_no<<"\n";
char yn;
cout<<"Do you want to continue yes(y) no(n):";
cin>>yn;
if(yn=='y')
goto cont;
 
}
fin.close();
 
}
 
void IO::read_file()
{
cin.ignore();
fin.open("teldir.txt");
if(!fin.is_open())
{
cout<<"Error occur file opening file.";
}
else
{
fin.seekg(ios::beg);
char ch=(char)fin.get();
while(ch!=EOF)
{
cout<<ch;
ch=(char)fin.get();
}
 
}
fin.close();
}
 
int main()
{
IO i;
i.file_insert();
i.read_file();
 
  
 
return 0;
}
