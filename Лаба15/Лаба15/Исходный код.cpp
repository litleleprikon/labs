

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
const int N=150;
const int M=140;

struct list
	{
		int info;
		list *next;
		list *prev;
	};

int Rand(int mass[N])
{
	int r=rand()%N;
	for(int i=0;i<N;i++)
		if(mass[i]==r)
		{
			r=rand()%N;
			i=-1;
		}
	return r;
}
void CreateSimpleMass(int SimpleMass[N])
{
	for(int i=0;i<N;i++)
		SimpleMass[i]=Rand(SimpleMass);
}


void PocketSort(int mass[N])
{
	char str[10];
	int k=0,tmp;
	int mass2[N];
	int moving=0,comparison=0;
	do
		{
			cout<<"1.with second array \n2.without second array\n";
			cin>>str;
			k=atoi(str);
			if((k!=1)&&(k!=2)) cout<<"error\n";
		}
		while((k!=1)&&(k!=2));
		if(k==1)
		{
			for(int i=0;i<N;i++)
			{
				mass2[mass[i]]=mass[i];
				moving++;
			}
			cout<<"new array:\n";
			for(int i=0;i<N;i++)
				cout<<mass2[i]<<" ";
			cout<<"\nperes: "<<moving<<"  srav:"<<comparison<<endl;
		}
		if(k==2)
		{
			for(int i=0;i<N;i++)
			{
				comparison++;
				while(mass[i]!=i)
				{
					tmp=mass[i];
					mass[i]=mass[tmp];
					mass[tmp]=tmp;
					moving++;
				}
			}
			cout<<"new array:\n";
			for(int i=0;i<N;i++)
				cout<<mass[i]<<" ";
			cout<<"\nperes: "<<moving<<"  srav:"<<comparison<<endl;
		}
}

void ShowMass(int mass[N])
{
	for(int i=0;i<N;i++)
		cout<<mass[i]<<" ";
	cout<<endl;
}

list *search(int a,list *mass[M])
{
	list *srh=NULL;
	for(int i=0;i<M;i++)
		if(mass[i]!=NULL)
		{
		if(a==mass[i]->info)
			srh=mass[i];
		}
	return srh;

}



void GeneralizeidPocketSort(int mass[N])
{

	list *mass2[M];
	list *tmp;
	list *srh;
	list *hlp;
	int moving=0,comparison=0;
	for(int i=0;i<M;i++)
	{
		mass2[i]=NULL;
	}
	for(int i=0;i<N;i++)
	{
		moving++;
		comparison++;
		comparison+=M;
		srh=search(mass[i],mass2);
		if(srh==NULL)
		 {
			mass2[mass[i]]=new list;
			mass2[mass[i]]->next=mass2[mass[i]];
			mass2[mass[i]]->prev=mass2[mass[i]];
			mass2[mass[i]]->info=mass[i];
		 }
		 else
		 {
			 list *tmp=new list;
			 if(srh->next==srh)
			 {
		
				 tmp->next=srh;
				 tmp->prev=srh;
				 srh->next=tmp;
				 srh->prev=tmp;
			 }
			 else
			 {
				 tmp->next=srh->next;
				 tmp->prev=srh;
				 srh->next->prev=tmp;
				 srh->next=tmp;
			 }
			 tmp->info=mass[i];
		 }
	}

	cout<<"bez povtoryauschihsua elementov:\n";
	for(int i=0;i<M;i++)
		if(mass2[i]!=NULL)
		cout<<mass2[i]->info<<" ";
	cout<<endl;

	cout<<"s povtoryauschimisya elementami:\n";
	for(int i=0;i<M;i++)
	{
		if(mass2[i]!=NULL)
		{
			hlp=mass2[i]->next;
			cout<<mass2[i]->info<<" ";
			while(hlp!=mass2[i])
			{
				cout<<hlp->info<<" ";
				hlp=hlp->next;
			}
		}
	}
	cout<<"\nperes: "<<moving<<endl;//"  Количество сравнений: "<<comparison<<endl;

	list *del;
			for(int i=0;i<10;i++)
			{
				if(mass2[i]!=NULL)
				{
					hlp=mass2[i]->next;
					while(hlp!=mass2[i])
					{
						del=hlp; 
						hlp=hlp->next; 
						hlp->prev=del->prev;
						hlp->prev->next=hlp;
						delete del; 
					}
					delete(mass2[i]);
				}
		
			}
}

