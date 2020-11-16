//�ڽӱ�Ļ������� 

#include<iostream>
#include<string>
#include<queue>
#define MAX 10
using namespace std;

struct Node{//�����ڵ� 
	int Number;//��� 
	int weight;
	struct Node *next;
};

struct HeadNode{//ͷ�ڵ� 
	string data;
	Node *headNext;//ͷ�ڵ����һ�� 
};

 

struct AdjacencyGraph{
	int n,e;//ͼ�ĵ����ͱ��� 
	HeadNode headNode[MAX];//ͷ�ڵ�ļ��� 
};

AdjacencyGraph Graph;

void createGraph(AdjacencyGraph &g,int nVex,int nEdge)
{
	g.n=nVex;
	g.e=nEdge;
	cout<<"input vertex:\n";
	//���붥��
	for(int i=0;i<g.n;i++)
	{
		cin>>g.headNode[i].data;
		g.headNode[i].headNext=NULL;
	}
	//����ߵ���Ϣ
	int start,end;
	Node *arc;
	cout<<"input edge start end:\n";
	for(int i=0;i<g.e;i++)
	{
		cin>>start>>end;
		//�����½ڵ㸳ֵ
		arc=new Node;
		arc->Number=end;
		arc->weight=0;
		arc->next=NULL;
		
		//ͷ�巨 
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
//�����������
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
