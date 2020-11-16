#include<iostream>

using namespace std;
#define INF 999999;
void solve(int a[],int low,int high,int &max1,int &max2)
{
	int lmax1,lmax2,rmax1,rmax2;
	int mid=(low+high)/2;
	if(low==high)//数组只有一个元素 
	{
		max1=a[low];
		max2=-INF;
		return;
	 } 
	 else if(high==1+low)//数组有两个元素 
	 {
	 	max1=a[low]>a[high]?a[low]:a[high];
	 	max2=a[low]<a[high]?a[low]:a[high];
	 }
	 else if(high>low)//数组多个元素 
	 {
	 	solve(a,low,mid,lmax1,lmax2);
	 	solve(a,mid+1,high,rmax1,rmax2);
	 	if(lmax1>rmax1)
	 	{
	 		max1=lmax1;
	 		if(rmax1>lmax2) max2=rmax1;
	 		else max2=lmax2;
		 }else if(lmax1<rmax1){
		 	max1=rmax1;
		 	if(lmax1>rmax2) max2=lmax1;
		 	else max2=rmax2;
		 }
	 }
	 else return;
}

int main()
{
	int test[6]={2,5,1,4,6,3};
	int n=sizeof(test)/sizeof(test[0]);
	int max1,max2;
	solve(test,0,5,max1,max2);
	cout<<"max1:"<<max1<<" max2:"<<max2<<endl; 
 } 
