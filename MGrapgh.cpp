#include<iostream>
#include<queue>
#include<string>
#define MAX 10

using namespace std;

struct Vertex 
{
	int no;// 
	string data;
 };
struct MatGraph 
{
	int n,e;//��ͱߵ���Ŀ 
	int edges[MAX][MAX];//  �ڽӾ���ı����� ͼ�����ӹ�ϵ 
	Vertex vertexes[MAX];//�����Ϣ 
};
 
MatGraph graph;
int visited[10]; 
//g�������������� 
void createGraph(MatGraph &g,int n,int e)//n;
{
	int i=0;
	g.n=n;
 	g.e=e;
 	cout<<"������ͼ�ı�ź�ֵ��"<<endl; 
	for(i=0;i<n;i++)//����ÿ���������Ϣ 
	{
		cin>>g.vertexes[i].no>>g.vertexes[i].data;
	}
	int start,end;
	cout<<"������ͼ�ĵ�������յ㣺"<<endl; 
	for(i=0;i<e;i++)
	{
		cin>>start>>end;
		g.edges[start][end]=1;
		g.edges[end][start]=1;
	}
 } 
 
 void show(MatGraph g)
 {
 	cout<<"ͼ���ڽӱ�"<<endl;
 	for(int i=0;i<g.n;i++)
 	{
 		for(int j=0;j<g.n;j++)
 		{
 			cout<<g.edges[i][j]<<'\t';
		 }
		 cout<<endl;
	 }
	 cout<<"ͼ�ĸ����ֵ��"<<endl;
	 for(int i=0;i<g.n;i++)
	 {
	 	cout<<g.vertexes[i].data<<" ";
	 }
	 cout<<endl;
 }
 //������ȱ��� 
void DFS(MatGraph g,int v)
{
	cout<<v<<" ";
	visited[v]=1;
	for(int i=0;i<g.n;i++)
	{
		if(g.edges[v][i]!=0 && visited[i]==0)
		{
			DFS(g,i);
		}
	}
 } 
//������ȱ���
void BFS(MatGraph g,int v)
{
	//������� 
	queue<int> q;
	//���ʱ������visited ����ʼ��Ϊ0
	int visited[MAX]={0};
	//���V
	cout<<v<<" ";
	//����V�ѱ�����
	visited[v]=1;
	//V���q
	q.push(v); 
	int front;//��ͷԪ�� 
	while(!q.empty())
	{
		//��ȡ��ͷԪ��W
		int front=q.front();
		// ɾ����ͷ������
		q.pop();
		//ɨ��W���ڵ������������ڵ�������
		 for(int i=0;i<g.n;i++)
		 {
		 	//�ж��Ƿ���Ҫɨ�� 
		 	if(visited[i]==0&&g.edges[front][i]==1)
		 	{
		 		cout<<i<<" ";
		 		visited[i]=1;
		 		q.push(i);

			 }
		 }
	 } 
}
  
int main()
{
	createGraph(graph,5,7);
	show(graph);
	DFS(graph,0);
	cout<<endl;
	BFS(graph,0);
}
//0 BOB 1 KEN 2 JENNY 3 YE 4 VIV
//0 1 0 4 1 2 1 3 1 4 2 3 3 4
