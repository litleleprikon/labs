// SAOD_lab_3_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

struct secondList
{
	int val;
	secondList * next;
}
*slp, *stemp=NULL;

struct firstList
{
	secondList*link;
	firstList*next;
}
*first=NULL, *flp=NULL, *ftemp=NULL;

void add()
{
	bool boo=false;
	if (first==NULL)
	{
		printf("Net ni odnogo elementa v spiske, budet sozdan pervyi element\n");
		first=new firstList;
		ftemp=first;
		ftemp->link=NULL;
		ftemp->next=NULL;
	}
	else
	{
		int boo1;
		printf("Sozdat novyi roditelskiy element?\n 1)Da\n 2)Net\n");
		scanf("%d",&boo1);
		if (boo1==1)
		{
			int num, i=0, j=0;
			printf("Vstavka v roditelya\n");
			printf("Kuda vstavit?\n 1)Do\n 2) Posle\n");
			scanf("%d",&num);
			printf("Ryadom s kakim elementom vstavit?\n");
			scanf("%d",&j);
			if (num==1)
				j-=1;
			flp=first;
			while (flp->next!=NULL&i<j)
			{
				flp=flp->next;
				i++;
			}
			if(i<j-1)
				boo=true;
			ftemp=new firstList;
			ftemp->link=NULL;
			ftemp->next=flp->next;
			flp->next=ftemp;
		}
		if (boo1==2)
		{
			int j=0,i=0;
			printf("V kakoy element roditelya dobavit\n");
			scanf("%d",&j);
			flp=first;
			while (flp->next!=NULL&i<=j)
			{
				flp=flp->next;
				i++;
			}
			if(i<j-1)
				boo=true;
			ftemp=flp;
		}
		if (boo==true)
			printf("takogo elementa net, vstavlenie posle poslednego\n");
		boo=false;
	}
		slp=ftemp->link;
		printf("Vstavka v dite\n");
		if (slp==NULL)
		{
			printf("Dochernih elementov net budet sozdan novyi\n");
			ftemp->link=new secondList;
			ftemp->link->next=NULL;
			printf("Vvedite znachenie\n");
			scanf("%d",&ftemp->link->val);
		}
		else
		{
			printf("Do ili posle vstavit?\n 1)Do\n 2)Posle\n");
			int num=0, i=0, j=0;
			scanf("%d",&num);
			printf("Ryadom s kakim elementom vstavit?\n");
			scanf("%d",&j);
			if (num==1)
				j--;
			slp=ftemp->link;
			while(slp->next!=NULL&i<j)
			{
				slp=slp->next;
				i++;
			}
			if(i<j-1)
				boo=true;
			printf("vvedite znachenie\n");
			stemp=new secondList;
			stemp->next=slp->next;
			slp->next=stemp;
			scanf("%d",&stemp->val);
		}
}

void delFirstRec(secondList *next)
{
	if (next!=NULL)
	{
		delFirstRec(next->next);
		delete next;
	}
}

void delFirst()
{
	printf("Kakoi element roditelya udalit?\n");
	int n=0,i=0;
	scanf("%d",&n);
	flp=first;
	while (flp!=NULL& i<n)
	{
		ftemp=flp;
		flp=flp->next;
		i++;
	}
	if (flp==first)
		first=NULL;
	if (flp!=NULL)
	{
		delFirstRec(flp->link);
		ftemp->next=flp->next;
		delete flp;
	}
	else
		printf("Takogo elementa net\n");
}

void view()
{
	flp=first;
	while (flp!=NULL)
	{
		slp=flp->link;
		while(slp!=NULL)
		{
			printf("%d ",slp->val);
			slp=slp->next;
		}
		flp=flp->next;
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	do
	{
		puts("\n==============================================");
		puts(" 1 - add");
		puts(" 2 - delFirst\n 4 - show\n 6 - Exit\n");
		puts("==============================================\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : add(); break;
			case 2 : delFirst(); break;
			//case 3 : del(); break;
			case 4 :view(); break;
			//case 5 : show_stack(); break;
			case 6 : break;
			default : puts("\nError");
			getchar();
		}
	}
	while(n!=6);
	 	
	return 0;
}

