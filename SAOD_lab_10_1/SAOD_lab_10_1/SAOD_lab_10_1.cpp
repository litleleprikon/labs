// SAOD_lab_10_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
using namespace std;

int Hash(string key)
{
	int sum=0;
	for (int i=0; i<key.size(); i++)
		sum+=(int)key[i];
	return sum%10;
}

string *Create()
{
	string arr[10];
	string *Table = new string [10];
	arr[0]="end";
	arr[1]="bool";
	arr[2]="REAL";
	arr[3]="True";
	arr[4]="TRY";
	arr[5]="FUNCTION";
	arr[6]="PROGRAMM";
	arr[7]="begin";
	arr[8]="integer";
	arr[9]="var";
	for (int i=0;i<10;i++)
		Table[Hash(arr[i])]=arr[i];
	return Table;
}

int Search(string key, string *Table,int n)
{
	int hash=Hash(key);
	if (Table[hash]==key)return hash;
	else return -1;
}

void Show(string *Table)
{
	for (int i=0; i<10; i++)
	{
		printf("index=%d word= ", i);
		cout<<Table[i] << endl;
	}
	printf("\n");
}

int main()
{
	string *Table=NULL;
	string key;
	int n=0;
	int action;
	while(true)
	{
		cout<< "1. sozdat tablicu" << endl
		<< "2. search" << endl
		<< "3. show" << endl
		<< "0. exit" << endl;
		cin >> action;
		switch(action)
		{
		case 1:
			if (Table!=NULL)
			delete[] Table;
			Table=Create();
			cout << endl << "tablica sozdana" << endl;
			n++;
			break;	
		case 2:
		if (n!=0)
		{
			cout << endl << "Vvedite znachenie klyucha ";
			cin >> key;
			if (Search(key, Table, n)!=-1)
			cout << endl << "indeks  " << Search(key, Table, n) << endl;
			else
			cout << endl << "not found" << endl;
		}
		else
		cout << endl << "sozdaite tablicu" << endl;
		break;
	case 3:
	if (n!=0)
	Show(Table);
	else
	cout << endl << "sozdaiet tablicu" << endl;
	break;
	case 0: return 1;
	default:
	cout << endl << "error" << endl;
	break;
		}	
}

}
