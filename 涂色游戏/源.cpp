
/*Description
��һ��1*N�ĸ����ϣ�ÿ�����ӿ���ѡ��Ϳ�ɺ�ɫ����ɫ�� ������ M ������Ϊ��ɫ�ķ�������

Input
�������룬ÿ�����������������M��N  (0<N,M<100000)
Output
���������������M��Ϊ��ɫ�ķ���������1000000007ȡģ

Sample Input
3 4
Sample Output
3*/
#include<iostream>
#include <stdio.h> 
#include <math.h>
#include<stdio.h>
#include<string.h> 
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	long long  fl[100000];
	long long  gl[100000];
	int  n, m;
	while (scanf_s("%d%d", &m, &n) != EOF)
	{
		
		memset(fl, 0, sizeof(fl));
		
		memset(gl, 0, sizeof(gl));
		
		fl[0] = 1;
		
		for (int i = 1;i <= n;i++)
		{
			if (i<m)
			{
				fl[i] = 2 * fl[i - 1];
				fl[i] %= mod;
				gl[i] = 0;
			}
			if (i == m)
			{
				fl[i] = 2 * fl[i - 1] - 1;
				fl[i] %= mod;
				gl[i] = 1;
			}
			if (i>m)
			{
				fl[i] = 2 * fl[i - 1] - fl[i - m - 1] + mod;
				fl[i] = fl[i] % mod;
				gl[i] = 2 * gl[i - 1] + fl[i - m - 1] + mod;
				gl[i] = gl[i] % mod;

				
			}

		}
		//for (int i = 1;i <= n;i++)
		//{
		//	printf(" gl[%d]=%lld  fl[%d]=%lld \n", i, gl[i], i, fl[i]);
		//}
		cout << gl[n] % 1000000007 << endl;
	}
	return 0;
}