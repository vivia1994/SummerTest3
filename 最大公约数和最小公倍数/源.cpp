/*Description
从输入文件中读入两个整数a，b，求最大公约数GCD(a,b)和最小公倍数和LCM(a,b)。
Input
输入有若干行，每行有两个整数a和b，(|a|,|b|<65536)。
输入直到文件输入结束。
Output

对每一行测试数据，在一行上先输出“Case #:”，其中“#”是测试数据的行编号（从1开始），接着在下面的两行上分别输出这两个整数的最大公约数和最小公倍数。如无最大公因数，则输出“no GCD”；如无最小公倍数，则输出“no LCM”；两组输出数据之间空一行。
*/

#include<iostream>
#include<cmath>
using namespace std;

int GCD(int a, int b)
{
	int r=-1;
	if (a == 0 && b == 0)
		return r ;
	if (a == 0)
		return abs(b);
	if (b == 0)
		return abs(a);
	if (abs(a) >= abs(b))
	{
		if (a%b == 0)
			return r = abs(b);		//最大公约数为b
		for (int i = 1;i <= abs(b) / 2 + 1;i++)
		{
			if (a%i == 0 && b%i == 0)
			{
				r = i;
			}
		}
		return r;
	}
	if (abs(a) < abs(b))
	{
		if (b%a == 0)
			return r = abs(a);		//最大公约数为b
		for (int i = 1;i <= abs(a) / 2 + 1;i++)
		{
			if (a%i == 0 && b%i == 0)
			{
				r = i;
			}
		}
		return r;
	}
}

//最小公倍数
int LCM(int a, int b)
{
	int r=-1;
	if (a == 0 || b == 0)
		return r;
	return r= abs(a*b/GCD(a,b));
}
int main()
{
	int a, b;
	int count = 0;
	while (cin >> a >> b)
	{
		count++;
		cout << "Case " << count << ":" << endl;
		if (GCD(a, b) == -1)
			cout <<"no GCD" << endl;
		else
			cout << "GCD(" << a << "," << b << ") = " << GCD(a, b) << endl;
		if (LCM(a, b) == -1)
			cout << "no LCM" << endl;
		else
			cout << "LCM(" << a << "," << b << ") = " <<LCM(a, b) << endl;
		cout << endl;
	}
	return 0;
}