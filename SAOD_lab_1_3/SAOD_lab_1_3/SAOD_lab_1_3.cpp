// SAOD_lab_1_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
using namespace std;

struct queue
{
	char val;
	queue *next;
}
* head=NULL, * lp=NULL;

void add(char val)
{
	lp=new queue;
	lp->val=val;
	lp->next=head;
	head=lp;
}

void del()
{
	lp=head;
	queue * sleeper;
	int i=0;
	while (lp->next!=NULL)
	{
		sleeper=lp;
		lp=lp->next;
		//printf("%d",i );
		i++;
	}
	//printf("\n");
	sleeper->next=NULL;
	delete (lp);
}

void view()
{
	int i=0;
	lp=head;
	while (lp!=NULL)
	{
		printf("[%d]%c ",i,lp->val);
		lp=lp->next;
		i++;
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{
		int c;
		c=rand()%25+65;
		switch(rand()%2)
		{
		case 0 : add((char)c); break;
		case 1 : if (head!=0) del(); break;
		}
		view();
	Sleep(1000);	
	}
	return 0;
}