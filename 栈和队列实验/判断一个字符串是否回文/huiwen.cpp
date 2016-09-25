#include <iostream>
#include <stack>
#include <list>

using namespace std;

bool judge(char a[])
{
	stack<char , list<char> > stack;
	int i = 0;
	while(a[i] != '\0')
	{
		stack.push(a[i]);
		i++;
	}
	i = 0;
	while(a[i] != '\0')
	{
		char b = stack.top();
		stack.pop();
		if(a[i] != b)
			break;
		i++;
	}
	if(a[i] == '\0')
		return true;
	return false;
}

int main()
{
	char a[50];
	cin>>a;
	bool b = judge(a);
	if(b == true)
		cout<<"yes"<<endl;
	if(b == false)
		cout<<"no"<<endl;
	return 0;
}