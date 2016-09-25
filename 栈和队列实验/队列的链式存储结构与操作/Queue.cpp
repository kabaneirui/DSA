#include <iostream>
#include <list>

using namespace std;

template <class DataType>
class Queue
{
public:
	Queue(){}

	void push(DataType x);
	DataType pop();
	DataType get_top() const;
	void clear();
	bool empty() const;
	
private:
	list<DataType> date;
};

template <class DataType>
void Queue<DataType>::push(DataType x)
{
	date.push_back(x);
}

template <class DataType>
DataType Queue<DataType>::pop()
{
	if(date.empty()) throw -1;
	DataType x = date.front();
	date.pop_front();
	return x;
}

template <class DataType>
DataType Queue<DataType>::get_top() const
{
	if(date.empty()) throw -1;
	return date.front();
}

template <class DataType>
void Queue<DataType>::clear()
{
	date.clear();
}

template <class DataType>
bool Queue<DataType>::empty() const
{
	return date.empty();
}

int main()
{
	Queue<char> queue;
	char a;
	while(cin >> a)
	{
		if(a == 'Q')
			break;
		if(a == 'E')
		{
			char b; cin >> b;
			queue.push(b);
		}
		if(a == 'C')
		{
			queue.clear();
		}
		if(a == 'G')
		{
			try
			{
				cout<<queue.get_top()<<endl;
			}
			catch(int e)
			{
				if(e == -1)
					cout<<"None"<<endl;
			}
		}
		if(a == 'D')
		{
			try
			{
				cout<<queue.pop()<<endl;
			}
			catch(int e)
			{
				if(e == -1)
					cout<<"None"<<endl;
			}
		}
	}
	return 0;
}
