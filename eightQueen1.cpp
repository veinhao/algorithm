#include<iostream>

using namespace std;

int map[10];
int count=0;
void print(int n)
{
	cout<<"第"<<++count<<"个棋盘："<<endl; 
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(map[i]==j)
				cout<<map[i]<<"  ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
}

bool placeRight(int i)//第i行的第MAP[I]列是否能放棋子 
{
	if(i==1)
		return true;
	for(int j=1;j<i;j++)
	{
		if(map[i]==map[j] || abs(i-j)==abs(map[i]-map[j]))
			return false;
	}
	return true;
}

void queen(int size)
{
	int i=1;//从第一行第一列开始
	map[i]=0;
	while(i>=1)
	{
		++map[i];
		//cout<<i<<" "<<map[i]<<" ";
		while(map[i]<=size && !placeRight(i))//行判断
		{
			++map[i];
		}
		//cout<<map[i]<<endl;
		if(map[i]<=size)//行判断 位置符合 
		{
			if(i==size)
			{
				print(i);
			}
			else
			{
				++i;
				map[i]=0; 
			}
		}
		else//行未搜索到 
		{
			--i;
		}

	}
}


int main()
{
	queen(6);
 } 
