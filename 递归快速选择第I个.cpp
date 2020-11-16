#include<iostream>

using namespace std;

int quickSelect(int a[],int s,int t,int k)
{
	if(s<t)
	{
		int tmp=a[s],i=s,j=t;
		while(i<j)
		{
			
				while(j>i&&tmp<a[j])
				{
					--j; 
				}
				a[i]=a[j];
				while(j>i&&tmp>a[i])
				{
					++i;
				}
				a[j]=a[i];
			 
			
		}
		a[i]=tmp;
		
		if(i==k-1) return a[i];
		else if(k-1<i) return quickSelect(a,s,i-1,3);
		else return quickSelect(a,i+1,t,3);
	}else if(s==t&&s==k-1)
		return a[k-1];
	
}

int main()
{
	int test[10]={1,4,6,7,9,12,14,15,16,100};
	int result=quickSelect(test,0,9,10);
	cout<<result<<endl;
}
