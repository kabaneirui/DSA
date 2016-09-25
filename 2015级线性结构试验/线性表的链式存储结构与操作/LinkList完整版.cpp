#include<iostream>

using namespace std;

template <class Datetype>
struct Node
{
	Datetype date;
	Node * next;
};

template <class Datetype>
class LinkList
{
public:
	LinkList();
	//LinkList(Datetype a[], int n);
	~LinkList(){delete [] first;}
	int Length();
	Datetype Get(int i);
	int Locate(Datetype x);
	void Insert(int i,Datetype x);
	Datetype Delete(int i);
	void PrintList();
private:
	Node<Datetype> * first;
};

//构造
template <class Datetype>
LinkList<Datetype>::LinkList()
{
	first = new Node<Datetype>;
	first->next = NULL;
}

//通过位置获取元素
template <class Datetype>
Datetype LinkList<Datetype>::Get(int i)
{
	Node<Datetype> * p = first->next;
	int j = 1;
	while(j < i && p->next != NULL)
	{
		j++; p = p->next;
	}
	if(i < 1 || j < i) throw 0;		//位置不正确
	return p->date;
}

//通过元素获取位置
template <class Datetype>
int LinkList<Datetype>::Locate(Datetype x)
{
	Node<Datetype> * p = first->next;
	int i = 1;
	while(p->date != x && p->next != NULL){ i++; p = p->next;}
	if(p->next == NULL && p->date != x)
		return 0;
	else
		return i;
}

//长度
template <class Datetype>
int LinkList<Datetype>::Length()
{
	int i = 0;
	if(first->next == NULL)
		return 0;
	Node<Datetype> * p = first->next;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

//插入
template <class Datetype>
void LinkList<Datetype>::Insert(int i,Datetype x)
{
	int j = i;
	if(this->Length() >= 20) throw 1;	//上溢
	Node<Datetype> * p = first->next;
	Node<Datetype> * q = first->next;

	i = i-1;
	while(p != NULL && i--)  {	q = p;	p = p->next; }

	if( i > 0 || j < 1) throw 0;  //位置不正确

	Node<Datetype> * temp = new Node<Datetype>(); 
	temp->date = x; temp->next = NULL;
	if(first->next != NULL)
	{
		if(j == 1)
		{
			temp->next = first->next;
			first->next = temp;
		}
		else
		{
			temp->next = q->next;
			q->next = temp;	
		}
	}
	if(first->next == NULL)
	{
		first->next = temp;
	}
}

//删除
template <class Datetype>
Datetype LinkList<Datetype>::Delete(int i)
{
	int j = i;
	if(first->next == NULL ) throw -1;		//下溢
	Node<Datetype> * p = first->next, * q;
	Datetype temp;
	while(p != NULL && --i)
	{
		q = p;
		p = p->next;
	}
	if(j < 1 || i > 0) throw 0;
	if(j == 1)
	{
		temp = first->next->date;
		first->next = first->next->next;
		delete p;
	}else
	{
		temp = p->date;
		q->next = p->next;
		delete p;
	}
	return temp;
}

//打印
template <class Datetype>
void LinkList<Datetype>::PrintList()
{
	Node<Datetype> * p = first->next;
	while(p != NULL)
	{
		cout<<p->date<<endl;
		p = p->next;
	}
}

//测试
int main()
{
	LinkList<int> list ;
	char a;
	while(cin>>a)
	{
		if(a == 'E')
			break;
		if(a == 'I')	//插入
		{
			int n,i,x;
			cin>>n;	
			
			for(int j = 0;j < n; j++)
			{
				try
				{
					cin>>i>>x;
					list.Insert(i,x);
				}catch(int e)
				{
					if(e == 1)
						cout<<"上溢"<<endl;
					if(e == 0)
						cout<<"位置不正确"<<endl;
				}
			}
			
		}
		if(a == 'D')	//删除
		{
			int i,x;
			cin>>i;
			try
			{
				x = list.Delete(i);
				cout<<x<<endl;
			}
			catch(int e)
			{
				if(e == -1) cout<<"下溢"<<endl;
				if(e == 0) cout<<"位置不正确"<<endl;
			}	
		}
		if(a == 'S')	//通过元素获取位置
		{
			int i,x;
			cin>>x;
			i = list.Locate(x);
			if(i == 0) 
				cout<<"None"<<endl;
			if(i != 0)
				cout<<i<<endl;
		}
		if(a == 'G')	//通过位置获取元素
		{
			int i,x;
			cin>>i;
			try{
				x = list.Get(i);
				cout<<x<<endl;
			}
			catch(int e)
			{
				if(e == 0)
					cout<<"位置不正确"<<endl;
			}
		}
		if(a == 'V')	//打印
			list.PrintList();
		if(a == 'L')	//长度
			cout<<list.Length()<<endl;
	}

	return 0;
}