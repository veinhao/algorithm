#include<iostream>

using namespace std;
/*
���ܣ�
���ƣ�ȫ���� 
������a �ݼ�Ԫ�� ,n  Ԫ�ظ���,i   ��ǰ���߲��� ,x  ������ 
*/
void displaySolution(int *a,int n,int *x)
{
	cout<
	cout<<"{";
	for(int i=0;i<n;i++)
	{
		if(x[i]==1)
			cout<<a[i];
		if(i<n-1 && x[i]!=0)
			cout<<" ";
	}
	cout<<"} ";
}

void dfs(int a[],int n,int i,int x[])
{
	if(i>=n)
	{
		//res.pushback(a[i]);
		displaySolution(a,n,x);
	}
	else
	{
		x[i]=0;
		dfs(a,n,i+1,x);
		x[i]=1;
		dfs(a,n,i+1,x);
	}
 } 
 
int main()
{
	int a[]={1,2,3}; 
	int n=sizeof(a)/sizeof(a[0]);
	int x[]={0,0,0}; 
	dfs(a,n,0,x);
	return 0;
}
