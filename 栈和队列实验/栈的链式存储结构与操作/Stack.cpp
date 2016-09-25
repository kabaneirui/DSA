//��ʽ
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
		if(a == 'E')	//����
			break;
		if(a == 'D')	//����
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
		if(a == 'P')	//��ջ
		{
			char b;
			cin>>b;
			try{
				stack.push(b);
			}catch(int )
			{
			}
		}
		if(a == 'Y')	//�Ƿ��
		{
			if( stack.is_empty() )
				cout<<"Yes"<<endl;
			if( !stack.is_empty() )
				cout<<"No"<<endl;
		}
		if(a == 'G')	//ջ��
		{
			if( stack.get_top() == NULL )
				cout<<"None"<<endl;
			else
				cout<<stack.get_top()<<endl;
		}
		if(a == 'T')	//���
		{
			stack.Delete();
		}
	}
	return 0;
}

