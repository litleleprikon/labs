// SAOD_lab_9_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int method;
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
			cout<<"eto ne cifri"<<endl;
			return NULL;
		};
	i++;
	};
	i=atoi(op);
	return i;
};

int *CreateAuto(int n)
{
	if (n<=10000 && n>1)
	{
		method=0;
		int *arr=new int [n];
		for (int i=0; i<n; i++) arr[i]=rand()%n;
		return arr;
		}
	else
	return NULL;
}

void Show(int *arr, int n)
{
	cout << endl;
	for (int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl;
}

void Copy(int *arr1, int *arr2, int n)
{
	for (int i=0; i<n; i++) arr2[i]=arr1[i];
}

struct ITEM {
	int info;
	ITEM *next;
};

void AddItem(ITEM *pItem, int info)
{
	while(pItem->next!=NULL)
	pItem=pItem->next;
	pItem->next = new ITEM;
	pItem->next->info=info;
	pItem->next->next=NULL;
}

void ShowPocketGeneral(ITEM *arr, int n)
{
	cout << endl;
	for (int i=0; i<n; i++)
	{
		ITEM *current=arr[i].next;
		while(current!=NULL)
		{
			cout << current->info << " ";
			current=current->next;
		};
	};
	cout << endl;
}

void ClearList(ITEM *head)
{
	while(head!=NULL)
	{
		ITEM *tmp=head;
		head=head->next;
		delete tmp;
	};
}

void PocketGeneralSort(int *arr, int n)
{
	ITEM *sort = new ITEM [n];
	int moves=0;
	for (int i=0;i<n;i++) sort[i].next=NULL;
	for (int i=0; i<n; i++, moves++) AddItem(&sort[arr[i]],arr[i]);
	ShowPocketGeneral(sort,n);
	//cout << endl << "Kolichestvo peresylok = " << moves << endl;
	for (int i=0; i<n; i++)
	ClearList(sort[i].next);
	delete[] sort;
}

int main()
{
	int *unsort=NULL;
	int *sort=NULL;
	int n=0;
	char action[100];
	while(true)
	{
	cout
	<< endl << "1. create array "
	<< endl << "2. show"
	<< endl << "3. sort"
	<< endl << "0. exit"
	<< endl; //<< " = ";
	cin >> action;
	switch(action[0])
	{
		case '1':
		if (n>0)
		{
			delete[] unsort;
			delete[] sort;
		}
		cout << endl << "vvedite razmer massiva ";
		//cin >> n;
		n=vvod();
		if (n!=NULL)
		{
			unsort=CreateAuto(n);
			if (unsort!=NULL)
			{
				sort=new int [n];
				cout << endl << "massiv sozdan" << endl;
			}
			else
			{
				cout << endl << "nevozmozhno sozdat massiv" << endl;		
				n=0;
			};
		};
		break;
	case '2':
		if (n>0)
		Show(unsort, n);
		else
		cout << endl << "sozdaite massiv" << endl;
		break;
	case '3':
	if (n>0)
	{
		PocketGeneralSort(unsort, n);
	}
	else
	cout << endl << "sozdaite massiv" << endl; 
	break;

	case '0': return 1;
	default:
		cout << endl << "error" << endl;
		break;
	};

};
//cin.get();

}



