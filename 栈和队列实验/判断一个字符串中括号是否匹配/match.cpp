#include <iostream>
#include <stack>
#include <list>

using namespace std;

bool match(char * a);

int main()
{
	char a[100] = { '\0' };
	cin>>a;
	bool b = match(a);
	if(b == false)
		cout<<"no";
	if(b == true)
		cout<<"yes";
	return 0;
}

bool match(char * a)
{
	stack<char , list<char> > stack;
	int i = 0;
	while(a[i] != '\0')
	{
		if( a[i] == '{' || a[i] == '(' || a[i] == '[' )
			stack.push(a[i]);
		if(a[i] == '}')
		{
			if(stack.top() != '{')
				return false;
			stack.pop();
		}
		if(a[i] == ')')
		{
			if(stack.top() != '(')
				return false;
			stack.pop();
		}
		if(a[i] == ']')
		{
			if(stack.top() != '[')
				return false;
			stack.pop();
		}
		i++;
	}

	return true;
}