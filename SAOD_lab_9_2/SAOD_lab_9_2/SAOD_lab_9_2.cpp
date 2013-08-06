// SAOD_lab_9_2.cpp: определяет точку входа для консольного приложения.
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
			cout<<"eto ne cifry"<<endl;
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
		for (int i=0; i<n; i++)
		arr[i]=rand()%n;
		return arr;
	}
	else
		return NULL;
}

void Show(int *arr, int n)
{
	cout << endl;
	for (int i=0; i<n; i++)
	cout << arr[i] << " ";
	cout << endl;
}

void Copy(int *arr1, int *arr2, int n)
{
	for (int i=0; i<n; i++)
	arr2[i]=arr1[i];
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

void ClearList(ITEM *head)
{
	while(head!=NULL)
	{
		ITEM *tmp=head;
		head=head->next;
		delete tmp;
	};
}

void DigitSort(int *arr, int n)
{
	ITEM *sort = new ITEM [10];
	int k=n-1;
	int i=0;
	int moves=0;
	while(k>=1)
	{
		i++;
		k/=10;
		for(int j=0; j<10; j++)
			sort[j].next=NULL;
		for (int j=0; j<n; j++, moves++)
		{
			int div=1;
			for (int l=0;l<i;l++,div*=10);
				AddItem(&sort[((arr[j]%div)*10)/div],arr[j]);
		}
	for (int j=0, l=0; l<n; j++)
	{
		ITEM *tmp=sort[j].next;
		while(tmp!=NULL)
		{
			arr[l]=tmp->info;
			tmp=tmp->next;
			l++;
			moves++;
		}
	}
	for(int j=0; j<10; j++)
	ClearList(sort[j].next);
	}
	Show(arr,n);
	cout << "kol-vo peresylok " << moves << endl;
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
		<< endl << "1. create array"
		<< endl << "2. show"
		<< endl << "3. sort"
		<< endl << "0. exit"
		<< endl ;
		cin >> action;
		switch(action[0])
		{
		case '1':
			if (n>0)
			{
				delete[] unsort;
				delete[] sort;
			};
			cout << endl << "vvedite razmer massiva ";
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
				Copy(unsort, sort, n);
				DigitSort(sort, n);
			}
			else
				cout << endl << "sozdaite massiv" << endl; 
			break;

		case '0': return 1;
		default:
			cout << endl << "error" << endl;
		break;
	}

};
cin.get();

}