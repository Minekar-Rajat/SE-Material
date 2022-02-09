#include<iostream>
#include<string.h>
using namespace std;

class node
{
public:
	int roll;
	char name[20];
	//char choice[30];
	int choice;
	node* next;
	node(char* nm, int r, int ch)
	{
		strcpy(name, nm);
		roll = r;
		//strcpy(choice, ch);
		choice=ch;
		next = NULL;
	}
};

class sll
{
	
public:
	node* head;
	void both(sll &vnl, sll &btr);
	void onlyvanella(sll &vnl, sll &btr);
	void onlybutter(sll &vnl, sll &btr);
	void union_of_set(sll &vnl, sll &btr);
	sll()
	{
		head = NULL;
	}
	void create();
	void show();
	void addatend(char* nm, int roll, int c);
	int findpos(int);
	void deletebyroll(int);
	int count();
	void deleteatbeg();
	void copylist(sll &obj);


};


int sll::count()
{
	int cnt = 0;
	node* p;
	p = head;
	while (p != NULL)
	{
		cnt++;
		p = p->next;

	}
	return cnt;

}


void sll::deleteatbeg()
{

	if (head == NULL)
	{
		cout << "\n\n\tLinklist is already empty";
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
	}

	else
	{
		node* p;
		p = head;
		p = p->next;
		delete head;
		head = p;

	}
}




