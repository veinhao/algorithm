#include<iostream>

using namespace std;
#define N 9

/*page 172*/ 

void fun(char *op,int sum,int pre,int *a,int i)
{
	if(i>=N)
	{
		if(sum==100)
		{
			cout<<a[0];
			for(int j=1;j<N;j++)
			{
				if(op[j]!=' ')
					cout<<op[j];
				cout<<a[j];
			}
			cout<<"=100"<<endl;
		}
	}
	else{
		//+
		op[i]='+';
		sum+=a[i];
		fun(op,sum,a[i],a,i+1);
		sum-=a[i];
		
		op[i]='-';
		sum-=a[i];
		fun(op,sum,-a[i],a,i+1);
		sum+=a[i];
		
		op[i]=' ';
		sum-=pre;
		int temp;
		if(pre>0)
			temp=a[i]+pre*10;
		else
			temp=pre*10-a[i];
		sum+=temp;
		fun(op,sum,temp,a,i+1);
		sum-=temp;
		sum+=pre;
	
	}
}

int main()
{
	int a[N];
	char op[N];
	for(int i=0;i<N;i++)
	{
		a[i]=i+1;
	}
	cout<<"½á¹ûÎª£º "<<endl;
	fun(op,a[0],a[0],a,1);
}
