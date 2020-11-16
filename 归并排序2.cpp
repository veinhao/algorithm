#include<iostream>

using namespace std;



void merge(int* arr,int start,int mid ,int end)
{
	int *c=new int[end-start+1];
	for(int i=start;i<end+1;i++)
	{
		c[i]=arr[i];
	}
	
	int j=start,k=mid+1;	
	for(int i=start;i<=end;i++)
	{
		if(j>mid) arr[i]=c[k++];
		else if(k>end) arr[i]=c[j++];
		else if(c[j]>c[k]) arr[i]=c[k++];
		else arr[i]=c[j++];
	}
	
	delete c;
}

void mergeSort(int *box,int start,int end)
{
	if(start<end)//s
	{
		int mid=start+(end-start)/2;
		mergeSort(box,start,mid);	
		mergeSort(box,mid+1,end);
		merge(box,start,mid,end);
	}
}



void show(int* box, int len)
{
	for(int i=0;i<len;i++)
		cout<<box[i]<<" "; 
}
int main()
{
	int test[5]={4,3,2,1,5};
	mergeSort(test,0,4);
	show(test,5);
 } 
