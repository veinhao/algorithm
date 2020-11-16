#include<iostream>

using namespace std;

int n0=0; 
void hanoi(char x,char y,char z,int n)
{
	if(n==1)
		cout<<"第"<<++n0<<"步： "<<":"<<x<<"->"<<z<<endl;
	else{
		hanoi(x,z,y,n-1);
		cout<<"第"<<++n0<<"步： "<<":"<<x<<"->"<<z<<endl;
		hanoi(y,x,z,n-1);
	}
}
int main()
{
	hanoi('A','B','C',4);
}
