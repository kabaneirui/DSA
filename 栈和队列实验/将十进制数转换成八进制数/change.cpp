#include <iostream>
#include <stack>
#include <list>

using namespace std;

void change(int a,int n);

int main()
{
	int a[3];
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		cin>>a[i];
	}
	for(i = 0; i < 3; i++ )
	{
		change(a[i],8);
	}
	return 0;
}
//十进制转换n进制
void change(int a,int n)
{
	int b = 0;
	stack<int , list<int> > stack;
	if(a == 0)
		stack.push(0);
	while( a != 0 )
	{
		b = a % n;
		stack.push(b);
		a = a / n;
	}
	int i = 0;
	while(!stack.empty())
	{
		cout<<stack.top();
		stack.pop();
	}
	cout<<endl;
}