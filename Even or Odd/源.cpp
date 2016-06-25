/*求C(n,i)中有多少个组合数是奇数(0<=i<=n)。

Input
多组数据，第一行为一个整数T，表示数据组数。(T <= 1000)

之后有T组数据，每组数据为一个整数n。(1 <= n <= 1000000000)

Output
对于每组数据，输出一个整数表示这些组合数中奇数的个数。

Sample Input
3
1
7
100000
Sample Output
2
8
64*/


/*
组合数的奇偶
奇偶定义：对组合数C(n,k)(n>=k）：将n,k分别化为二进制，若某二进制位对应的n为0，而k为1 ，则C(n,k）为偶数；否则为奇数。
下面是判定方法：
结论：
对于C(n,k），若n&k == k 则c(n,k）为奇数，否则为偶数。*/

#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		int r = 1;
		int count = 0;
		int n;		//(1 <= n <= 1000000000)
		cin >> n;
		while (n)
		{
			if (n % 2 == 1)
			{
				count += 1;
			}
			n /= 2;
		}
		for (int i = 0;i < count;i++)
		{
			r *= 2;
		}
		cout << r << endl;
	}
	return 0;
}