//链式
#include <iostream>
#include <list>
using namespace std;

template <class DataType>
class Stack
{
public:
	Stack();

	void push(DataType x);
	DataType pop();
	DataType get_top()const;
	bool is_empty()const;
	void Delete();
private:
	list<DataType> date;
};

template <class DataType>
Stack<DataType>::Stack()
{
}

template <class DataType>
void Stack<DataType>::push(DataType x)
{
	date.push_back(x);
}

template <class DataType>
DataType Stack<DataType>::pop()
{
	if(date.empty()) throw -1;
	DataType x = date.back();
	date.pop_back();
	return x;
}

template <class DataType>
DataType Stack<DataType>::get_top ()const
{
	if(date.empty()) 
		return NULL;
	return date.back();
}

template <class DataType>
void Stack<DataType>::Delete()
{
	date.clear();
}

template <class DataType>
bool Stack<DataType>::is_empty ()const
{
	return date.empty();
}

int main()
{
	Stack<char> stack;
	char a;
	while(cin>>a)
	{
		if(a == 'E')	//结束
			break;
		if(a == 'D')	//弹出
		{
			try
			{
				cout<<stack.pop()<<endl;
			}catch(int e)
			{
				if(e == -1)
					cout<<"None"<<endl;
			}
		}
		if(a == 'P')	//入栈
		{
			char b;
			cin>>b;
			try{
				stack.push(b);
			}catch(int )
			{
			}
		}
		if(a == 'Y')	//是否空
		{
			if( stack.is_empty() )
				cout<<"Yes"<<endl;
			if( !stack.is_empty() )
				cout<<"No"<<endl;
		}
		if(a == 'G')	//栈顶
		{
			if( stack.get_top() == NULL )
				cout<<"None"<<endl;
			else
				cout<<stack.get_top()<<endl;
		}
		if(a == 'T')	//清空
		{
			stack.Delete();
		}
	}
	return 0;
}

