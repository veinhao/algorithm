#include<iostream>
using namespace std;
#define MAX 8
/*************************
eightQueen by backtrace
**************************/
int board[MAX][MAX] = { 0 };
int way;
int isSuitable(int row, int col)//当前位置是否适合放置
{
	if (row<0 || row>MAX || col<0 || col>MAX)
		return 0;
	if (board[row][col])
		return 0;

	//decide row or col is suitable
	for (int i = 0; i < MAX; i++)
	{
		if (board[i][col] || board[row][i])
			return 0;
	}

	for (int i = 1; i <= MAX; i++)
	{
		//decide upper left corner diagonal is suiteable
		if (col >= i && row >= i)
		{
			if (board[row - i][col - i])
				return 0;
		}
		//decide upper right corner diagonal is suitable
		if ((row >= i && (col + i) < MAX))
		{
			if (board[row - i][col + i])
				return 0;
		}
		//decide bottom left corner diagonal is suitable
		if ((row + i) < MAX && col >= i)
		{
			if (board[row + i][col - i])
				return 0;
		}
		//decide bottom right corner diagonal is suitable
		if ((row + i) < MAX && (col + i) < MAX)
		{
			if (board[row + i][col + i])
				return 0;
		}
	}
	return 1;
}

void queen(int i)
{
	if (i > MAX)
	{
		++way;

	}
	else
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				if (isSuitable(j, k))
				{
					//cout << i << " ";
					board[j][k] = 1;
					queen(i + 1);
					board[j][k] = 0;	

				}
			}
		}
	}
}
//阶乘 
int factorial(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	way = 0;
	queen(1);
	cout << way/factorial(MAX);
}
