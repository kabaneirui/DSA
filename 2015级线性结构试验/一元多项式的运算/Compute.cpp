#include<iostream>

using namespace std;

template <class Datetype>
struct Node
{
	Datetype coef;		//系数
	Datetype exp;		//指数
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
	void Insert(Datetype y,Datetype x);
	Datetype Delete(int i);
	void PrintList();

	friend LinkList<LinkList> & operator+ (LinkList<LinkList> & a1,LinkList<LinkList> &a2);

	Node<Datetype> * first;
};

//构造
template <class Datetype>
LinkList<Datetype>::LinkList()
{
	first = new Node<Datetype>;
	first->next = NULL;
}


//插入
template <class Datetype>
void LinkList<Datetype>::Insert(Datetype y,Datetype x)
{
	Node<Datetype> * p = new Node<Datetype>;
	p->coef = y; p->exp = x;
	if(first->next == NULL)
	{
		first->next = p; p->next = NULL;
	}
	else{
		Node<Datetype> * q = first, * temp;
		while(q->exp < x && q != NULL)
		{
			temp = q;
			if(q->next == NULL)
				break;
			q = q->next;
		}
		if(q->next == NULL && q->exp < x)
		{
			p->next = NULL;
			q->next = p;
		}else
		{
		p->next = temp->next;
		temp->next = p;
		}
	}
}

//打印
template <class Datetype>
void LinkList<Datetype>::PrintList()
{
	Node<Datetype> * p = first->next;
	while(p != NULL)
	{
		cout<<p->coef<<" "<<p->exp<<endl;
		p = p->next;
	}
}

template <class Datetype>
LinkList<Datetype> & operator+ (LinkList<Datetype> & a1,LinkList<Datetype> &a2)
{
	LinkList<Datetype> *temp = new LinkList<Datetype>;

	Node<Datetype> * b1 = a1.first->next; Node<Datetype> * b2 = a2.first->next;
	while(b1 != NULL || b2 != NULL)
	{
		if((b1 == NULL && b2 != NULL) || ( (b1 != NULL && b2 != NULL) && (b1->exp > b2->exp) ) )
		{
			temp->Insert(b2->coef,b2->exp);
			b2 = b2->next;
		}
		if((b2 == NULL && b1 != NULL) || ( (b1 != NULL && b2 != NULL)&&(b1->exp < b2->exp) ) )
		{
			temp->Insert(b1->coef,b1->exp);
			b1 = b1->next;
		}
		if((b1 != NULL && b2 != NULL) && b1->exp == b2->exp )
		{
			int c = b1->coef+b2->coef;
			if(c != 0)
				temp->Insert(c,b2->exp);
			b1 = b1->next; b2 = b2->next; 
		}
	}
	return *temp;
}

//测试
int main()
{	
	char a;
	LinkList<int>* list1 = new LinkList<int>;
	LinkList<int>* list2 = new LinkList<int>;
	while(cin>>a)
	{
		if(a == 'E')
			break;
		if(a == 'A')
		{
			int m, n;
			while(cin>>m>>n)
			{
				if(m == 0)
					break;
				list1->Insert(m,n);
			}
		}
		if(a == 'B')
		{
			int m,n;
			while(cin>>m>>n)
			{
				if(m == 0)
					break;
				list2->Insert(m,n);
			}
		}
		if(a == 'C')
		{
			LinkList<int> temp = *list1 + *list2;
			temp.PrintList();
		}
	}

	return 0;
}