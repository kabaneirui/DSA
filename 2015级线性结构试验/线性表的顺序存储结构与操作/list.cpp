#include<iostream>

using namespace std;
template<class DateType>

class SeqList
{
public:
	SeqList(){length = 1;}
	~SeqList(){}

	int lenght(){return length;}
	DateType Get(int i);
	int Locate(DateType x);
	void Insert(int i,DateType x);
	DateType Delete(int i);
	void PrintList();
private:
	DateType date[100];
	int length;
};

//下溢-1  上溢0 位置不正确1
template<class DateType>
DateType SeqList<DateType>::Get(int i)
{
	if(length == 1)throw 1;
	if(i < 1 || i > length) throw 1;
	else
		return date[i];
}

template<class DateType>
int SeqList<DateType>::Locate(DateType x)
{
	if(length == 1)return 0;
	for(int i = 1; i < length; i++)
		if(date[i] == x)
			return i;
	return 0;
}

template<class DateType>
void SeqList<DateType>::Insert(int i,DateType x)
{
	if(length > 21) throw 0;
	if(i < 1 || i > length) throw 1;
	for(int j = length; j > i; j--)
		date[j] = date[j-1];
	date[i] = x;
	length++;
}

template<class DateType>
DateType SeqList<DateType>::Delete(int i)
{
	if(length < 2)throw -1;
	if(i < 1 || i > length) throw 1;
	int x = date[i];
	for(int j = i; j < length; j++)
		date[j] = date[j + 1];
	length--;
	return x;
}

template<class DateType>
void SeqList<DateType>::PrintList()
{
	for(int i = 1; i < length; i++)
		cout<<date[i]<<endl;
}

int main()
{
	char a; int n;
	SeqList<int> list;
	
	while(cin>>a)
	{
		if(a == 'I')
		{
			cin>>n;
			int x,y;
			for(int i = 0; i < n; i++)
			{
				try
				{
				cin>>x>>y;
				list.Insert(x,y);
				}catch(int e)
				{
					if(e == 0)
						cout<<"上溢"<<endl;
					if(e == 1)
					{
						cout<<"位置不正确"<<endl;
						i--;
					}
				}
			}
		}
		if(a == 'S')
		{
			int x;
			cin>>x;
			int i = list.Locate(x);
			if(i != 0)
				cout<<i<<endl;
			else
				cout<<"None"<<endl;
		}
		if(a == 'G')
		{
			int i;
			cin>>i;
			try
			{
				int x = list.Get(i);
				cout<<x<<endl;
			}catch(int e)
			{
				if(e == 1)
					cout<<"位置不正确"<<endl;
			}
		}
		if(a == 'D')
		{
			int i;
			cin>>i;
			try
			{
				int x = list.Delete(i);
				cout<<x<<endl;
			}catch(int e)
			{
				if(e == -1)
					cout<<"下溢"<<endl;
				if(e == 1)
					cout<<"位置不正确"<<endl;
			}
		}
		if(a == 'V')
		{
			list.PrintList();
		}
		if(a == 'E')
			break;
	}
	return 0;
}
