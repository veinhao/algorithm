#include<iostream>
#define MAX 10 
using namespace std;

int n;
int	c1=50,c2=50; 
int op[MAX]={0};
int maxW=0;//���Ž�������� 
int W=10;//������ 
int w[]={0,5,2,6,4,3};//����1-5 
int x[MAX];//���Žⷽ�� 
int n=sizeof(w)/sizeof(w[0])-1;
int minNum=MAX;//��С���������ﵽ�������� 

void dfs(int tw,int rw,int op[],int i)
{
	//cout<<op[i]<<" ";
	if(i>=n)
	{
		if(tw<=c1&&tw>maxW)
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
		
		if(tw+w[i]<=c1)//���֦,�����ǰ��������װ�ص�֮��С����������� 
		{
			cout<<op[i]<<" ";
			op[i]=1;
			tw+=w[i];
			num+=1;
			rw-=w[i];
			dfs(tw,rw,op,i+1);
		}
		
		if(tw+rw-w[i]>maxW)//�Ҽ�֦ 
		{
			op[i]=0;
			dfs(tw,rw-w[i],op,i+1);
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
	
	int rw=0,tw=0;//ʣ�������� 
	for(int j=1;j<=n;j++)
	{
		rw+=w[j];
	}
	dfs(0,tw,rw,op,0);
	show();
	return 0;
}
