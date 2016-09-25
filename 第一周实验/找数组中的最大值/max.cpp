#include<iostream>

using namespace std;

void max(int * a, int n);

int main()
{
	int n = 0;
	cin>>n;
	if(n >= 0)
	{
		int * a = new int [n];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		max(a,n);
	}
	return 0;
}

//时间复杂度O(n),空间复杂度O(1)
void max(int * a, int n)
{
	int max = a[0];
	int index = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
			index = i;
		}
	}
	cout<<index<<" "<<max;
}