/*Description
       有如下图所示的正五边形环，角上和各边中点都挂了珍珠，共挂10个珍珠。每个珍珠可以用C种不同颜色来染色，一共可以得到多少种不同的样式。如果这样一个环，经过任意旋转、翻转后变成另一个正五边形，那么这两个环就认为有同一种样式。



现在告诉你C的数目，请你算算到底有多少种不同的正五边形环？

Input
有多组测试数据。每组测试数据由一个正整数C（C<=20），表示颜色数。

Output
对于每组测试数据，在一行里输出不同的正五边形环数。

Sample Input
2
3
Sample Output
136
6273*/
/*对于含n个对象的置换群G，用t种颜色着色的不同方案数为：*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long long  GetR(int c)
{
	long long  r;
	return r = pow(c, 2) * 4 + pow(c, 6) * 5 + pow(c, 10);
}
int main()
{
	int c;
	while (cin >> c)
	{
		cout <<fixed<<setprecision(0)<<(1.0/10)* GetR(c) << endl;
	}
	return 0;
}