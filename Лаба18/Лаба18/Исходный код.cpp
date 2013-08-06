#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
const int M=10;


struct list
	{
		string key;
		list *next;
		list *prev;
	};
list *table[M];

int Hash(string key)
{
	int sum=0;
    const char *str = key.c_str();
    int length = strlen(str);
	for ( int i=0; i<length; i++)
	sum+= int(key[i]); 
	return sum%M;
}
int Search(string key, int &count)
{
	int check=0; 
	int hash=Hash(key); 
	list *tmp=NULL;
	
	if(table[hash]!=NULL)
	{
		count++;
		if(table[hash]->key==key)
		{
			check=1;
		}
		else
		{
			tmp=table[hash]->next;
			while(tmp!=table[hash])
			{
				count++;
				if(tmp->key==key)
				{
					check=1;
					break;
				}
				tmp=tmp->next;
		
			}
		}
	}
	else
	{
		count++;
		check=-1;
	}
	return check;
}

void ShowTable()
{
	cout<<"table:\n";
	list *hlp;
	for(int i=0;i<M;i++)
	{
		cout<<"["<<i<<"]: ";
		if(table[i]!=NULL)
		{
			hlp=table[i]->next;
			cout<<table[i]->key<<" : ";
			while(hlp!=table[i])
			{
				
				cout<<hlp->key<<" ";
				hlp=hlp->next;
			}
		}
		cout<<endl;
	}
	cout<<endl;
}


int AddKey(string key)
{
	list *tmp;
	int count=0;
	int hash=Hash(key);
	if(Search(key,count)==-1)
	 {
		 table[hash]=new list;
		 table[hash]->next=table[hash];
		 table[hash]->prev=table[hash];
		 table[hash]->key=key;
	}
	else
	{
		tmp=new list;
		count++;
		if(table[hash]->next==table[hash])
		{
			tmp->next=table[hash];
			tmp->prev=table[hash];
			table[hash]->next=tmp;
			table[hash]->prev=tmp;
		}
		else
		{
			 tmp->next=table[hash];
			 tmp->prev=table[hash]->prev;
			 table[hash]->prev->next=tmp;
			 table[hash]->prev=tmp;
		}
			 tmp->key=key;
	}
	return count;
}

list *SearchForDel(string key)
{
	int hash=Hash(key); 
	list *hlp=NULL,*tmp=NULL;
	
	if(table[hash]!=NULL)
	{
		if(table[hash]->key==key)
		{
			hlp=table[hash];
		}
		else
		{
			tmp=table[hash]->next;
			while(tmp!=table[hash])
			{
				if(tmp->key==key)
				{
					hlp=tmp;
					break;
				}
				tmp=tmp->next;
		
			}
		}
	}
		return hlp;
}



int DelKey(string key)
{
	int check=0;
	list *tmp,*del;
	int hash=Hash(key);
	tmp=SearchForDel(key);
	if(tmp!=NULL)
	{
		if(tmp!=table[hash])
		{
			del=tmp; 
			tmp=tmp->next; 
			tmp->prev=del->prev;
			tmp->prev->next=tmp;
			delete del; 
			
		}
		else
		{
			if(table[hash]->next==table[hash])
			{
				del=table[hash];
				table[hash]=NULL;
				delete del;
				
			}
			else
			{
				del=table[hash]; 
				table[hash]=table[hash]->next; 
				table[hash]->prev=del->prev;
				table[hash]->prev->next=table[hash];
				delete del; 
			}

		}
		check=1;
	}
	else
	{
		check=0;
	}
	return check;

}



void main() 
{   
	string key;
	int count;
	for ( int i=0;i<M;i++) 
	{
	 table[i]=NULL;
	}
	char str[10];
	int i;
	
	do
	 {
		cout<<"\n1.add key\n2.delete key\n3.find key\n4.show table\n0.exit\n";
		cin>>str;
		i=atoi(str);
		switch (i)
		 {		
			case 1:
					cout << endl << "input key: "; 
					cin >> key; 
					count=0; 
					if (Search(key, count)==1) 
					cout << endl << "this key already added, srav : " << count << endl; 
					else 
					{ 
						count = AddKey (key); 
						cout << endl << "key added, srav: " << count << endl; 
					} 
					break;
			case 2:
					cout << endl << "input key : "; 
					cin >> key; 
					if (DelKey(key)==1) 
					cout << endl << "key is deleted" << endl; 
					else 
					cout << endl << "key not found" << endl; 
					break;
			case 3:
					cout << endl << "input key "; 
					cin >> key; 
					count=0; 
					if (Search(key, count)==1) 
					cout << endl << "key is found, srav : " << count << endl; 
					else 
					cout << endl << "key not found" << endl; 
					break;	
			case 4:ShowTable();break;
			case 0:exit(0);break;
			default:cout<<"error\n\n";break;
		}
	 
		
	}
		while(i!=0);
		getche();
}






