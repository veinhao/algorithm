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

cow c1[]={{0},{1,1,4},{2,2,5},{3,5,7},{4,8,9},{5,4,10}};
int n=sizeof(c1)/sizeof(c1[0]);
int ans[MAX];
void solve(){
	sort(c1+1,c1+n);
	int num=1,preEnd;
	for(int i=1;i<=n;i++){
		if(ans[i]==0){
			ans[i]=num;
			preEnd=c1[i].end;
			for(int j=i+1;j<=n;j++)
			{
				if(ans[j]==0&&c1[j].begin>preEnd)
				{
					ans[j]=num;
					preEnd=c1[j].end;
				}
			}
			num++;
		}
	}
}

void show()
{
	for(int i=1;i<n;i++)
	{
		cout<<c1[i].num<<" "<<ans[i]<<endl;
	}
}

int main()
{
	solve();
	show();
	return 0;
}
