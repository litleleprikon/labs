// SAOD_lab_10_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int M=5;

struct ITEM 
{
	string key;
	ITEM *next;
};

struct LIST 
{
	string key;
	ITEM *headitem;
};

LIST mylist[M];

void Initial()
{
	for (int i=0;i<M;i++)
	{
		mylist[i].key.empty();
		mylist[i].headitem=new ITEM;
		mylist[i].headitem->next=NULL;
	};
}

int Hash(string key)
{
	int sum=0;
	for (int i=0; i<key.size(); i++)
	sum+=int(key[i]);
	return sum%M;
}

ITEM *GetItem(int index, int &count)
{
	ITEM *CurrentItem=mylist[index].headitem;
	while(++count && CurrentItem->next!=NULL)
	CurrentItem=CurrentItem->next;
	return CurrentItem;
}

int Add(string key)
{
	int count=0;
	int hash=Hash(key);
	if (++count && mylist[hash].key.empty())
	mylist[hash].key=key;
	else
	{
		cout << endl << "konflict" << endl;
		ITEM *CurrentItem=GetItem(hash,count);
		ITEM *tmp=new ITEM;
		tmp->key=key;
		tmp->next=NULL;
		CurrentItem->next=tmp;
	CurrentItem=tmp;
	}
	return count;
}

int Search(string key, int &count)
{
	int flag=0;
	int hash=Hash(key);
	if (++count && mylist[hash].key==key) flag=1;
	else
	{
		ITEM *tmp=mylist[hash].headitem->next;
		while(++count && tmp!=NULL)
		{
			if (tmp->key==key)
			{
				flag=1;
				break;
			}
			tmp=tmp->next;
		};
	};
	if (flag) 
	return 1;
	else 
	return 0;
}

void Show()
{
	cout<<endl;
	for (int i=0; i<M; i++)
	{
		printf("index=%d",i);
		cout << mylist[i].key << " : ";
		ITEM *tmp=mylist[i].headitem->next;
		while(tmp!=NULL)
		{
			cout<<tmp->key<<" ";
			tmp=tmp->next;
		};	
		cout << endl;
	};
}

int Del(string key)
{
	int flag=0;
	int hash=Hash(key);
	if (mylist[hash].key==key)
	{
		if (mylist[hash].headitem->next==NULL)
		{
			flag=1;
			mylist[hash].key.empty();
		}
		else
		{
			mylist[hash].key=mylist[hash].headitem->next->key;
			ITEM *tmp=mylist[hash].headitem->next;
			mylist[hash].headitem->next=tmp->next;
			flag=1;
			delete tmp;
		};
	}
	else
	{
		ITEM *prev=mylist[hash].headitem;
		ITEM *tmp=mylist[hash].headitem->next;
		while(tmp!=NULL)
		{
			if (tmp->key==key)
			{
				prev->next=tmp->next;
				delete tmp;
				flag=1;
				break;
			}
			else
			{
				prev=tmp;
				tmp=tmp->next;
			};
		};
	};
return flag;
}

int main()
{
	string key;
	Initial();
	int count;
	char action[100];
	for (;;)
	{
		cout	<< "1. Add" << endl
		<< "2. search" << endl
		<< "3. show" << endl 
		<< "4. delete" << endl
		<< "0. exit" << endl;
		cin >> action;
		switch(action[0])
		{
		case '1':
			cout << endl << "vvedite kluch ";
			cin >> key;
			count=0;
			if (Search(key, count)!=0) cout << endl << "kluch byl ispolzovan " << count << endl;
			else
			{
				count = Add(key);
				cout << endl << "kluch dobavlen byl " << count << endl;
			};
			break;
		case '2':
			cout << endl << "vvedite key ";
			cin >> key;
			count=0;
			if (Search(key, count)!=0) cout << endl << "found " << count << endl;
			else cout << endl << "not found" << endl;
			break;
		case '3':
			Show();
			break;
		case '4':
			cout << endl << "input key ";
			cin >> key;
			if (Del(key)==1)cout << endl << "deleted" << endl;
			else cout << endl << "not found" << endl;
			break;
		case '0':
			return 1;
		default:
			cout << endl << "error" << endl;
			break;
		};
	};
}



