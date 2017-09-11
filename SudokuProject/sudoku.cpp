
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int judgement(int r, int c, int s);
void fillSpace(int r, int c);
void nextSpace(int r, int c);
void init();
void print();
bool isnum(char *str);
int board[9][9];
int amount;
int t;
ofstream fcout("sudoku.txt");
int main(int argc, char * argv[])
{
	if (argc == 3&&strcmp(argv[1],"-c")&&isnum(argv[2]));
	{ 
		amount = atoi(argv[2]);
		int r = 0, c = 0;
		init();
		nextSpace(r, c);
	}
	else
	{
		cout << "error!" << endl;
	}
	return 0;
}
int judgement(int r, int c, int s)
{
	int i, j, r2, c2;
	for (i = 0; i<9; i++)
	{
		if (board[r][i] == s || board[i][c] == s)
		{
			return 0;
		}
	}
	r2 = r / 3 * 3;
	c2 = c / 3 * 3;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if (s == board[r2 + i][c2 + j])
			{
				return 0;
			}
		}
	}
	return 1;
}
void fillSpace(int r, int c)
{
	for (int s = 1; s < 10; s++)//分别填入数字1-9
	{
		if (judgement(r, c, s))//判断是否满足条件
		{
			board[r][c] = s;//给该位置赋值
			nextSpace(r, c);//准备填下一个位置
			board[r][c] = 0;//初始化该位置

		}
	}
}
void nextSpace(int r, int c)
{
	if (r == 8 && c == 8)
	{
		print();
		t++;
		if (amount == t)
		{
			fcout.close();
			exit(0);
		}
	}
	c++;
	r += c / 9;
	r = r % 9;
	c = c % 9;
	fillSpace(r, c);
}
void print()
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			fcout << board[i][j] << " ";
		}
		fcout << endl;
	}
	fcout << endl;
}
void init()
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			board[i][j] = 0;
		}
	}
	board[0][0] = 4;
}
bool isnum(char* str)
{
	int size=sizeof(str);
	for(int i=0;i<size;i++)
	{
		if(str[i]<47||str[i]>58)
		return false;	
	}
	return true;
}
