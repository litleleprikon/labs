// SAOD_lab_7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <ctime>
using namespace std;

 int* fs;
int num;

void generate()
{
	printf("na skolko elementov sozdat massiv?\n");
	scanf("%d",&num);
	fs=new int[num];
	srand(time(NULL));
	for(int i=0;i<num;i++)
	{
		fs[i]=rand()%100;
		printf("%d ",fs[i]);
	}
	printf("\n");
}

void bubbleSort(int as[], int len)
{
	  int *arr=new int[len];
  for(int i=0;i<len;i++)
	  arr[i]=as[i];
	int peres=0,srav=0;
for (int i=len-1;i>0;i--)
  {
    for (int j=0;j<i;j++)
      {
        if(arr[j]>arr[j+1])
          {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
			peres++;
          }
		srav++;
     }
  }
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\nperes=%d srav=%d\n",peres,srav);
}

void insertSort(int as[], int len)
{
	  int i,j,per=0,sr=0;
  int *arr=new int[len];
  for(int i=0;i<len;i++)
	  arr[i]=as[i];
  int temp;

  for(i=1; i < len; ++i) 
  {
    temp = arr[i];
	++per;
    for(j=i-1; (j >= 0) && (temp < arr[j]); j--)
	{
		sr++;
		arr[j+1] = temp;
      arr[j+1] = arr[i];
	}
  }
  	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\nperes=%d srav=%d\n",per,sr);
}

void metod2(int as[], int len)
{
	  int *arr=new int[len];
  for(int i=0;i<len;i++)
	  arr[i]=as[i];
	//сортировка вставками
	int count=0,tmp=0,count1=0;
	for (int i = 1; i < len; i++)
	{
		tmp=arr[i];
		int j=i-1;
		while ((j>=0)&&(tmp<arr[j]))
		{
			count=count+1;
			arr[j+1]=arr[j];
			j=j-1;
		}
		count1=count+1;
		arr[j+1]=tmp;
	}
	for (int i = 0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"peres: "<<count<<" srav: "<<count1<<endl;
}

void selectionSort(int as[], int len) {
	int peres=0,srav=0;
  int *arr=new int[len];
  for(int i=0;i<len;i++)
	  arr[i]=as[i];
    for (int i = 0; i < len - 1; i++) 
	{
		int temp;
        int min = i; 
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[min])
                min = j;
			srav++;
        }
        if(min != i) 
		{
            temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
			peres++;
		}
    }
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\nperes=%d srav=%d\n",peres,srav);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	do
	{
		puts("\n==============================================");
		puts(" 1 - generate");
		puts(" 2 - selectionSort\n 3 - bubbleSort\n 4 - insertSort\n 6 - Exit\n");
		puts("==============================================\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : generate(); break;
			case 2 : selectionSort(fs,num); break;
			case 3 : bubbleSort(fs,num); break;
			case 4 : metod2(fs,num); break;
			//case 5 : show_stack(); break;
			case 6 : break;
			default : puts("\nError");
			getchar();
		}
	}
	while(n!=6);

	return 0;
}

