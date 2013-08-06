// SAOD_lab_9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctime>

int *fs;
int num;

void generate()
{
	printf("na skolko elementov sozdat massiv?\n");
	scanf("%d",&num);
	fs=new int[num];
	srand(time(NULL));
	for(int i=0;i<num;i++)
		fs[i]=i;
	int tmp;
	for (int i=0; i<num;i++)
	{
		int k1=rand()%num;
		int k2=rand()%num;
		tmp=fs[k1];
		fs[k1]=fs[k2];
		fs[k2]=tmp;
	}
	for (int i=0;i<num;i++)
		printf("%d ",fs[i]);
	printf("\n");	
}

void bucketSort()
{
	int *bsa=new int[num];
	for (int i=0;i<num;i++)
		bsa[fs[i]]=fs[i];
	for (int i=0;i<num;i++)
		printf("%d ",bsa[i]);
	printf("\n");
}

void bucketSortHard(int arr[])
{
	int tmp;
	for (int i=0; i<num;i++)
	{
		while(arr[i]!=i)
		{
			tmp=arr[arr[i]];
			arr[arr[i]]=arr[i];
			arr[i]=tmp;
		}
	}
	for (int i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	do
	{
		puts("\n==============================================");
		puts(" 1 - generate");
		puts(" 2 - bucketSort\n 3 - bucketSortHard\n 6 - Exit\n");
		puts("==============================================\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : generate(); break;
			case 2 : bucketSort(); break;
			case 3 : bucketSortHard(fs); break;
			//case 4 : insertSort(fs,num); break;
			//case 5 : show_stack(); break;
			case 6 : break;
			default : puts("\nError");
			getchar();
		}
	}
	while(n!=6);
	return 0;
}

