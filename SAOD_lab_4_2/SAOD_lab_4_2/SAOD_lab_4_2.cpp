// SAOD_lab_4_2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include "stdafx.h"


#include <iostream>
#include <cstdlib>
using namespace std;

struct TREE {
int info;
TREE *right;
TREE *left;
};
struct STACK {
int l;
TREE *tree;
STACK *next;
};

TREE *root=NULL;
STACK *stack;
int count=0;


void Push(TREE *tree, int l)
{
	STACK *tmp=new STACK;
	tmp->tree=tree;
	tmp->l=l;
	tmp->next=stack;
	stack=tmp;
}

int Pop(TREE **tree)
{
	if(stack!=NULL)
	{
		STACK *tmp=stack;
		stack=stack->next;
		*tree=tmp->tree;
		int l=tmp->l;
		delete tmp;
		return l;
	}
	else
	return 0;
}
void Create(TREE **current, int n)
{
	if(n==0) *current=NULL;
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

void Symmetric_not_recurs(TREE *current, int l)
{
	int flag=0;
	while(flag==0)
	{
		while(current!=NULL)
		{
			l++;
			Push(current, l);
			current=current->left;
		};
		if(stack==NULL) flag=1;
		else
		{
			l=Pop(&current);
			for(int i=1; i<l; i++) cout << "\t";
			cout << current->info << endl;
			current=current->right;
		};
	};

}
int vvod()
{
	cout<<"Vvedite kolichestvo vershin "<<endl;
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
	stack=NULL;
	int num;
	char otv;
	while (true)
	{
		cout << "1. build tree" << endl<< "2. pryamoy obhod" << endl<< "3. symmetric obchod" << endl<< "4. obratnyi symmetric obhod" << endl<<"5. symmetric not recursion"<<endl<< "0. exit"<<endl;
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
				cout << endl << "ok" << endl;
			};
			break;
			case '2':
			if(root!=NULL)
			{
				ShowOnward(root, 0);
			}
			else cout << endl << "derevo pusto" << endl;
			break;
			case '3':
			if(root!=NULL)
			{
				ShowSymmetric(root, 0);
			}
			else
			cout << endl << "derevo pusto" << endl;
			break;
			case '4':
			if(root!=NULL)
			{
				ShowBackSymmetric(root, 0);
			}
			else
			cout << endl << "derevo pusto" << endl;
			break;
			case '5':
			if (root==NULL)
			{
				cout<<"ne sozdano"<<endl;
				break;
			};
			Symmetric_not_recurs(root,0);
			break;
			case '0':
			return 1;
			default:
			cout << endl << "error" << endl;
			break;
	};

};
//cin.get();

}


