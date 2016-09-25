#include<iostream>

using namespace std;

class SeqList
{
public:
	SeqList() { length = 0; }
	~SeqList() {}

	void Insert(int x);
	void PrintList();
	int date[100];
	int length;
};

//下溢-1  上溢0 位置不正确1
void SeqList::Insert(int x)
{
	if (length > 21)
		return ;
	date[length+1] = x;
	length++;
}

void SeqList::PrintList()
{
	for (int i = 1; i <= length; i++)
		cout << date[i] << endl;
}

void I(SeqList  a,SeqList b)
{
	int i = 1;
	int temp = a.length;
	while(temp--)
	{
		
		for(int j = 1; j <= b.length;j++)
		{
			if(a.date[i] == b.date[j])
			{
				cout<<a.date[i]<<endl;
				break;
			}
		}
		i++;
	}
}

void U(SeqList a,SeqList b)
{
	int i = 1; int temp = a.length;
	int j;
	while(temp--)
	{
		cout<<a.date[i]<<endl;
		i++;
	}
	temp = b.length; i = 1;
	while(temp--)
	{
		for(j = 1; j <= a.length;j++)
		{
			if(b.date[i] == a.date[j])
				break;
		}
		if(j > a.length)
			cout<<b.date[i]<<endl;
		i++;
	}
}
int main()
{
	SeqList  a ;
	SeqList  b ;
	char c;
	while(cin>>c)
	{
		if(c == 'A')
		{
			int n,x;
			cin>>n;
			for(int i = 0; i < n; i++)
			{
				cin>>x;
				a.Insert(x);
			}
		}
		if(c == 'B')
		{
			int n,x;
			cin>>n;
			for(int i = 0; i < n; i++)
			{
				cin>>x;
				b.Insert(x);
			}
		}
		if(c == 'U')
		{
			U(a,b);
		}
		if(c == 'I')
		{
			I(a,b);
		}
		if(c == 'E')
			break;
	}
return 0;
}
