#include<iostream>
#define MAX 10 
using namespace std;

int maxW=0;//最优解的总重量 
int W=10;//总重量 
int w[]={0,5,2,6,4,3};//货物1-5 
int x[MAX];//最优解方案 
int n=sizeof(w)/sizeof(w[0])-1;
int minNum=MAX;//最小货物数量达到总重量的 

void dfs(int num,int tw,int rw,int op[],int i)
{
	//cout<<op[i]<<" ";
	if(i>=n)
	{
		if(tw==W&&num<minNum)
		{
			maxW=tw;//maxW
			minNum=num;//minNum
			for(int j=1;j<=n;j++)//OP->X
			{
				x[j]=op[j];
			}
		}
	}
	else
	{
		op[i]=1;
		if(tw+w[i]<=W)//左剪枝,如果当前重量和已装载的之和小于最大总重量 
		{
			//cout<<op[i]<<" ";
			//tw+=w[i];
			//num+=1;
			//rw-=w[i];
			//i+=1;
			dfs(num+1,tw+w[i],rw-w[i],op,i+1);
		}
		op[i]=0;
		if(tw+rw-w[i]>=W)//右剪枝如果没有当前这个货物重量结果可以满足大于总质量
		{
			dfs(num,tw,rw-w[i],op,i+1);
		}
	}
} 

void show()
{
	for(int j=1;j<=n;j++)
	{
		cout<<x[j]<<" ";
	}
}

int main()
{
	int op[MAX]={0};
	int rw=0,tw=0;//剩余总重量 
	for(int j=1;j<=n;j++)
	{
		rw+=w[j];
	}
	dfs(0,tw,rw,op,1);
	show();
	return 0;
}
