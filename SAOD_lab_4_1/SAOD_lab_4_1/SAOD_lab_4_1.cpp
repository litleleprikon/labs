// SAOD_lab_4_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct TREE {
int info;
TREE *right;
TREE *left;
};

TREE *root=NULL;
int count=0;

void Create(TREE **current, int n)
{
	if(n==0) 
		*current=NULL;
	else
	{
		int nl=n/2;
		int nr=n-nl-1;
		TREE *tmp=new TREE;
		tmp->info=rand()%100;
		count++;
		Create(&tmp->left, nl);
		Create(&tmp->right, nr);
		*current=tmp;
	}
}

void ShowOnward(TREE *current, int l)
{
	if(current!=NULL)
	{
		for(int i=0;i<l;i++)
		cout << "\t";
		cout << current->info << endl;
		ShowOnward(current->left, l+1);
		ShowOnward(current->right, l+1);
}
}

void ShowSymmetric(TREE *current, int l)
{
	if(current!=NULL)
	{
		ShowSymmetric(current->left, l+1);
		for(int i=0;i<l;i++)
		cout << "\t";
		cout << current->info << endl;
		ShowSymmetric(current->right, l+1); 
	}
}

void ShowBackSymmetric(TREE *current, int l)
{
	if(current!=NULL)
	{
		ShowBackSymmetric(current->right, l+1);
		for(int i=0;i<l;i++)
		cout << "\t";
		cout << current->info << endl;
		ShowBackSymmetric(current->left, l+1); 
	}
}

void ClearTree(TREE **current)
{
	if(*current!=NULL)
	{
		ClearTree(&(*current)->left);
		ClearTree(&(*current)->right);
		delete *current;
		count--;
		if(count==0)
		*current=NULL;
	}
}

int vvod()
{
	cout<<"vvedite kollichestvo vershin "<<endl;
	char op[80];
	cin>>op;
	int i=0;
	while (op[i]!='\0')
	{
		if (iswdigit(op[i])==false)
		{
			cout<<"error"<<endl;
			return NULL;
		};
	i++;
	};
	i=atoi(op);
	return i;
};
int main()
{
	int num;
	char otv;
	while(true)
	{
		cout << "1) build tree" << endl<< "2) pryamoi obhod" << endl<< "3) simmetrichnyi obhod" << endl<< "4) obrathiy simmetrichnyi" << endl<< "0) exit"<<endl;//" = ";
		cin >> otv;
		switch(otv)
		{
			case '1':
			num=vvod();
			if (num==NULL)
			{
			
			}
			else
			{
				ClearTree(&root);
				Create(&root, num);
				cout << endl << "derevo sozdano" << endl;
			};
			break;
			case '2':
			if(root!=NULL)
			{
				ShowOnward(root, 0);
			}
			else cout << endl << "derevo pustoe" << endl;
			break;
			case '3':
			if(root!=NULL)
			{
				ShowSymmetric(root, 0);
			}
			else
			cout << endl << "derevo pustoe" << endl;
			break;
			case '4':
			if(root!=NULL)
			{
				ShowBackSymmetric(root, 0);
			}
			else
			cout << endl << "derevo pustoe" << endl;
			break;
			case '0':
			return 1;
			default:
			cout << endl << "error" << endl;
			break;
		}

	};
//cin.get();

}
