#include<iostream>
//À„∑®∏¥‘”∂»£∫log 2 n 
using namespace std;

int halfate(int a[],int low,int high,int k)
{
	if(low==high&&k!=a[low]) return -1;
	int mid=(low+high)/2;
	if(low==high&&k==a[low]) return low;
	if(k==a[mid])
		return mid;
	else if(k<a[mid])
	{
		halfate(a,low,mid,k);
	}
	else if(k>a[mid])
	{
		halfate(a,mid+1,high,k);
	}
	

	
	
}
int main()
{
	int test[10]={1,4,6,7,9,12,14,15,16,100};
	int result=halfate(test,0,9,12);
	cout<<result<<endl;
 } 
