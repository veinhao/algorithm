#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;


 
 int doubleNum(int *arr,int n)
 {
 	int count=0;
 	map<int,int> myM;
 	for(int i=0;i<n;i++)
 	{
 		if(arr[i]>0)
 		{
 			++myM[arr[i]];
		 }
		 else
		 {
		 	++myM[-arr[i]];
		 }
		 if(myM[arr[i]]!=1)
		 	++count;
	 }
	 return count;
 }

int main()
{
	int box[6]={4,5,9,-9,-5,-4};
	int result=doubleNum(box,6);
	cout<<"The result is "<<result<<endl;
	return 0;
}
