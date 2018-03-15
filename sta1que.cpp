#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	node *next;
};

class queue
{
	public:
		node *f;
		node *r;
		queue()
		{
			f=NULL;
			r=NULL;
		}
		int isempty();
		void enque(int);
		int deque();
};

int queue::isempty()
{
	if(f==NULL && r==NULL)
		return 1;
	else
		return 0;
}

void queue::enque(int val)
{
	node *temp=new node;
	temp->next='\0';
	temp->data=val;
	if(f=='\0' || r=='\0')
	{
		f=temp;
		r=temp;
	}
	else
	{
		r->next=temp;
		r=temp;
	}
	r->next=f;
}

int queue::deque()
{
	if(!isempty())
	{
		node *t=f;
		int res=t->data;
		if(f!=r)
		{
			f=f->next;
			delete t;
			r->next=f;
		}
		else
		{
			f='\0';
			r='\0';
		}
		return res;
	}
}

class stack
{
	public:
		queue q;
		void push(int);
		void pop();
		void display();
};

void stack::push(int val)
{
	q.enque(val);
	node *i=q.f;
	node *p=q.r;
	while(i!=p)
	{
			i=i->next;
			int y=q.deque();
			q.enque(y);
	}
}

void stack::pop()
{
	int y;
	if(q.f!='\0')
	{
		y=q.deque();
		cout<<y<<" deleted successfully...";
		getch();
	}
}

void stack::display()
{
	if(!q.isempty())
	{
		node *t=q.f;
		while(t->next!=q.f)
		{
			cout<<t->data<<'\t';
			t=t->next;
		}
		cout<<t->data;
	}
	else
		cout<<"\nStack is empty...";
	getch();
}

int main()
{
	stack obj;
	int a,z;
	do
	{
		system("cls");
		cout<<"\nThe menu is:"
			<<"\n1.Insert element in stack"
			<<"\n2.Delete element from stack"
			<<"\n3.Display the stack"
			<<"\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>a;
		switch(a)
		{
			case 1:cout<<"\nEnter the element to be inserted:";
					cin>>z;
					obj.push(z);
					break;
			case 2:obj.pop();
					break;
			case 3:obj.display();
					break;
			case 4:exit(0);
			default:cout<<"\nWrong choice is entered...";
					getch();
					break;
		}
	}while(a!=4);
	getch();
	return 0;
}
