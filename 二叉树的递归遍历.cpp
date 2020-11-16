#include<iostream>
#include<vector>
using namespace std;

struct treeNode{
	int data;
	treeNode *left;
	treeNode *right;
	
	treeNode(int d){
		data=d;
		left=NULL;
		right=NULL;	
	}
};

typedef treeNode biTree;

biTree *createTree(int a[],int b[],int n)
{
	 if(n<=0)
	 	return NULL;
	int root=a[0];
	treeNode *bt=new treeNode(root);
	int k=0;
	while(k<n&&root!=b[k])
	{
		k++;
	 } 
	bt->left=createTree(a+1,b,k);
	bt->right=createTree(a+k+1,b+k+1,n-k-1);
	return bt;
}
//÷––Ú±È¿˙ 
void showMid(treeNode *bt){
	if(bt==NULL) return;
	showMid(bt->left);
	cout<<bt->data<<"-->";
	showMid(bt->right);
}
//µ›πÈœ˙ªŸ 
void destroy(treeNode* &bt)
{
	if(bt==NULL) return;
	destroy(bt->left);
	//bt->left=nullptr;
	destroy(bt->right);
	//bt->right=nullptr;
	delete bt;
	bt=NULL; 
}
//øΩ±¥ 
void copyTree(treeNode* bt,treeNode* bt1)
{
	if(bt==NULL) return;
	bt1=new treeNode(bt->data);
	copyTree(bt->left,bt1->left);
	copyTree(bt->right,bt1->right);
}
//≤È’“¬∑æ∂ 
bool findPath(treeNode *bt,int x,vector<int> tmpPath,vector<int> &path)
{
	if(bt==NULL) return false;
	tmpPath.push_back(bt->data);
	if(bt->data==x)
	{
		path=tmpPath;
		return true;
	}
	bool find;
	find=findPath(bt->left,x,tmpPath,path);
	if(find)
	{
		return true;
	}
	else{
		find=findPath(bt->right,x,tmpPath,path);
	}
}

void show(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
int main()
{
	int a[]={1,2,4,5,3,6,7};
	int b[]={4,2,5,1,6,3,7};
	int n=sizeof(a)/sizeof(a[0]);
	treeNode *tree=createTree(a,b,n);
	showMid(tree);
	//destroy(tree);
	treeNode * newT=NULL;
	//newT=new treeNode;
	copyTree(tree,newT);
	showMid(newT);
	cout<<endl;
	
	vector<int> tmpPath;
	vector<int> path;
	bool find;
	find=findPath(tree,5,tmpPath,path);
	cout<<path.empty();
//	cout<<find;
	show(path);
}

