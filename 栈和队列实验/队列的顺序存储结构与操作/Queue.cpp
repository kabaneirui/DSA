#include <iostream>

using namespace std;

template <class DataType>
class Queue
{
public:
	Queue();

	void push(DataType x);
	void Delete();
	DataType get_top();
	DataType pop();
	bool empty();
private:
	int top,tail;
	DataType date[100];
};

template <class DataType>
Queue<DataType>::Queue()
{
	top = 0;
	tail = 0;
}

template <class DataType>
void Queue<DataType>::push(DataType x)
{
	if( (tail + 1) % 100 == top) throw 1;
	tail = (tail + 1) % 100;
	date[tail] = x;
}

template <class DataType>
void Queue<DataType>::Delete()
{
	top = 0;
	tail = 0;
}

template <class DataType>
DataType Queue<DataType>::get_top()
{
	if( tail == top) throw -1;
	return date[ (top+1) % 100 ];
}

template <class DataType>
DataType Queue<DataType>::pop()
{
	if(tail == top) throw -1;
	top = (top + 1) % 100;
	return date[top];
}

template <class DataType>
bool Queue<DataType>::empty()
{
	return top == tail;
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
			try
			{
				queue.push(b);
			}
			catch(int e)
			{
				if(e == 1)
					cout<<"Queue Full"<<endl;
			}
		}
		if(a == 'C')
		{
			queue.Delete();
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