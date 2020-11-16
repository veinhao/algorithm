#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Stud
{
	int no;
	string name;
	Stud(int no1,int name1){
		no=no1;
		name=name1;
	}
	bool operator<(const Stud &s) const 
	{
		return s.no<no;
	}
};

struct cmp
{
	bool operator()(const Stud &s,const Stud &t) const
	{
		return s.name<t.name;
	}
};

void Disp(vector<Stud> &myv)
{
	vector<Stud>::iterator it;
	for(it=myv.begin();it!=myv.end();it++){
		
	}
}
