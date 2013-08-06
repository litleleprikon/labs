// SAOD_lab_10_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int M=10;
int vvod()
{
	cout<<"vvedite chislo"<<endl;
	char op[80];
	cin>>op;
	int i=0;
	while (op[i]!='\0')
	{
		if (iswdigit(op[i])==false)
		{
			cout<<"eto ne chislo"<<endl;
			return NULL;
		};
	i++;
	};
	i=atoi(op);
	return i;
};
void Initial(string *Table)
{
	for (int i=0;i<M;i++)
	Table[i].empty();
}

int Hash(string key, int j)
{
	int sum=j;
	for (int i=0;i<key.size();i++)
	sum+=(int)key[i];
	return sum%M;
}

int Add(string *Table, string key, int &count)
{
	int flag=0;
	int hash;
	for (int i=0;i<M-2;i++)
	{	
		hash=Hash(key,i);
		count++;
		if (Table[hash].empty())
		{
			Table[hash]=key;
			flag=1;
			break;
		} 
	}
	if (flag) return 1;
	else return 0;
}

int Search(string *Table, string key, int &count)
{
	int flag=0;
	int hash;
	for (int i=0;i<(M-2);i++)
	{
		hash=Hash(key,i);
		count++;
		if (Table[hash]==key)
		{
			flag=1;
			break;
		}
	}
	if (flag) 	return hash;
	else return -1;
}

void Show(string *Table)
{
	for (int i=0;i<M;i++)
	{
		printf("index=%d word=",i);
		cout << Table[i] << endl;
	}
}

int main()
{
	string Table[M];
	Initial(Table);
	string key;
	int count;
	int action;
	for (;;)
	{
		cout<< "1. Add" << endl
		<< "2. Search" << endl
		<< "3. Show" << endl
		<< "0. Exit" <<endl;
		cin >> action;
		switch(action)
		{
		case 1:
			count=0;
			cout << endl << "vvedite cluch ";
			cin >> key;
			if (Search(Table, key, count)!=-1) cout << endl << "etot cluch uzhe ispolzovalsa " << count << endl;
			else
			{
				count=0;
				if (Add(Table, key, count)==1)cout << endl << "kluch dobavlen " << count << endl;
				else cout << endl << "error" << endl;
			}
			break;
		case 2:
			count=0;
			cout << endl << "vvedite kluch ";
			cin >> key;
			if (Search(Table, key, count)!=-1) cout << endl << "Индекс = " << Search(Table, key, count) << " Кол-во сравнений = " << count << endl;
			else cout << endl << "not found" << endl;
			break;
		case 3:
			Show(Table);
            break;
		case 0: return 1;
			default:cout << endl << "error" << endl;
			break;
	}

}

}


