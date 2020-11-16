#include<iostream>

using namespace std;

int map[10];
int count=0;
void print(int n)
{
	cout<<"��"<<++count<<"�����̣�"<<endl; 
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

bool placeRight(int i)//��i�еĵ�MAP[I]���Ƿ��ܷ����� 
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
	int i=1;//�ӵ�һ�е�һ�п�ʼ
	map[i]=0;
	while(i>=1)
	{
		++map[i];
		//cout<<i<<" "<<map[i]<<" ";
		while(map[i]<=size && !placeRight(i))//���ж�
		{
			++map[i];
		}
		//cout<<map[i]<<endl;
		if(map[i]<=size)//���ж� λ�÷��� 
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
		else//��δ������ 
		{
			--i;
		}

	}
}


int main()
{
	queen(6);
 } 
