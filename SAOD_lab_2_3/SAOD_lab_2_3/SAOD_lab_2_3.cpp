// SAOD_lab_2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct ITEM 
{
int info;
int next;
};

struct LIST 
{
ITEM arr[5];
int count;
};

void Initial(LIST *plist)
{
	plist->arr[0].next=0;
	plist->count=0;
	for (int i=1;i<5;i++)
	plist->arr[i].next=-1;
}

int Empty(LIST *plist)
{
	if (plist->arr[0].next==0)
		return 1;
	else
		return 0;
}
int Full(LIST *plist)
{
	if(plist->count==5-1)
		return 1;
	else
		return 0;
}

int EmptyGet(LIST *plist)
{
	for (int i=1;i<5;i++)
		if (plist->arr[i].next==-1)
			return i;
	return 0;
}

void Show(LIST *plist)
{
int tmp=plist->arr[0].next;
	while(tmp!=0)
	{
		cout << plist->arr[tmp].info << " ";
		tmp=plist->arr[tmp].next;
	}
	cout << endl;
}

int Search(LIST *plist, int num, int *pred)
{
	if(pred)
		*pred=0;
	int tmp=plist->arr[0].next;
	while(tmp!=0 && plist->arr[tmp].info!=num)
	{
		if(pred)
			*pred=tmp;
		tmp=plist->arr[tmp].next;
	}
	return tmp;
}

void AddDo(LIST *plist, int find, int num, int pred)
{
int i=EmptyGet(plist);
	plist->arr[i].next=find;
	plist->arr[pred].next=i;
	plist->arr[i].info=num;
	plist->count++;
}

void AddPosle(LIST *plist, int find, int num)
{
int i=EmptyGet(plist);
	plist->arr[i].next=plist->arr[find].next;
	plist->arr[i].info=num;
	plist->arr[find].next=i;
	plist->count++;
}

void Del(LIST *plist, int find, int pred)
{
	plist->arr[pred].next=plist->arr[find].next;
	plist->arr[find].next=-1;
	plist->count--;
}

int main()
{
setlocale(LC_ALL,"Russian");
LIST list;
Initial(&list);
int num, tmp;
int find, pred;
char otv, otv2;
do
{
	puts("\n==============================================");
	puts(" 1 - add");
	puts(" 2 - del\n 3 - show\n 4 - search\n 5 - Exit\n");
	puts("==============================================\n");
	cin >> otv;

	switch(otv)
	{
		case '1':
			if (Full(&list)==1)
				printf("Список полный");
			else
			{
				printf("Введите элемент = ");
				cin >> num;
				if (Empty(&list)==1)
				{
					AddPosle(&list,0,num);
					printf("Элемент добавлен");
				}
				else
				{
					printf("\n1. Добавить до\n2. Добавить после\n");
					cin >> otv2;
						switch(otv2)
						{
							case '1':
								printf("Перед каким элементом добавить");
								cin >> tmp;
								find=Search(&list,tmp,&pred);
								if (find!=0)
								{
									AddDo(&list,find,num,pred);
									printf( "Элемент добавлен" ); 
								}
								else
									printf("Элемент не найден");
									break;
							case '2':
								printf("После какого элемента добавить ");
								cin >> tmp;
								find=Search(&list,tmp,&pred);
								if (find)
								{
									AddPosle(&list,find,num);
									printf("Элемент добавлен"); 
								}
								else
									printf("Элемент не найден");
									break;
						default:
							printf("Ошибка");
							break;
						}
				}
			}
		break;
		case '2':
			if (Empty(&list)==1)
				printf("Список пуст");
			else
			{
				printf("Введите удаляемый элемент  ");
				cin >> num;
				find = Search(&list,num,&pred);
				if (find!=0)
				{
					Del(&list,find,pred);
					printf("Элемент удален" );
				}
				else
					printf("Элемент не найден");
			}
		break;
		case '3':
			if (Empty(&list)==1)
				printf("Список пуст");
			else
				Show(&list);
		break;
		case '4':
			if (Empty(&list)==1)
				printf("Список пуст");
			else
			{
				printf("Поиск элемента  ");
				cin >> num;
				find = Search(&list,num,0);
				if (find!=0)
					cout << endl << "Элемент найден. Индекс  " << find <<endl;
				else
					printf("Такого элемента нет");
			}
		break;
		case '0':
		break;
	default:
		printf("Ошибка");
	break;
	}
}
while(otv!='0');
cin.get();
}
