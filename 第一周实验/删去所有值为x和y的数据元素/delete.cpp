#include<iostream>

using namespace std;

void dele(int * a, int x, int y, int n);

int main()
{
	int n = 0, m = 0, x = 0, y = 0, j = 0;
	cin>>n;
	int * arry = new int[n];
	if(n >= 0)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>m;
			arry[j] = m;
			j++;
		}
		
		cin>>x>>y;
		dele(arry,x,y,n);
		for(int k = 0; arry[k]!='\0';k++)
			cout<<arry[k]<<" ";
	}
	return 0;
}

//时间复杂度O(n) 空间复杂度O(1)
void dele(int * a, int x, int y, int n)
{
	int m= 0;
	for(int i = 0; (a[i] != x) && (a[i] !=y); i++ );
	for(m = 1;i < n; i++)
	{
		if((a[i+m] != x) && (a[i+m] !=y))
			a[i] = a[i+m];
		else{
			m++;i--;}
	}
	for(int j = n-m; j < n; j++)
		a[j] = '\0';
}
