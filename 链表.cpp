#include<iostream>

using namespace std;

struct linkNode{
	int data;
	linkNode* next;
};
class linkList{
	public: linkNode* head;
	private: int place;//当前最后一个节点的下标
	//reversePrint方法的全局变量 
	
	public:linkList()
		{
			head=new linkNode;
			head->next=NULL;
			place=-1; 
		}
		//尾连接
		void linkToTail(int newData)
		{
			//linkNode* cur=this->head->next,*preCur=head;
			linkNode* cur=this->head;
			while(cur->next!=NULL)
			{	
				cur=cur->next;
			}
			cur->next=new linkNode;
			cur->next->data=newData;
			cur->next->next=NULL;
			++place; 
		 } 
		 //删除第N个位置 
		 linkNode* deleteN(int n)
		 {
		 	if(n-1>place||n<=0) return NULL;
		 	linkNode* cur=head->next,*preCur=head;
		 	int i=0;
		 	while(i!=n-1)
		 	{
		 		preCur=cur;
		 		cur=cur->next;
		 		++i;
			 }
			 linkNode* backNode=new linkNode;
			 backNode->data=cur->data;
			 preCur->next=cur->next;
			 --place;
			 return backNode;
		 }
		 
		 //打印链表 
		 public:void print()
		 {
		 	linkNode* cur=head;
		 	while(cur->next!=NULL)
		 	{
		 		cur=cur->next;
		 		cout<<cur->data<<"-->";	
			 }
			 cout<<"NULL"<<endl;
		 }
		 //反向打印 
		 public:void reversePrint(linkNode* cur)
		 {
		 	if(cur!=NULL)
			 {
			 	reversePrint(cur->next);
			 	cout<<cur->data<<"<--";
			 }
			 else
			 	return;
		 }
		 
		 public:int sum(linkNode *cur)
		 {
		 	if(cur!=NULL)
		 	{
		 		return sum(cur->next)+cur->data;	
			 }
			 else
			 	return 0;
		  } 
};

int main()
{
	linkList test;
	test.linkToTail(2);
	test.linkToTail(3);
	test.linkToTail(4);
	test.linkToTail(5);
	test.linkToTail(6);
	test.print();
	//删除 
	test.deleteN(2);
	//int deleteResult=test.deleteN(2)->data;
	//cout<<"删除的数据是："<<deleteResult<<end;
	test.print();
	//反向打印/递归 
	linkNode cur;
	test.reversePrint(test.head->next);
	cout<<endl;
	//求和//递归 
	cout<<"求和结果是"<<test.sum(test.head->next);
	return 0;
}
