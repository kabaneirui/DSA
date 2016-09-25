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

//����
template <class Datetype>
LinkList<Datetype>::LinkList()
{
	first = new Node<Datetype>;
	first->next = NULL;
}

//ͨ��λ�û�ȡԪ��
template <class Datetype>
Datetype LinkList<Datetype>::Get(int i)
{
	Node<Datetype> * p = first->next;
	int j = 1;
	while(j < i && p->next != NULL)
	{
		j++; p = p->next;
	}
	if(i < 1 || j < i) throw 0;		//λ�ò���ȷ
	return p->date;
}

//ͨ��Ԫ�ػ�ȡλ��
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

//����
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

//����
template <class Datetype>
void LinkList<Datetype>::Insert(int i,Datetype x)
{
	int j = i;
	if(this->Length() >= 20) throw 1;	//����
	Node<Datetype> * p = first->next;
	Node<Datetype> * q = first->next;

	i = i-1;
	while(p != NULL && i--)  {	q = p;	p = p->next; }

	if( i > 0 || j < 1) throw 0;  //λ�ò���ȷ

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

//ɾ��
template <class Datetype>
Datetype LinkList<Datetype>::Delete(int i)
{
	int j = i;
	if(first->next == NULL ) throw -1;		//����
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

//��ӡ
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

//����
int main()
{
	LinkList<int> list ;
	char a;
	while(cin>>a)
	{
		if(a == 'E')
			break;
		if(a == 'I')	//����
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
						cout<<"����"<<endl;
					if(e == 0)
						cout<<"λ�ò���ȷ"<<endl;
				}
			}
			
		}
		if(a == 'D')	//ɾ��
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
				if(e == -1) cout<<"����"<<endl;
				if(e == 0) cout<<"λ�ò���ȷ"<<endl;
			}	
		}
		if(a == 'S')	//ͨ��Ԫ�ػ�ȡλ��
		{
			int i,x;
			cin>>x;
			i = list.Locate(x);
			if(i == 0) 
				cout<<"None"<<endl;
			if(i != 0)
				cout<<i<<endl;
		}
		if(a == 'G')	//ͨ��λ�û�ȡԪ��
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
					cout<<"λ�ò���ȷ"<<endl;
			}
		}
		if(a == 'V')	//��ӡ
			list.PrintList();
		if(a == 'L')	//����
			cout<<list.Length()<<endl;
	}

	return 0;
}