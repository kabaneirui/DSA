#include<iostream>

using namespace std;
void insert(int * a, int x,int y,int n);
int main()
{
	cout<<"输入个数n"<<endl;
	int n;
	cin>>n;

	if(n>0)
	{
		int *a = new int[n+2];
		cout<<"按从小到大顺序输入数组"<<endl;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		int x,y;
		cout<<"输入插入的两个数字"<<endl;
		cin>>x>>y;
		insert(a,x,y,n);
	}
	return 0;
}


void insert(int * a, int x,int y,int n)
{
	int max = 0,min = 0;
	if(x > y){max = x;	min = y;}
	else{max = y;	min = x;}
		
	for(int i = n-1; a[i] > max; i--)
		a[i+2] = a[i];
	a[i+2] = max;
	max = min;
	for(; a[i] > max; i--)
		a[i+1] = a[i];
	a[i+1] = max;

	for(int j = 0; j < n+2; j++)
	{
		cout<<a[j]<<" ";
	}

}