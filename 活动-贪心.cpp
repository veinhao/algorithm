#include<iostream>
#include<algorithm> 
#define MAX 10
using namespace std;

struct cow{
	int num;
	int begin;
	int end;
	bool operator<(const cow &c) const
	{
		if(end==c.end)
			return begin<=c.begin;
		return end<=c.end;
	} 
}; 

cow c1[]={{0},{1,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,8},{6,5,7},{7,6,10},
			{8,8,11},{9,8,12},{10,2,13},{11,12,15}};
int n=sizeof(c1)/sizeof(c1[0]);
bool ans[MAX];
int count;
void solve(){
	sort(c1+1,c1+n);
	int num=1,j,preEnd;
	for(int i=1;i<n;i++){
		if(c1[i].begin>=preEnd){
			ans[i]=true;
			preEnd=c1[i].end; 
			::count++;
		}
	}
}

void show()
{
	for(int i=1;i<n;i++)
	{
		cout<<c1[i].num<<" "<<c1[i].begin<<" "<<ans[i]<<endl;
	}
}

int main()
{
	solve();
	show();
	return 0;
}
