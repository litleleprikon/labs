#include <iostream>
#include <string>

using namespace std;

const int M=10;

void Initial(string *Table)
{
	for ( int i=0;i<M;i++)
		Table[i].empty();
}

int Hash(string key, int j)
{
	int sum=j;
        int length;
        const char *str = key.c_str();
        length = strlen(str);
	for ( int i=0;i<length;i++)
		sum+=(int)key[i];
	return sum%M;
}

int Add(string *Table, string key, int &count)
{
	int flag=0;
	int hash;
	for ( int i=0;i<M-2;i++)
	{
		hash=Hash(key,i);
		count++;
		if (Table[hash].empty())
		{
			Table[hash]=key;
			flag=1;
			break;
		}
	}
	if (flag) return 1;
	else return 0;
}

int Search(string *Table, string key, int &count)
{
	int flag=0;
	int hash;
	for ( int i=0;i<M-2;i++)
	{
		hash=Hash(key,i);
		count++;
		if (Table[hash]==key)
		{
			flag=1;
			break;
		}
	}
	if (flag) return hash;
	else return -1;
}

void Show(string *Table)
{
	for (int i=0;i<M;i++)
	cout << "Table[" << i << "] = " << Table[i] << endl;
}

int main()
{
	string Table[M];
	Initial(Table);
	string key;
        int count;
	char action;
	do
	{
		cout << endl
		<< "1. add key" << endl
		<< "2. search bu key" << endl
		<< "3. show table" << endl
		<< "0. exit" << endl;
		cin >> action;
		switch(action)
		{
			case '1':
				count=0;
				cout << endl << "enter key";
				cin >> key;
				if (Search(Table, key, count)!=-1)
				cout << endl << "this key was used, srav " << count << endl;
				else
				{
					count=0;
					if (Add(Table, key, count)==1)
					cout << endl << "key is added, srav : " << count << endl;
					else
					cout << endl << "table is full" << endl;
				}
				break;
			case '2':
			        count=0;
				cout << endl << "input key : ";
				cin >> key;
				if (Search(Table, key, count)!=-1)
				cout << endl << "index : " << Search(Table, key, count) << "  srav : " << count << endl;
				else
				cout << endl << "key not found." << endl;
				break;
			case '3':
				Show(Table);
				break;
			case '0':	break;
			default: cout << endl << "error" << endl; break;
		}
	}while(action!='0');
}