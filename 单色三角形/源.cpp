
/*题目描述
在空间中给出了n个点。这些点任三点不共线，并且每两个点之间都有一条线相连，每一条线不是红的就是黑的。在这些点和线组成的三角形中，如果一个三角形的三条边的颜色都相同，那么我们就称这个三角形为单色三角形。现给出所有涂红色的线，试求出单色三角形的数目。

输入
输入文件的第一行有一个整数T，表示下面有T组测试数据。接下来的行是T组测试数据的描述。每一组测试数据的第1行是两个整数n和m，其中整数n表示点数，m是红色边的数目，（0 <= m <= 250000， 3 <= n <= 1000）。接着有m行，每行包含两个整数p，x，表示这条红边的两个顶点，（1 <= p < x <= n）。

两组测试数据之间有一空行，输入直到文件结束。

输出
输出文件有若干行。对输入文件中的每组测试数据，输出对应的单色三角形的数目。

样例输入
2
6 9
1 2
2 3
2 5
1 4
1 6
3 4
4 5
5 6
3 6

3 3
1 2
2 3
1 3
样例输出
2
1*/

#include<iostream>
#include<string.h>
using namespace std;

int A[1000][1000];//记录你连的是什么
int C[1000][1000];
int B[1000][1000];

int DogeOne(int xx1);
int DogeTwo(int xx1);

int Solution1(int xx1, int yy1);
int Solution2(int xx1, int yy1);

void Func1(int xx1, int yy1);
void Func2(int xx1, int yy1);

int main()
{
	int m, n;//m点数 n红线数
	
	int num1 = 0;
	
	int num2 = 0;
	int y;
	
	int xx1, yy1;
	int pnt;
	
	cin >> pnt;
	
	int num = 0;
	
	
	while (pnt-->0)
	{
		
		memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B)); memset(C, 0, sizeof(C));
		num1 = num2=0;
		cin >> m >> n;
		for (int x = 1;x <= n;x++)
		{
			cin >> xx1 >> yy1;
			B[xx1][yy1] = 1;
			B[yy1][xx1] = 1;
		}//输入
		for (int x = 1;x <= m;x++)
		{
			
			for (y = 1;y <= m;y++)
			{
				if (B[x][y] == 1)Func1(x, y);
				else if (x != y)Func2(x, y);
				else;
			}
		}
		for (int x = 1;x <= m;x++)
		{
			num1 = num1 + DogeOne(x);
		}
		for (int x = 1;x <= m;x++)
		{
			num2 = num2 + DogeTwo(x);
		}
		cout << (num1 + num2) / 3 << endl;
		
		
	}
	return 0;
}

void Func1(int xx1, int yy1)
{
	int x = 1;
	while (A[xx1][x] != 0)
	{
		x++;
		if (A[xx1][x] == yy1)
		{
			return;
		}
	}
	A[xx1][x] = yy1;
}
void Func2(int xx1, int yy1)
{
	int x = 1;
	while (C[xx1][x] != 0)
	{
		x++;
		if (C[xx1][x] == yy1)
		{
			return;
		}
	}
	C[xx1][x] = yy1;
}
int DogeOne(int xx1)
{
	int x = 1;
	int y = 2;
	int num = 0;
	int pnt = x;
	while (A[xx1][x] != 0)
	{
		x++;
	}
	pnt = x - 1;
	for (x = 1;x<pnt;x++)
	{
		for (y = x + 1;y <= pnt;y++)
		{
			if (Solution1(A[xx1][x], A[xx1][y]))
			{
				num++;
			}

		}
	}
	return num;
}
int DogeTwo(int xx1)
{
	int x = 1;
	int y = 2;
	int num = 0;
	int pnt = 1;
	while (C[xx1][x] != 0)
	{
		x++;
	}
	pnt = x - 1;
	for (x = 1;x<pnt;x++)
	{
		for (y = x + 1;y <= pnt;y++)
		{
			if (Solution2(C[xx1][x], C[xx1][y]))
			{
				num++;
			}

		}
	}
	return num;
}
int Solution1(int xx1, int yy1)
{
	int x = 1;
	int num = 0;
	while (A[xx1][x] != 0)
	{
		if (A[xx1][x] == yy1)
		{
			return 1;
		}
		x++;
	}
	return 0;
}
int Solution2(int xx1, int yy1)
{
	int x = 1;
	int num = 0;
	while (C[xx1][x] != 0)
	{

		if (C[xx1][x] == yy1)
		{
			return 1;
		}
		x++;
	}
	return 0;
}

