#include<iostream>

using namespace std;
#define MAXN 8
int x,y;
int size;
int board[MAXN][MAXN]={0};
int tile;
void chessBoard(int tr,int tc,int dr,int dc,int size)
{
	//tr tc�Ǿ��ε����ϽǺ�������
	//dr dc�����������������
	//size �Ǵ�С 
	if(size==1) return;
	int s=size/2;
	int t=++tile;
	
	//���Ͻ�����
	if(dr<tr+s && dc<tc+s)
	{
		chessBoard(tr,tc,dr,dc,s);
	 }
	 else{
	 	board[tr+s-1][tc+s-1]=t;
	 	chessBoard(tr,tc,tr+s-1,tc+s-1,s);
	 }
	 //���Ͻ� 
	if(dr<tr+s && dc>=tc+s)
	{
		chessBoard(tr,tc+s,dr,dc,s);
	}else{
		board[tr+s-1][tc+s]=t;
		chessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	//���½�
	if(dr>=tr+s && dc<tc+s)
	{
		chessBoard(tr+s,tc,dr,dc,s);
	 } 
	 else
	 {
	 	board[tr+s][tc+s-1]=t;
	 	chessBoard(tr+s,tc,tr+s,tc+s-1,s);
	 }
	 //���½�
	 if(dr>=tr+s &&dc>=tc+s)
	 {
	 	chessBoard(tr+s,tc+s,dr,dc,s);
	  } 
	  else{
	  	board[tr+s][tc+s]=t;
	  	chessBoard(tr+s,tc+s,tr+s,tc+s,s);
	  }
	  //tile++;
}

void show()
{
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	chessBoard(0,0,1,7,8);
	show();
}
