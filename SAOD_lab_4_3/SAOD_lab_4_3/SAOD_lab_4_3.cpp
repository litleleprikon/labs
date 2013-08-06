// SAOD_lab_4_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#define null NULL

struct node
{
	int val;
	node* left;
	node* right;
}
* root, *tp;

void clearNode(node* n)
{
	if(n->left!=null)
	{
		clearNode(n->left);
		delete n->left;
	}
	if(n->right!=null)
	{
		clearNode(n->right);
		delete n->right;
	}
	n->val=null;
}

node* Add()
{
	printf("sozdan element\nVvedite znachenie\n");
	node* n=new node;
	n->left=null;
	n->right=null;
	scanf("%d",&n->val);
	while(true)
	{
		printf("vvesti potomka?\n1)da\n");
		if (getch()==49&&(n->left==null||n->right==null))
		{
			printf("sleva(1) ili sprava(2)\n");
			switch (getch())
			{
			case 49: 
				if(n->left==null)
					n->left=Add(); 
				else 
					printf("takoy element uzhe est\n");
				break;
			case 50: 
				if(n->right==null)
					n->right=Add(); 
				else 
					printf("takoy element uzhe est\n");
				break;
			default : printf("nepravilno vubran punkt\n");break;
			}
		}
		else break;
	}
	return n;
}


void symmetric(node*n,int num)
{
	if (n->left!=NULL)
		symmetric(n->left,num+1);
	for(int i=0;i<num;i++)
		printf("\t");
	printf("%d\n",n->val);
	if (n->right!=NULL)
		symmetric(n->right,num+1);
}

void direct(node*n,int num)
{
	for(int i=0;i<num;i++)
		printf("\t");
	printf("%d\n",n->val);
	if (n->left!=NULL)
		direct(n->left,num+1);
	if (n->right!=NULL)
		direct(n->right,num+1);
}

void search(node*n,int num, int val)
{
	if (n->left!=NULL&&n->val!=val)
		search(n->left,num+1, val);
	for(int i=0;i<num;i++)
		printf("\t");
	printf("%d\n",n->val);
	if (n->right!=NULL&&n->val!=val)
		search(n->right,num+1,val);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	do
	{
		puts("\n==============================================");
		puts(" 1 - Build tree");
		puts(" 2 - delete tree\n 3 - symmetric\n 4 - direct\n 5 - search\n 6 - Exit\n");
		puts("==============================================\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : 
				if(root==null)
					root=Add(); 
				else 
					printf("Snachala udalite derevo\n");
				break;
			case 3 : if (root!=null) symmetric(root,0); break;
			case 2 : 
				if (root!=null)
				{
					clearNode(root); 
					delete root;
					root=null;
					printf("tree deleted\n");
				}
				else
					printf("snachala sozdaite derevo\n");
				break;
			case 4 :if (root!=null) direct(root,0); break;
			case 5 : 
				printf("kakoy element vvesti?\n");
				int val;
				scanf("%d",&val);
				search(root,0,val); break;
			case 6 : break;
			default : puts("\nError");
			getchar();
		}
	}
	while(n!=6);	
	return 0;
}

