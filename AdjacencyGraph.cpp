//邻接表的基本操作 

#include<iostream>
#include<string>
#include<queue>
#define MAX 10
using namespace std;

struct Node{//基本节点 
	int Number;//编号 
	int weight;
	struct Node *next;
};

struct HeadNode{//头节点 
	string data;
	Node *headNext;//头节点的下一个 
};

 

struct AdjacencyGraph{
	int n,e;//图的点数和边数 
	HeadNode headNode[MAX];//头节点的集合 
};

AdjacencyGraph Graph;

void createGraph(AdjacencyGraph &g,int nVex,int nEdge)
{
	g.n=nVex;
	g.e=nEdge;
	cout<<"input vertex:\n";
	//输入顶点
	for(int i=0;i<g.n;i++)
	{
		cin>>g.headNode[i].data;
		g.headNode[i].headNext=NULL;
	}
	//输入边的信息
	int start,end;
	Node *arc;
	cout<<"input edge start end:\n";
	for(int i=0;i<g.e;i++)
	{
		cin>>start>>end;
		//申请新节点赋值
		arc=new Node;
		arc->Number=end;
		arc->weight=0;
		arc->next=NULL;
		
		//头插法 
		if(g.headNode[start].headNext==NULL)
		{
			g.headNode[start].headNext=arc;
		}
		else
		{
			arc->next=g.headNode[start].headNext;
			g.headNode[start].headNext=arc;
		}
	 } 
}
//深度优先搜索
int visited[100];
void DFS(AdjacencyGraph g,int start)
{
	cout<<start<<"\t";
	visited[start]=1;
	Node *p=g.headNode[start].headNext;
	while(p!=NULL)
	{
		if(visited[p->Number]==0)
		{
			DFS(g,p->Number);
		}
		p=p->next;
	}
}

void BFS(AdjacencyGraph &g,int start)
{
	int visited1[100]={0},w;
	queue<int> qu;
	visited1[start]=1;
	cout<<start<<"->";
	Node *p=g.headNode[start].headNext;
	qu.push(start);
	while(!qu.empty()) 
	{
		w=qu.front();
		qu.pop();
		p=g.headNode[w].headNext;
		while(p!=NULL)
		{
			if(visited1[p->Number]==0)
			{
				cout<<p->Number<<"->";
				visited1[p->Number]=1;
				qu.push(p->Number);
			}
			p=p->next;
		}
	}
}

int main()
{
	//0 1 2 3 4
	//0 1 0 4 1 2 1 3 1 4 3 2 3 4
	AdjacencyGraph graph;
	createGraph(graph,5,7);
	cout<<"DFS: ";
	DFS(graph,0);
	cout<<endl;
	cout<<"BFS: ";
	BFS(graph,0);
}
