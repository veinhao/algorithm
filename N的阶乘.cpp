#include<iostream>

using namespace std;

int digui(int n)
{
	if (n==1||n==0)
		return 1;
	else
		return n*digui(n-1);
}

int feibo(int n)
{
	if(n==1||n==2)
		return 1; 
	else
		return feibo(n-2)+feibo(n-1);	
		
}

struct linkNode{
	int data;
	linkNode *next;
};

typedef struct linkNode LNode;

void showReverse(linkNode *head)
{
	if(head->next!=NULL)
		showReverse(head->next);
		cout<<head->data<<" "<<endl;
}

int sum(linkNode *head)
{
	if(head==NULL)
		return 0;
	else
		return head->data+sum(head->next);
}
int main()
{
	int result=digui(5);
	cout<<"The result is "<<result;
	cout<<"the result is "<<feibo(5)<<endl;	
	linkNode node1,node2,node3;
	node1.next=&node2;
	node2.data=23;
	node2.next=&node3;
	node3.data=32;
	node3.next=NULL;
	
	linkNode *head=&node1;
	while(head->next!=NULL)
	{
		head=head->next;
		cout<<head->data<<"-->";
	}
	cout<<"NULL"<<endl;
	linkNode *head1=node1.next;
	cout<<"the result is "<<sum(head1);
	//showReverse(head1);
	
	
 } 
 

