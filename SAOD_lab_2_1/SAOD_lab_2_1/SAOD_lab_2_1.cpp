// SAOD_lab_2_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>

int list[10];
int last = 0;//ссылка на по конец очереди
int first = 0;//ссылка на начало очереди
int count = 0;//количество элементов
void view()
{
	int i;
	if (list[0]!=0)
	{
		for (i=0;i<10;i++)
		{
			if (list[i]!=0)
				printf("[%d]%d ",i,list[i]);
		}
	}
	else
		printf("V spiske net elementov");
	printf("\n");
	system("pause");
}

void search()
{
	char n[10];
	int nn, boo=0;
	printf("Vvedite chislo, kotoroe nuzhno naiti\n");
	gets(n);
	if (atoi(n)!=0)
	{
		nn=atoi(n);
		for (int i=0;i<10;i++)
		{
			if (list[i]==nn)
			{
				printf("list[%d]=%d, ",i,list[i]);
				boo=1;
			}
		}
		if (boo==0)
			printf ("Net elementov, udovletvorauchih usloviam");
		printf("\n");
	}	
	else
		printf("Neverno vvedeno znachenie\n");
	system("pause");
}

void add()
{
	char n[10];
	int i, nn;
	printf("vvedite znachenie\n");
	gets(n);
	if (atoi(n)!=0)
	{
		nn=atoi(n);
		for (i=9;(i)!=0 && !((list[i-1]<=nn) && list[i-1]!=0 && ((list [i]>=nn)||list [i]==0)) ;i--)
		{
			list [i]=list[i-1];
		}
		list[i]=nn;
		printf("vstavka v %d\n", i);
	}
	else 
		printf ("Nepravilno vvedeno znachenie\n");
	//if (last < 10 && count < 10)
	//{
	//	list[last] = nn;
	//}
}

void del()
{
	int i,n;
	printf("vvedite nomer udalyaemogo elementa\n");
	scanf("%d",&n);
	for (i=n; i<10;i++)
		list[i]=list[i+1];

}

int _tmain(int argc, _TCHAR* argv[])
{
	view();
	add();
	view();
	del();
	view();
	search();
	return 0;
}