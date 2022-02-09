#include<iostream>
#include<string.h>
using namespace std;

class node
{
	protected :
		
		string brand;
		string processor;
		string RAM;
		string storage;
		string graphic;
		string os;
		node *next;
		node *prev;
	public :
		
		node(char *brand,char *processor,char *RAM,char *storage,char *graphic,char* os)
		{
			strcpy(this->brand,brand);
			strcpy(this->processor,processor);
			strcpy(this->RAM,RAM);
			strcpy(this->storage,storage);
			strcpy(this->graphic,graphic);
			strcpy(this->os,os);
			next=NULL;
		}
};


class laptop
{
	node *head;
	node *rear;
public :
			void create();
			void show();
	
		
};


