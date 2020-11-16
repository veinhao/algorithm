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
	int n,e;//点和边的数目 
	int edges[MAX][MAX];//  邻接矩阵的边数组 图的连接关系 
	Vertex vertexes[MAX];//点的信息 
};
 
MatGraph graph;
int visited[10]; 
//g必须是引用类型 
void createGraph(MatGraph &g,int n,int e)//n;
{
	int i=0;
	g.n=n;
 	g.e=e;
 	cout<<"请输入图的编号和值："<<endl; 
	for(i=0;i<n;i++)//输入每个顶点的信息 
	{
		cin>>g.vertexes[i].no>>g.vertexes[i].data;
	}
	int start,end;
	cout<<"请输入图的点的起点和终点："<<endl; 
	for(i=0;i<e;i++)
	{
		cin>>start>>end;
		g.edges[start][end]=1;
		g.edges[end][start]=1;
	}
 } 
 
 void show(MatGraph g)
 {
 	cout<<"图的邻接表："<<endl;
 	for(int i=0;i<g.n;i++)
 	{
 		for(int j=0;j<g.n;j++)
 		{
 			cout<<g.edges[i][j]<<'\t';
		 }
		 cout<<endl;
	 }
	 cout<<"图的各点的值："<<endl;
	 for(int i=0;i<g.n;i++)
	 {
	 	cout<<g.vertexes[i].data<<" ";
	 }
	 cout<<endl;
 }
 //深度优先遍历 
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
//广度优先遍历
void BFS(MatGraph g,int v)
{
	//定义队列 
	queue<int> q;
	//访问标记数组visited 并初始化为0
	int visited[MAX]={0};
	//输出V
	cout<<v<<" ";
	//设置V已被访问
	visited[v]=1;
	//V入队q
	q.push(v); 
	int front;//队头元素 
	while(!q.empty())
	{
		//获取队头元素W
		int front=q.front();
		// 删除队头，出队
		q.pop();
		//扫描W所在的行找他的相邻点访问入队
		 for(int i=0;i<g.n;i++)
		 {
		 	//判断是否需要扫描 
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
