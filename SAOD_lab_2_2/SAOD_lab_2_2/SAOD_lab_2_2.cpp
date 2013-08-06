// SAOD_lab_2_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include<iostream>

struct elList
{
	int val;
	elList * next;
}
*head, *lp, *backup;

elList * search(int reg)
{
	int num, i=0;
	printf("Vvedite Nomer elementa\n");
	scanf("%d",&num);
	if (reg==0)
		num=num-1;
	else
		if (reg==1)
			num=num;
	lp=head;
	printf("reg %d\n", reg);
	while (lp->next!=NULL && i<num)
	{
		lp=lp->next;
		i++;
	}
	if (i<num-1)
	{
		printf("Takogo elementa net\n");
		return NULL;
	}
	else
		return lp;
	lp=NULL;
}

void addAfter()
{
	int val;
	printf("Vvedite znachenie after\n");
	scanf("%d",&val);
	if (head->next==NULL)
	{
		head->next=new elList;
		head->next->next=NULL;
		head->next->val=val;
	}
	else
	{
		elList* current=search(0);
		if (current!=NULL)
		{
			lp=new elList;
			lp->val=val;
			lp->next=current->next;
			current->next=lp;
			printf("operaciya udachno zavershena\n");
			lp=NULL;			
		}
	}

}

void addBefore()
{
	int n;
	printf("Vvedite znachenie before\n");
	scanf("%d",&n);
		elList* current=search(1);
		if (current!=NULL)
		{
			lp=new elList;
			lp->val=n;
			lp->next=current->next;
			current->next=lp;
			printf("operaciya udachno zavershena\n");
			lp=NULL;
		}
		else printf("Vy vveli nepravilnoe znachenie\n");
}

void show()
{
	int i=0;
	lp=head->next;
	while(lp!=NULL)
	{
		printf("[%d]=%d ",i,lp->val);
		lp=lp->next;
		i++;
	}
	printf("\n");
	system("pause()");
}

void show_stack()
{
	lp=backup;
	while(lp!=NULL)
	{
		printf("%d ",lp->val);
		lp=lp->next;
	}
}

void del()
{
	int val, i=0;
	printf("Vvedite znachenie\n");
	scanf("%d",&val);
	lp=head;
	while (lp->next!=NULL && lp->next->val!=val)
	{
		lp=lp->next;
	}
	if (lp->next!=NULL)
	{
		elList * point=lp->next;
		lp->next=lp->next->next;
		point->next=backup;
		backup=point;
	}
	else 
		printf("elementa net");
}

void view()
{
	lp=backup;
	while (lp->next!=NULL)
		printf("%d ",lp->val);
	printf("\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	head=new elList;
	head->next=NULL;
	head->val=NULL;
	int n;
	do
{
	puts("\n==============================================");
	puts("1 - addAfter");
	puts(" 2 - addBefore\n 3 - del\n 4 - show\n 5 - show_stack\n 6 - Exit\n");
	puts("==============================================\n");
	scanf("%d",&n);
	switch(n)
    {
		case 1 : addAfter(); break;
		case 2 : addBefore(); break;
		case 3 : del(); break;
		case 4 : show(); break;
		case 5 : show_stack(); break;
		case 6 : break;
		default : puts("\nError");
		getchar();
    }
}
 while(n!=6);
	return 0;
}

