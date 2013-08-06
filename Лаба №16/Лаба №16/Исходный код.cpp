#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

const int N=9;


int Hash(string key, int n)
{
	int sum=0;
        int length;
        const char *str = key.c_str();
        length = strlen(str);
	for ( int i=0; i<length; i++)
	sum+=(int)key[i];
	return sum%n;
}

string *Create(int n)
{
	const int s=18;
	string *Table = new string [n]; 
	string  str[s]={"END","BEGIN","ELSE","TRUE","FALSE","FOR","WHILE","DO","INTEGER","ARRAY","CHAR","STRING","VAR","String","Int64","End","Int16","32"};
	for ( int i=0; i<n; i++) 
		Table[i].empty(); 
	int k=0;
	while (k<s) 
	{
	
		int  hash = Hash(str[k], n); 
		if (Table[hash].empty()) 
		Table[hash] = str[k]; 
		k++;
	}
	return Table;

}
int Search(string key, string *Table, int n)
{
	int hash=Hash(key, n); 
	if (Table[hash]==key) 
	return hash; 
	else 
	return -1;
}

void Show(string *Table, int n)
{
	for ( int i=0; i<n; i++) 
	cout << "Table[" << i << "] = " << Table[i] << endl;
}

	
void main() 
{   
	srand(time(NULL));
	string *Table=NULL; 
	string key;
	int action;
	char str[10];
	int i,n=0;
	
	do
	 {
		cout<<"\n1.create table\n2.search by key\n3.show table\n0.exit\n";
		cin>>str;
		i=atoi(str);
		switch (i)
		 {		
			case 1:
					if (Table!=NULL) 
					delete[] Table; 
					n=N;
					Table=Create(n); 
					cout << endl << "table is created." << endl; 
					;break;
			case 2:
						if (n!=0) 
					{ 
					cout << endl << "input key: "; 
					cin >> key; 
					if (Search(key, Table, n)!=-1) 
					cout << endl << "index: " << Search(key, Table, n) << endl; 
					else 
					cout << endl << "key not found" << endl; 
					} 
					else 
					cout << endl << "table is not created." << endl; 
					break;
			case 3:
					if (n!=0) 
					Show(Table, n); 
					else 
					cout << endl << "table is not created." << endl; 
					break;
			case 0:exit(0);break;
			default:cout<<"error\n\n";break;
		}
	 
		
	}
		while(i!=0);
		getche();
}






