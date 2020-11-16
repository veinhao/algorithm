#include<iostream>

using namespace std;

void displaySolution(int *x,int n)
{
	cout<<"(";
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<") ";
}


void dfs(int a[],int n, int i)
{
	if(i>=n)
		displaySolution(a,n);
	else
		for(int j=i;j<n;j++)
		{
			swap(a[j],a[i]);
			dfs(a,n,i+1);
			swap(a[j],a[i]);
		}	
}
int main()
{
	int a[]={1,2,3}; 
	int n=sizeof(a)/sizeof(a[0]);
	int x[]={0,0,0}; 
	dfs(a,n,0);
	return 0;
}

