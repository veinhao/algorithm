#include<iostream>
#include<vector>
//��1-n�������Ӽ� 
//typedef Vector<Vector<int>> vec;
using namespace std;
typedef vector<vector<int> > vec;
vector<vector<int> > ps;

void pSet(int n)
{
	vector<vector<int>> ps1;
	vector<int> s;
	vector<vector<int>>::iterator it;
	ps.push_back(s);
	for (int i = 1; i <= n; i++)
	{
		//��PS1��ʼ��PS
		ps1 = ps;
		//ɨ��PS1�е�Ԫ�أ�������i
		for (it = ps1.begin(); it != ps1.end(); it++)
		{
			it->push_back(i);
		}
		for (it = ps1.begin(); it != ps1.end(); it++)
		{
			ps.push_back(*it);
		}
		//��PS1�е�����Ԫ�غϲ���PS��

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
	int n = 3;
	pSet(3);
	show();
	return 0;
}