void sll::deletebyroll(int roll)
{
	int pos;
	
	pos = findpos(roll);
	
	
	
	node* p;
	node* q;
	int c = count();
	if (pos<1 || pos>c)
	{
		cout << "\n\tDelete can't be performed";
		return;
	}
	if (pos == 1)
	{
		deleteatbeg();
	}
	else
	{
		p = head;
		for (int i = 1; i < pos - 1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		delete q;

	}

}


int sll::findpos(int roll)
{
	node* p;
	p = head;
	int cnt = 1;
	while (p != NULL)
	{
		if (p->roll == roll)
		{
			return cnt;
		}
		cnt++;
		p = p->next;
	}
}



void sll::addatend(char* nm, int roll, int ch)
{
	node* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new node(nm, roll, ch);

}

void sll::show()
{
	node* p;
	p = head;
	if (head == NULL)
	{
		cout << "\n\n\tList is empty ";
	}
	else
	{
		while (p != NULL)
		{
			cout << "\n\t\tName    :  " << p->name;
			cout << "\n\t\tRoll no :  " << p->roll;
			//cout << "\n\tChoice    : " << p->choice;
			cout << "\n\n\t";
			p = p->next;
		}
	}
}

void sll::both(sll &vnl, sll &btr)
{
	sll temp;
	node* p, * q;
	p = vnl.head;
	q = btr.head;
	while (p != NULL)
	{
		while (q != NULL)
		{
			if (p->roll == q->roll && strcmp(p->name, q->name)==0)
			{
				temp.addatend(p->name, p->roll, p->choice);
			}
			q = q->next;
		}
		p = p->next;
	}

	cout << "\n\n\tStudents who likes Both Vanella and Butterscotch : \n\t";
	temp.show();

}

void sll::copylist(sll &obj)
{
	node* p, * q;
	p = obj.head;
	this->head = q = new node(p->name, p->roll, p->choice);
	p = p->next;
	while (p != NULL)
	{
		q->next = new node(p->name, p->roll, p->choice);
		p = p->next;
		q = q->next;

	}
}





void sll::onlyvanella(sll &vnl, sll &btr)
{
	sll temp;
	temp.copylist(vnl);
	node* p, * q;
	p = vnl.head;
	q = btr.head;
	while (p != NULL)
	{
		while (q != NULL)
		{
			if (p->roll == q->roll && strcmp(p->name, q->name) == 0)
			{
				temp.deletebyroll(q->roll);
			}
			q = q->next;
		}
		p = p->next;
	}

	cout << "\n\n\tStudents who likes only Vanella : \n\t";
	temp.show();

}

void sll::onlybutter(sll &vnl, sll &btr)
{
	sll temp;
	temp.copylist(btr);
	node* p, * q;
	p = btr.head;
	q = vnl.head;
	while (p != NULL)
	{
		while (q != NULL)
		{
			if (p->roll == q->roll && strcmp(p->name, q->name) == 0)
			{
				temp.deletebyroll(q->roll);
			}
			q = q->next;
		}
		p = p->next;
	}

	cout << "\n\n\tStudents who likes only Vanella : \n\t";
	temp.show();


}

void sll::union_of_set(sll &vnl, sll &btr)
{
	sll temp1, temp2,temp3;
	temp1.copylist(vnl);
	temp2.copylist(btr);
	node* r, * s;
	r = btr.head;
	s = vnl.head;
	while (r != NULL)
	{
		while (s != NULL)
		{
			if (r->roll == s->roll && strcmp(r->name, s->name) == 0)
			{
				temp2.deletebyroll(s->roll);
			}
			s = s->next;
		}
		r = r->next;
	}

	node* p, * q;
	p = temp1.head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	q = temp2.head;
	p->next = q;

	cout << "\n\n\tStudents who likes either Vanella or Butterscotch : \n\t";
	temp1.show();

}

int main()
{
	sll vnl;
	sll btr;
	sll none;
	char* str;
	int ch;
	str = new char[100];
	//ch = new char[50];
	int r;
	cout << "\n\n\t-----------------Data Set--------------------\n\n";
	cout << "\n\n\tEnter data for node  : ";
	cout << "\n\t\tRoll no :  ";
	cin >> r;
	cin.ignore(1);
	cout << "\n\t\tName    :  ";
	cin.getline(str, 98);

	cout << "\n\t\tEnter choice :  \
		\n\n\t0.vanella   \
		\n\t1.butterscotch \
		\n\t2.both               \
		\n\t3.none of them  \n\t";
	//cin.getline(ch, 49);
	cin>>ch;
	//if (strcmp(ch, "vanella") == 0 || strcmp(ch, "Vanella") == 0 || strcmp(ch, "VANELLA") == 0 || strcmp(ch, "both") == 0 || strcmp(ch, "Both") == 0 || strcmp(ch, "BOTH") == 0)
	if(ch==0 || ch==2)
	{
		vnl.addatend(str, r, 1);
	}
	//else if (strcmp(ch, "butterscotch") == 0 || strcmp(ch, "Butterscotch") == 0 || strcmp(ch, "BUTTERSCOTCH") == 0 || strcmp(ch, "both") == 0 || strcmp(ch, "Both") == 0 || strcmp(ch, "BOTH") == 0)
	else if(ch==1 || ch==2)
	{
		btr.addatend(str, r, 1);
	}
	//else if(strcmp(ch, "none") == 0 || strcmp(ch, "None") == 0 || strcmp(ch, "NONE") == 0 )
	else if(ch==3)
	{
		none.addatend(str, r, 3);
	}
	
	while (1)
	{
		cout << "\n\n\tEnter data for node  or stop(0) : ";
		cout << "\n\t\tRoll no :  ";
		cin >> r;
		cin.ignore(1);
		if(r==0)
		{
			break;
		}
		cout << "\n\t\tName    :  ";
		cin.getline(str, 98);
	
		
		cout << "\n\t\tEnter choice :  \
		\n\n\t0.only vanella   \
		\n\t1.only butterscotch \
		\n\t2.both               \
		\n\t3.none of them  \n\t";
		cin>>ch;
		//cin.getline(ch, 49);
		//if (strcmp(ch, "vanella") == 0 || strcmp(ch, "Vanella") == 0 || strcmp(ch, "VANELLA") == 0 || strcmp(ch, "both") == 0 || strcmp(ch, "Both") == 0 || strcmp(ch, "BOTH") == 0)
		if(ch==0 || ch==2)
		{
			vnl.addatend(str, r, 0);
		}
		//else if (strcmp(ch, "butterscotch") == 0 || strcmp(ch, "Butterscotch") == 0 || strcmp(ch, "BUTTERSCOTCH") == 0 || strcmp(ch, "both") == 0 || strcmp(ch, "Both") == 0 || strcmp(ch, "BOTH") == 0)
		else if(ch==1 || ch==2)
		{
			btr.addatend(str, r, 1);
		}
		//else if (strcmp(ch, "none") == 0 || strcmp(ch, "None") == 0 || strcmp(ch, "NONE") == 0)
		else if(ch==3)
		{
			none.addatend(str, r, 3);
		}
		


	}

	int c;
	sll abc;

	do
	{
		cout << "\n\n\t0.Exit							 \
				 \n\t1.Either vanella or Butterscotch	 \
				 \n\t2.Only Vanella                      \
				 \n\t3.only Butterscotch				 \
				 \n\t4.Both							     \
				 \n\t5.Niether Vanella Nor Butterscotch  \
				 \n\n\tEnter your choice	   :  ";
		cin >> c;

		switch (c)
		{
		case 1 :
			abc.union_of_set(vnl,btr);
			break;
		case 2 :
			abc.onlyvanella(vnl,btr);
			break;
		case 3:
			abc.onlybutter(vnl, btr);
			break;
		case 4:
			abc.both(vnl, btr);
			break;
		case 5:
			cout << "\n\n\tStudents who likes Neither Vanella Nor Butterscotch : \n\t";
			none.show();
		default:
			if (c != 0)
			{
				cout << "\n\tInvalid Input";
			}
		}


	} while (c != 0);



cout<<"\n\n\tDONE!!!!!!";
return 0;

}
