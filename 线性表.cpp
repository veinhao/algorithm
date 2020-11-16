#include<iostream>

using namespace std;

int cur=0;
int cur1=0;

class linerList{
	int *list;
	int currentPlace;
	int size;
	
	public: linerList(int s)
	{
		size=s;
		list=new int[size];
		currentPlace=-1;//当前位置，从0开始 
	}
	//增加 
	public: void add(int num)
	{
		if(this->currentPlace<=size-1){
			this->list[++currentPlace]=num;
			
		}
	}
	
	public: int sumByDigui(){
		if(cur1!=currentPlace+1)
		{
			return this->list[cur1++]+sumByDigui();
		}
		else{
			return 0;
		}
	} 
	
	public: void deleteFromTail()
	{
		if(currentPlace>=0)
		{
			this->list[currentPlace]=0;
			--currentPlace;	
		}
		
	}
	
	//求和
	public: void sum()
	{
		int sum=0;
		for(int i=0;i<=currentPlace;i++)
		{
			sum+=this->list[i];
		}
		cout<<"线性表各个数的和是"<<sum<<endl;
	}
	//倒置输出 
	public: void reverseShow()
	{
		if(cur<=currentPlace)
		{
			++cur;
			reverseShow();
			cout<<this->list[--cur]<<" ";
		}
		
	 } 
	
	public: void show()
	{
		for(int i=0;i<=currentPlace;i++)
		{
			cout<<this->list[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	linerList test(4);
	//test.linerList(4);
	test.add(1);
	test.add(2);
	test.add(3);
	test.add(4);
	test.show();
	
	//cout<<"afer delete"<<endl;
	//test.deleteFromTail();
	//test.show();
	
	test.reverseShow();
	cout<<endl;
	cout<<test.sumByDigui();
 } 


