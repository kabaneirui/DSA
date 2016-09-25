#include <iostream>
using namespace std;

template <class DataType>
class Stack
{
public:
	Stack();

	void push(DataType x);
	DataType pop();
	DataType get_top();
	bool is_empty();
	void Delete();
private:
	int top;
	DataType date[13];
};
//1���� -1����
template <class DataType>
Stack<DataType>::Stack()
{
	top = -1;
}

template <class DataType>
void Stack<DataType>::push(DataType x)
{
	if(top >= 9) throw 1;
	date[++top] = x;
}

template <class DataType>
DataType Stack<DataType>::pop()
{
	if(top == -1) throw -1;
	DataType x = date[top];
	top--;
	return x;
}

template <class DataType>
DataType Stack<DataType>::get_top()
{
	if(top == -1) 
		return NULL;
	return date[top];
}

template <class DataType>
void Stack<DataType>::Delete()
{
	top = -1;
}

template <class DataType>
bool Stack<DataType>::is_empty()
{
	if(top == -1)
		return true;
	return false;
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

