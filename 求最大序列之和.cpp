#include<iostream>

using namespace std;

int max3(int a,int b,int c)
{
	if(a>b && a>c) return a;
	else if(b>a && b>c) return b;
	else return c;
}

int maxSub(int *a,int left,int right)
{
	if(left==right)
	{
		if(a[left]>0) return a[left];
	}
	int i,j,mid;
	int leftSubSum,rightSubSum;
	mid=(left+right)/2;
	leftSubSum=maxSub(a,left,mid); 
	rightSubSum=maxSub(a,mid+1,right); 
	
	int leftBorderSum=0,rightBorderSum=0;
	int maxLeftBorder=0,maxRightBorder=0;
	for(int i=mid;i>=left;i--)
	{
		leftBorderSum+=a[i];
		if(leftBorderSum>maxLeftBorder) 
			maxLeftBorder=leftBorderSum;
	}
	for(int j=mid+1;j<=right;j++)
	{
		rightBorderSum+=a[j];
		if(rightBorderSum>maxRightBorder)
			maxRightBorder=rightBorderSum;
	}
	return max3(leftSubSum,rightSubSum,maxLeftBorder+maxRightBorder);
 } 
 
 int main()
 {
 	int test[9]={1,2,3,-1,5,6,0,8,9};
 	int result=maxSub(test,0,8);
 	cout<<result<<endl;
  } 
 
