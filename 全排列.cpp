#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
typedef vector<vector<int> > vec;
vector<vector<int> > ps;

void insert(vector<int> s,int i,vec &ps1)
{
	vector<int>::iterator it;
	vector<int> s1;
	for(int j=0;j<i;j++)
	{
		s1=s;
		it=s1.begin()+j;
		s1.insert(it,i);
		ps1.push_back(s1);
	}
}

void perm(int n)
{
	vec ps1;
	vector<int> s;
	vec::iterator it;
	s.push_back(1);
	ps.push_back(s);
	for(int i=2;i<=n;i++)
	{
		ps1.clear();
		for(it=ps.begin();it!=ps.end();it++)
		{
			insert(*it,i,ps1);
		}
		ps=ps1;
	}	
}


void show()
{
	vec::iterator it;
	vector<int>::iterator it1;
	int i = 0;
	//cout << ps.size();
	for (it = ps.begin(); it != ps.end(); it++)
	{
		cout << "{";
		for (it1=(*it).begin();it1!=(*it).end();it1++)
		{
			cout << *it1 << " ";
		}
		cout << "}";
	}
	cout << endl;
}

int main()
{
	int n=3;
	printf("1-n的全排列如下：\n",n);
	perm(n);
	show();
}
