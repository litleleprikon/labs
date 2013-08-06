// SAOD_lab_3_1: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct LIST 
{
	int info;
	LIST *next;
	LIST *prev;
};

LIST *head;
	int n1, n2;

void Initial()
{
	head = new LIST;
	head->next=head;
	head->prev=head;
}

int Empty()
{
	if (head->next==head && head->prev==head)
		return 1;
	else
		return 0;
}

LIST *SearchOnward(int num)
{
	LIST *tmp=head->next;
	while(tmp!=head && tmp->info!=num)
	{
		tmp=tmp->next;
		n1++;
	}
	if (tmp!=head)
		return tmp;
	else
		return NULL;
}

LIST *SearchBack(int num)
{
	LIST *tmp=head->prev;
	while(tmp!=head && tmp->info!=num)
	{
		tmp=tmp->prev;
		n2++;
	}
	if (tmp!=head)
		return tmp;
	else
		return NULL;
}

int Del(int num)
{
	LIST *current=SearchOnward(num);
	if (current!=NULL)
	{
		current->prev->next=current->next;
		current->next->prev=current->prev;
		delete current;
		return 1;
	}
		return 0;
}

int AddAfter(int num, int point)
{
	if (Empty()==1)
{
	LIST *tmp=new LIST;
	tmp->next=head;
	tmp->prev=head;
	tmp->info=num;
	head->next=tmp;
	head->prev=tmp;
	return 1;
}

LIST *current=SearchOnward(point);
	if (current!=NULL)
	{
		LIST *tmp=new LIST;
		tmp->next=current->next;
		tmp->prev=current;
		tmp->info=num;
		current->next->prev=tmp;
		current->next=tmp;
		return 1;
	}
	return 0;
}

int AddBefore(int num, int point)
{
	LIST *current=SearchBack(point);
	if(current!=NULL)
	{
		LIST *tmp=new LIST;
		tmp->info=num;
		tmp->next=current;
		tmp->prev=current->prev;
		current->prev->next=tmp;
		current->prev=tmp;
		return 1;
}
return 0;
}

void ShowOnward()
{
	LIST *tmp=head->next;
	cout << endl << "V pryamom napravlenii" << endl;
	while(tmp!=head)
	{
		cout << tmp->info << " ";
		tmp=tmp->next;
	}
	cout << endl;
}

void ShowBack()
{
	LIST *tmp=head->prev;
	cout << endl << "V obratnom" << endl;
	while(tmp!=head)
	{
		cout << tmp->info << " ";
		tmp=tmp->prev;
	}
	cout << endl;
}

int main()
{
Initial();
int num, tmp;
char otv, otv2;
do
{
	printf("\n1. add\n2. del\n3. view\n4. search\n0. exit\n");
	cin >> otv;
	switch(otv)
	{
		case '1':
			printf("Vvedite element \n");
			cin >> num;
			if (Empty()==1)
			{
					AddAfter(num,0);
					printf("element dobavlen\n");
			}
			else
			{
				printf("1. add after\n2. add before\n");
				cin >> otv2;
				switch(otv2)
				{
				case '1':
					printf("kuda dobavit\n ");
					cin >> tmp;
					if (AddBefore(num,tmp)==1)
						printf("ok");
					else
						cout << endl << "netu elementa" << endl;
				break;
				case '2':
					printf("kuda dobavit\n ");
					cin >> tmp;
					if (AddAfter(num,tmp)==1)
						cout << endl << "ok" << endl;
					else
						printf("netu elementa\n");
				break;
				default:
				printf("error\n");
				break;
			}

			}
			break;

		case '2':
		if(Empty()==1)
			printf("list empty\n");
		else
		{
			printf("nomer elementa \n");
			cin >> num;
			if(Del(num)==1)
			printf("ok\n");
			else
			printf("net elementa\n");
		}
		break;
		case '3':
			if(Empty()==1)
			printf("list empty");
			else
			{
				printf("1. pryamoi obhod\n2. obratnyi\n");
				cin >> otv2;
				switch(otv2)
				{
					case '1':
						ShowOnward();
					break;
					case '2':
						ShowBack();
					break;

					default:
						printf("error");
					break;
				}

			}
		break;

		case '4':
			if(Empty()==1)
			printf("list is empty\n");
			else
			{
				printf("element poiska ");
				cin >> num;
				n1=0;
				n2=0;

				if(SearchOnward(num)!=NULL && SearchBack(num)!=NULL)
				{
					printf("ok");
					cout << endl << "v pryamom napravlenii " << n1 << endl;
					cout << endl << "v obratnom " << n2 << endl;
				}
				else
					printf("elementa net\n");
			}
		break;

		case '0':
		break;
		default:
		printf("error");
		break;
	}

}while(otv!='0');
cin.get();

}