#include<iostream>

using namespace std;
/*第一个节点有信息*/
struct Node{
	int data;
	Node* next;
	Node(int d)
	{
		data=d;
		next=NULL;
	}
}; 

typedef Node linkList;
//尾加 
void create(linkList* &head){
	int x;
	Node* s,*p;
	s=head;
	cout<<"please input: ";
	cin>>x;//
	if(x==-1) return;
	//cout<<endl;
	while(x!=-1)
	{
		p=new Node(x);
		s->next=p;
		s=s->next;
		cout<<"please input: "; 
		cin>>x;
	}
	
}

void destroy(linkList* &head)
{
	if(head!=NULL)
	{
		destroy(head->next);
		free(head);
		head=NULL;
	}
}

void display(linkList* head)
{
	if(head==nullptr)
	{
		cout<<"NULL LINKLIST"<<endl;
		return;
	}
	Node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"-->";
		p=p->next;
	}
	if(p==nullptr)
		cout<<"NULL"<<endl;
 } 
 
// void show(linkList* &head )
// {
 //	display(head);
// 	cout<<endl;
// }
int main()
{
	linkList* s=new Node(0);
	create(s);
	cout<<"--------------------------当前链表--------------------------:"<<endl;
	display(s);
	destroy(s);
	cout<<"--------------------------递归销毁后的链表--------------------------:"<<endl;
	display(s);
}