list *search2(int a,list *mass[10])
{
	list *srh=NULL;
	for(int i=0;i<10;i++)
		if(mass[i]!=NULL)
		{
		if(a==mass[i]->info)
			srh=mass[i];
		}
	return srh;

}

void RadixSort(int mass[N])
{
	char str[20];
	list *mass2[10];
	list *srh;
	list *hlp;
	int moving=0,comparison=0;
	for(int i=0;i<10;i++)
		mass2[i]=NULL;
	int k=0,t=N,r=0;
	 while(t)
    {
        t/=10;
        k++;
    }
	
	for(int i=k;i>0;i--)
	{
		r++;
		for(int j=0;j<N;j++)
		{
			 moving++;
			itoa(mass[j], str,10);
			char str2[1];
			str2[0]=str[i-1];
			for(int c=0;c<k;c++)
				if(str[c]=='\0')
				{
					if((c-r)>=0)
					str2[0]=str[c-r];
					else str2[0]='0';
					break;
				}
			int p=atoi(str2);
			srh=search2(p,mass2);
			comparison+=11;
			 if(srh==NULL)
			 {
				mass2[p]=new list;
				mass2[p]->next=mass2[p];
				mass2[p]->prev=mass2[p];
				mass2[p]->info=p;	
				if(mass2[p]->next==mass2[p])
				{
					list *tmp=new list;
					 tmp->next=mass2[p];
					 tmp->prev=mass2[p];
					 mass2[p]->next=tmp;
					 mass2[p]->prev=tmp;
					 tmp->info=mass[j];
				}
			 }
			 else
			 {
				 list *tmp=new list;

				 if(srh->next==srh)
				 {
		
					 tmp->next=srh;
					 tmp->prev=srh;
					 srh->next=tmp;
					 srh->prev=tmp;
				 }
				 else
				 {
					 tmp->next=srh;
					 tmp->prev=srh->prev;
					 srh->prev->next=tmp;
					 srh->prev=tmp;
				 }
				 tmp->info=mass[j];
				
			 }
      
	
		}
		int j=0;
		for(int i=0;i<10;i++)
		{
			if(mass2[i]!=NULL)
			{
				hlp=mass2[i]->next;
				while(hlp!=mass2[i])
				{
					mass[j]=hlp->info;
					hlp=hlp->next;
					j++;
					moving++;
				}
			}
		}

		if(i!=1)
		{
			list *del;
			for(int i=0;i<10;i++)
			{
				if(mass2[i]!=NULL)
				{
					hlp=mass2[i]->next;
					while(hlp!=mass2[i])
					{
						del=hlp; 
						hlp=hlp->next; 
						hlp->prev=del->prev;
						hlp->prev->next=hlp;
						delete del; 
					}
				}
		
			}

		}
		
	}

	cout<<"new array:\n";
	for(int i=0;i<10;i++)
	{
		if(mass2[i]!=NULL)
		{
			hlp=mass2[i]->next;
			while(hlp!=mass2[i])
			{
				cout<<hlp->info<<" ";
				hlp=hlp->next;
			}
		}
	}
	cout<<"\nperes: "<<moving<<endl;//"  Количество сравнений:"<<comparison<<endl;
	for(int i=0;i<10;i++)
		delete(mass2[i]);
}
	
void main() 
{   
	srand(time(NULL));
	int Mass[N];
	for(int i=0;i<N;i++)
		Mass[i]=rand()%M;
	int SimpleMass[N];
	CreateSimpleMass(SimpleMass);
	int Copy_Mass[N];
	int Copy_SimpleMass[N];
	char str[10];
	int i;
	
	do
	 {
		 for(int i=0;i<N;i++)
		 {
			 Copy_Mass[i]=Mass[i];
			 Copy_SimpleMass[i]=SimpleMass[i];
		 }



		cout<<"\n1.simple bucket sort\n2.bucket sort\n3.radixSort\n4.show array\n5.show simple array\n0.exit\n";
		cin>>str;
		i=atoi(str);
		switch (i)
		 {		
			case 1:PocketSort(Copy_SimpleMass);break;
			case 2:GeneralizeidPocketSort(Copy_Mass);break;
			case 3:RadixSort(Copy_Mass);break;
			case 4:cout<<"array:\n";ShowMass(Mass);break;
			case 5:cout<<"simple arrray:\n";ShowMass(SimpleMass);break;
			case 0:exit(0);break;
			default:cout<<"array\n\n";break;
		}
	 
		
	}
		while(i!=0);
		getche();
}






