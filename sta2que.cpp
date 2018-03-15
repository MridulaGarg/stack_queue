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
		int flag;
		node *f;
		node *r;
		queue()
		{
			f=NULL;
			r=NULL;
			flag=0;
		}
		int isempty();
		void enque(int);
		int deque();
}q1,q2;

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
	flag=1;
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
		void push(int);
		void pop();
		void display();
};

void stack::push(int val)
{
	int x;
	if(q1.flag==0)
	{
		q1.enque(val);
		if(!q2.isempty())
		{
			while(!q2.isempty())
			{
				x=q2.deque();
				q1.enque(x);
			}
		}
		q1.flag=1;
		q2.flag=0;
	}
	else if(q2.flag==0)
	{
		q2.enque(val);
		if(!q1.isempty())
		{
			while(!q1.isempty())
			{
				x=q1.deque();
				q2.enque(x);
			}
		}
		q2.flag=1;
		q1.flag=0;
	}
}

void stack::pop()
{
	int x;
	if(q1.flag==0 && q2.flag==0)
		cout<<"\nStack is empty...";
	else
	{
		if(q1.flag==1)
		{
			x=q1.deque();
			if(q1.isempty())
				q1.flag=0;
		}
		else if(q2.flag==1)
		{
			x=q2.deque();
			if(q2.isempty())
				q2.flag=0;
		}
		cout<<"\n"<<x<<" deleted successfully...";
	}
	getch();
}

void stack::display()
{
	if(q1.flag==0 && q2.flag==0)
		cout<<"\nStack is empty...";
	else
	{
		node *p;
		if(q1.flag==1)
		{
			p=q1.f;
			while(p!=q1.r)
			{
				cout<<p->data<<'\t';
				p=p->next;
			}
		}
		else if(q2.flag==1)
		{
			p=q2.f;
			while(p!=q2.r)
			{
				cout<<p->data<<'\t';
				p=p->next;
			}
			cout<<p->data;
		}
	}
	getch();
}

int main()
{
	stack obj;
	int a,z;
	do
	{
		system("cls");
		cout<<"The menu is:"
			<<"\n1.Push element(s) in stack"
			<<"\n2.Pop element(s) fron stack"
			<<"\n3.Display the stack"
			<<"\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>a;
		switch(a)
		{
			case 1:cout<<"\nEnter the element to push in stack:";
					cin>>z;
					obj.push(z);
					cout<<"\nElement pushed successfully...";
					getch();
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
