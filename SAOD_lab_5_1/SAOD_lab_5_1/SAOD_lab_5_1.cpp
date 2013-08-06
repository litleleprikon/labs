// SAOD_lab_5_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

struct TREE
{
	int key;
	int count;
	TREE *left;
	TREE *right;
};

TREE *pRoot;
TREE *pTEMP;
int x;

TREE *Search(int i)
{
	TREE *pCurrent;
	bool stop;
	pCurrent=pRoot;
	stop=false;
	while ((pCurrent!=NULL)&&(stop==false))
	{
		if (i<pCurrent->key)
		{
			pCurrent=pCurrent->left;
		}
		else
		{
			if (i>pCurrent->key)
			{
				pCurrent=pCurrent->right;
			}
			else
			{
				stop=true;
			};
		};
	};
	return pCurrent;
}
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


void ShowBackSymmetric(TREE *current, int l)
{
	if(current!=NULL)
	{
		ShowBackSymmetric(current->right, l+1);
		for(int i=0;i<l;i++)
		cout << "\t";
		cout << current->key << endl;
		ShowBackSymmetric(current->left, l+1); 
	};
}
void AddTREE(TREE * &pCurrent, int KEY)
{
//	int x=(*pCurrent)->key;
	if (pCurrent==NULL)
	{
			TREE *pTemp=new TREE;
			pTemp->key=KEY;
			pTemp->left=NULL;
			pTemp->right=NULL;
			pTemp->count=1;
			pCurrent=pTemp;
	}
	else
		{
			if (KEY<pCurrent->key) 
			{
				AddTREE(pCurrent->left, KEY);
			}
			else 
			{
				if (KEY>pCurrent->key)	
				{
					AddTREE(pCurrent->right, KEY);
				}
				else 
				{
					pCurrent->count++;
				}
			}
		}
}
void AddTREE_not(int i)
{

	if (pRoot==NULL)
	{
		pRoot=new TREE;
		pRoot->key=i;
		pRoot->left=NULL;
		pRoot->right=NULL;
		pRoot->count=1;
	}
	else
	{
		TREE *pCurrent, *pParent;
		pCurrent=pRoot;
		while (pCurrent!=NULL)
		{
			pParent=pCurrent;
			if (i<pCurrent->key)
			{
				pCurrent=pCurrent->left;
			}
			else
			{
				if (i>pCurrent->key)
				{
					pCurrent=pCurrent->right;
				}
				else
				{
					pCurrent=NULL;
					pParent->count++;
				};
			};
		};
		if (i<pParent->key)
		{
			pCurrent=new TREE;
			pCurrent->key=i;
			pCurrent->left=NULL;
			pCurrent->right=NULL;
			pCurrent->count=1;
			pParent->left=pCurrent;
		}
		else
		{
			if (i>pParent->key)
			{
				pCurrent=new TREE;
				pCurrent->key=i;
				pCurrent->left=NULL;
				pCurrent->right=NULL;
				pCurrent->count=1;
				pParent->right=pCurrent;
			};
		};
	};
};
void ShowSymmetric(TREE *pCurrent)
{
	if(pCurrent!=NULL)
	{
		ShowSymmetric(pCurrent->left);
		cout << pCurrent->key<<"("<<pCurrent->count<<")"<<"\t" ;
		ShowSymmetric(pCurrent->right); 
	}
}

TREE *poisk(int x)
{
	TREE *pCurrent;
	pCurrent=pRoot;
	bool stop=false;
	while ((pCurrent!=NULL)&&(stop=false))
	{
		if (x<pCurrent->key)
		{
			pCurrent=pCurrent->left;
		}
		else
		{
			if (x>pCurrent->key)
			{
				pCurrent=pCurrent->right;
			}
			else
			{
				//stop=true;
				return pCurrent;
			};
		};

	};
	return NULL;
};
void Changer ( TREE * &p, TREE * &tmp)
{
 if (p->right !=NULL) Changer ( p->right, tmp);
 else                   
 {
  tmp->key= p->key;   
  tmp = p;                
  p= p->left;     
 };
};
void   DeleteNode (TREE * &Current,int x)
{

 TREE *temp;
 if  (Current == NULL)  cout<<"nechego udalyat"<<endl;
 else  
  if  (x < Current->key)  DeleteNode ( Current->left,x);
  else
   if  (x > Current->key)  DeleteNode (Current->right,x);
   else                                  
   {
    temp = Current;
    if   (temp->right == NULL)  Current =  Current->left;
    else  
     if   (temp->left == NULL)  Current =  Current->right;
     else                           
      Changer (  Current->left, temp);  
    delete ( temp);
   };

};
void del()
{
  if (pRoot==NULL) cout<<"tree empty"<<endl;
 else {
 cout<<"vvedite chislo dlya poiska"<<endl;
 int x;
 x=vvod();
 if (x!=NULL)
 {
 DeleteNode(pRoot,x);
 }
 };
}
int main()
{
	pRoot=NULL;
	pTEMP=NULL;
	char op[100];
	while(true)
	{
		cout<<"vyberite punkt"<<endl;
		cout<<"1. vvod dereva po elementam recursia"<<endl;
		cout<<"2. vvod dereva po elementam ne recursia"<<endl;
		cout<<"3. udalit element s kluchom"<<endl;
		cout<<"4. vuvesti kluchi v stroku"<<endl;
		cout<<"5. obratnuy simm"<<endl;
		cout<<"6. sgenerirovat randomnoe derevo"<<endl;
		cout<<"0. exit"<<endl;
		cin>>op;
		switch (op[0])
		{
			case '1': /*AddTREE_not(); break;*/
				{
					int i=vvod();
					if (i==NULL) break;
					AddTREE(pRoot, i);
				}; 
				break;
			case '2':
				{
				int j=vvod();
				if (j!=NULL)
				{
					AddTREE_not(j);
				};
				};
				break;
			case '3':
				/*TREE *p;
				{
					pTEMP=NULL;
					x=vvod();
					if (x!=NULL)
					{
					DeleteTREE(pRoot);
					};
					x=0;
					pTEMP=NULL;
					p=poisk(x);
				};*/
				del();
				break;
			case '4': 
				{
					ShowSymmetric(pRoot);
					cout<<endl;
				};
				break; 
			case '5': ShowBackSymmetric(pRoot,0); break;
			case '6': 
				int current;
				//ClearTree(&pRoot);
				current=vvod();
				if (current!=NULL)
				{
					for (int i=0;i<current;i++)
					{
						int key=rand()%100;
						AddTREE(pRoot,key);
					};
				};
				break;
/*
			case '7':
				ClearTree(&pRoot);
				break;
				*/
			case '0': return 1;
			default: cout<<"error"<<endl; break;
		};
	};
};

