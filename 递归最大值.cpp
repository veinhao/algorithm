#include<iostream>

using namespace std;
/*
2020.09.17 
求数组里的最大值用递归的方法 
*/
int fMax(int a[],int start,int end)
{
	int mid=(start+end)/2;
	if(start==end) return a[mid];
	int lMax,rMax;
	lMax=fMax(a,start,mid);
	rMax=fMax(a,mid+1,end);
	return lMax>rMax?lMax:rMax; 
 } 
 
 int main()
 {
 	int a[]={1,12,3,4,5};
 	int result=fMax(a,0,4);
 	cout<<"result:"<<result<<endl;
  } 
