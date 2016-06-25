#include <stdio.h>  
#include <string.h>  
#include<iostream>
#define MAX 10000000  
#define MIN -10000000  

int ln[200],sum[200];
int  n, m;
int mn, mx;
int A[200][20];//A[i][j]=第1-i个数分成j份，结果最大值  
int B[200][20];//B[i][j]=第1-i个数分成j份，结果最小值  

int MinValue(int a, int b)
{
	if (a>b)
		return b;
	return a;
}
int MaxValue(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
void DP(int a[])
{
	int i, j, k;
	for (i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	for (i = 0;i <= n;i++)
		for (j = 0;j <= m;j++)
		{
			A[i][j] = 0;
			B[i][j] = -1u >> 1;
		}
	for (i = 1;i <= n;i++)
	{
		A[i][1] = B[i][1] = (sum[i] % 10 + 10) % 10;
	}
	A[0][0] = 1;
	B[0][0] = 1;
	for (j = 2;j <= m;j++)
	{
		for (i = j;i <= n;i++)
		{
			for (k = j - 1;k<i;k++)
			{
				{
					A[i][j] = MaxValue(A[i][j], A[k][j - 1] * (((sum[i] - sum[k]) % 10 + 10) % 10));
					B[i][j] = MinValue(B[i][j], B[k][j - 1] * (((sum[i] - sum[k]) % 10 + 10) % 10));
				}
			}
		}
	}
	mx = MaxValue(mx, A[n][m]);
	mn = MinValue(mn, B[n][m]);
}
int main()
{
	int i, j, k;
	mx = 0;
	mn = -1u >> 1;
	scanf("%d%d", &n, &m);
	for (i = 1;i <= n;i++)
	{
		scanf("%d", &ln[i]);
		
		ln[i + n] = ln[i];
	}
	for (i = 0;i<n;i++)
		DP(ln + i);
	printf("%d\n%d\n", mn, mx);
	return 0;
}
