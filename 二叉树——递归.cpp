#include<iostream>

using namespace std;

struct BiNode{
	int data;
	BiNode *Lchild;
	BiNode *Rchild;
};

typedef struct BiNode BtTree;

void showMid(BtTree *cur)
{
	if(cur!=NULL)
	{
		showMid(cur->Lchild);
		cout<<cur->data<<" ";
		showMid(cur->Rchild);
	}
}

int Mid_add(BtTree *cur)
{
	if(cur==NULL)
		return 0;
	else{
		return Mid_add(cur->Lchild)+Mid_add(cur->Rchild)+cur->data;
	}	
}

int main()
{
	BtTree a,b,c,d,e,f,g;
	a.Lchild=&b;
	a.Rchild=&c;
	b.Lchild=&d;
	b.Rchild=&e;
	c.Lchild=&f;
	c.Rchild=&g;
	d.Lchild=NULL;
	d.Rchild=NULL;
	e.Lchild=NULL;
	e.Rchild=NULL;
	f.Lchild=NULL;
	f.Rchild=NULL;
	g.Lchild=NULL;
	g.Rchild=NULL;
	
	a.data=1;
	b.data=2;
	c.data=3;
	d.data=4;
	e.data=5;
	f.data=6;
	g.data=7;	
	
	showMid(&a);
	cout<<endl;
	cout<<"the result of binary tree is "<<Mid_add(&a);

 } 




