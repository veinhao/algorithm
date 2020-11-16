#include<iostream>

using namespace std;

int partition(int a[],int start,int end)
{
	int tmp=a[start];
	int i=start,j=end;
	while(i<j)
	{
		//scanf from right to left
		while(i<j&&tmp<a[j])
		{
			j--;
			
		}
		a[i]=a[j];
		//scanf from left to right	
		while(i<j&&tmp>a[i])
		{
			i++;
		}
		a[j]=a[i];
	}	
	a[i]=tmp;
	return i;
}

void quickSort(int a[],int start,int end)
{
	if(start<end){
		int i=partition(a,start,end); 
		quickSort(a,start,i-1);
		quickSort(a,i+1,end);
	}
}

void show(int* box, int len)
{
	for(int i=0;i<len;i++)
		cout<<box[i]<<" "; 
}

int main()
{
	int a[]={5,2,7,3,6,4,1};
	quickSort(a,0,6);
	show(a,7);
}
