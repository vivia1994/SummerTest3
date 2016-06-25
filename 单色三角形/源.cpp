
/*��Ŀ����
�ڿռ��и�����n���㡣��Щ�������㲻���ߣ�����ÿ������֮�䶼��һ����������ÿһ���߲��Ǻ�ľ��Ǻڵġ�����Щ�������ɵ��������У����һ�������ε������ߵ���ɫ����ͬ����ô���Ǿͳ����������Ϊ��ɫ�����Ρ��ָ�������Ϳ��ɫ���ߣ��������ɫ�����ε���Ŀ��

����
�����ļ��ĵ�һ����һ������T����ʾ������T��������ݡ�������������T��������ݵ�������ÿһ��������ݵĵ�1������������n��m����������n��ʾ������m�Ǻ�ɫ�ߵ���Ŀ����0 <= m <= 250000�� 3 <= n <= 1000����������m�У�ÿ�а�����������p��x����ʾ������ߵ��������㣬��1 <= p < x <= n����

�����������֮����һ���У�����ֱ���ļ�������

���
����ļ��������С��������ļ��е�ÿ��������ݣ������Ӧ�ĵ�ɫ�����ε���Ŀ��

��������
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
�������
2
1*/

#include<iostream>
#include<string.h>
using namespace std;

int A[1000][1000];//��¼��������ʲô
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
	int m, n;//m���� n������
	
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
		}//����
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

