//���� �14
# include <iostream>
# include <locale.h>
# include <time.h>
# include <cmath>
#include "stdafx.h"

using namespace std;
const int N=100;
int mass[N], count2=0,count3=0;
void  MassCreator()
{
	//�������� �������
	for (int i = 0; i < N; i++)
	{
		mass[i]=rand()%100;
	}
	
}




void metod1(int mass2[N])
{
	//����� ��������
	int tmp=0,count=0,count1=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j >= i; j--)
		{
			
			if (mass2[j-1]>mass2[j])
			{
				count++;
				tmp=mass2[j-1];
				mass2[j-1]=mass2[j];
				mass2[j]=tmp;
				
			}
			count1++;
		}
	}
	cout<<"���������� ������� ��������: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count<<" ����� ���������: "<<count1<<endl;
}

void metod2(int mass2[N])
{
	//���������� ���������
	int count=0,tmp=0,count1=0;
	for (int i = 1; i < N; i++)
	{
		tmp=mass2[i];
		int j=i-1;
		while ((j>=0)&&(tmp<mass2[j]))
		{
			count=count+1;
			mass2[j+1]=mass2[j];
			j=j-1;
		}
		count1=count+1;
		mass2[j+1]=tmp;
	}
	cout<<"���������� ������� ��������: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count<<" ����� ���������: "<<count1<<endl;
}

void metod3(int mass2[N])
{
	//���������� �������
	int count=0,k=0,tmp=0,count1=0;
	for (int  i= 0; i < N; i++)
	{
		k=i;
		tmp=mass2[i];
		for (int j =i+1; j < N; j++)
		{
			count1=count1+1;
			if (mass2[j]<tmp)
			{
				k=j;
				tmp=mass2[j];
			}
		}
		if(k!=i)
		{
		mass2[k]=mass2[i];
		mass2[i]=tmp;
		count=count+1;
		}
	}
	cout<<"���������� ������� ������: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count<<" ����� ���������: "<<count1<<endl;
}

void metod4(int mass2[N])
{
	//����� �����
	int count=0,tmp=0,count1=0,m,k,j;
	m=int(log10(N)/log10(2));//����� ����� �����������
	int mass1[N/2];//������ ����� �����������
	for (int i = 0; i < m; i++)
	{
		mass1[i]=(int)(pow(2,i+1)-1);
	}
	for (int l = m; l >= 1; l--)
	{
		k=mass1[l-1];
		for (int i = k; i < N; i++)
		{
			tmp=mass2[i];
			j=i-k;
			while (j>=0 && tmp<mass2[j])
			{
				count=count+1;
				mass2[j+k]=mass2[j];
				j=j-k;
			}
			count1=count1+1;
			mass2[j+k]=tmp;
		}
	}
	cout<<"���������� ������� �����: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count1<<" ����� ���������: "<<count+count1<<endl;
}

void QuickSort (int mass2[N],int left, int right)
{
	int count=0, count1=0;
	int i = left;
	int j = right; /*��������� ��������� �������� ������ ����������*/
	int middle = mass2[(left+right)/2]; /*����������� ����������� ��������*/
	while (i<=j)
	{
		while (mass2[i]<middle) /*����� ����� ��������, �������� ��������*/
			{
				i++; 
				count3++;
			}
		while (mass2[j]>middle)/*����� ������ ��������, �������� ��������*/
			{
				j--;
				count3++;
			}
		//count3=count3+(i-left)+(right-j)+1;
		count3=count3+2;
		if (i<=j)
		{ /*���������� �������� � �������� �������*/
			count2=count2+1;
			int tmp=mass2[i];
			mass2[i]=mass2[j];
			mass2[j]=tmp;
			i=i+1;
			j=j-1;
		}
	}
	if (left<j)
		QuickSort(mass2,left,j); /*��������� ����� ��������*/
	if (i<right)
		QuickSort(mass2,i,right); /*��������� ������ ��������*/
}

void metod5(int mass2[N])
{
	//������� ����������
	int count=0, count1=0, left=0, right =N-1;

	QuickSort(mass2,left,right);
	cout<<"������� ����������: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count2<<" ����� ���������: "<<count3<<endl;
}

void sito(int al, int ar,int mass2[N])
{
	//���������� ���������
	int i,j,el;
	i=al;
	j=2*al;
	el=mass2[al];
	if ((j<ar)&&(mass2[j+1]<mass2[j]))
	{
		j=j+1;
		count3++;
	}
	while ((j<=ar)&&(mass2[j]<el))
	{
		mass2[i]=mass2[j];
		count3++;
		i=j;
		j=2*j;
		if ((j<ar)&&(mass2[j+1]<mass2[j]))
		{
			j++;
			count3++;
		}
	}
	count2++;
	mass2[i]=el;
}

void metod6(int mass2[N])
{
	//������������� ����������
	int left=(int)(N/2)+1,hlp,right=N-1,count=0,count1=0;
	while (left>0)
	{
		left=left-1;
		sito(left,right,mass2);
	}
	while (right>0)
	{
		hlp=mass2[0];
		mass2[0]=mass2[right];
		mass2[right]=hlp;
		right= right-1;
		sito(left,right,mass2);
	}
	cout<<"������������� ����������: "<<endl;
	for (int i = N-1; i >= 0; i--)
	{
		cout<<mass2[i]<<" ";
	}
	cout<<endl;
	cout<<"����� ������������: "<<count2<<" ����� ���������: "<<count3<<endl;
}

void main ()
{
	MassCreator();
	int mass_copy[N];
	int chs;
	srand(time(NULL));
	setlocale(LC_ALL,"Russian");
	do
	{
		cout<<"���������� �������: "<<endl;
		for(int i=0;i<N;i++)
		{
		mass_copy[i]=mass[i];
		cout<<mass_copy[i]<<" ";
		}
		cout<<endl;
	
		cout<<"�������� ����� ����������: "<<endl;
		cout<<"1 - ������ ��������"<<endl;
		cout<<"2 - ������� ����������"<<endl;
		cout<<"3 - ���������� ���������"<<endl;
		cout<<"4 - ������� �����"<<endl;
		cout<<"5 - ���������� �������"<<endl;
		cout<<"6 - ������������� ����������"<<endl;
		cout<<"0 - �����"<<endl;
		cin>>chs;
		switch (chs)
		{
			case 1: metod1(mass_copy); system("pause"); system("CLS"); break;
			case 2: metod5(mass_copy); system("pause"); system("CLS"); break;
			case 3: metod2(mass_copy); system("pause"); system("CLS"); break;
			case 4: metod4(mass_copy); system("pause"); system("CLS"); break;
			case 5: metod3(mass_copy); system("pause"); system("CLS"); break;
			case 6: metod6(mass_copy); system("pause"); system("CLS"); break;
			default: break;
		}
	} while (chs!=0);
}