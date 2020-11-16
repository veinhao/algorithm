#include<iostream>

using namespace std;

int maxSum1(int a[],int n)
{
	int i,j,k;
	int thisSum=0,maxSum=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			thisSum=0;
			for(k=i;k<=j;k++)
			{
				thisSum+=a[k];
				if(thisSum>maxSum)
				maxSum=thisSum;
			}
	
		}
	}
	return maxSum;
}

int maxSum2(int a[],int n)
{
	int i,j,k;
	int maxSum=0,thisSum=0;
	for(i=0;i<n;i++)
	{
		thisSum+=a[i];
		if(thisSum<0)
		{
			thisSum=0;
		}
		if(maxSum<thisSum)
		{
			maxSum=thisSum;
		}
	}
	return maxSum;
}

int main()
{
	int test[9]={-1,-2,3,-6,-8,-1,1,9,-7};
	int res=maxSum1(test,9);
	cout<<"max:"<<res<<endl;
 } 
 
