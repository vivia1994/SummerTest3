/*题目描述
As we know, gcd(A, B) means the Greatest Common Divisor (GCD) of A and B.

But zy thinks it is so easy to just let you calculate it.
So now your task is to calculate gcd(A, B^B),it is easy right?

Notice: B ^ B means B multiply by himself B times.

输入
Multiply test case, each case per line.
Each line 2 integers A, B, 1 <= A, B <= 1000
输出
For each test case output one line( one number ), indicating the value of gcd (A, B^B)

样例输入
100 1
100 2
样例输出
1
4*/

/*#include<iostream>
#include<cmath>
using namespace std;

#define ll long long
ll r=1;
// <= A, B <= 1000

//快速幂,b^b
ll QuickPow(ll b)
{
	ll tmp = b;
	while (tmp)
	{
		if (tmp & 1)
			r *= b;
		b *= b;
		tmp >>= 1;
	}
	return r;
}

//快速GCD
int GCD(int a, int b)
{
	int r = -1;
	if (a == 0 && b == 0)
		return r;
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

int main()
{
	ll a, b;
	while (cin >> a >> b)
	{
		if (b > 15)
		{
			bool f = true;
			for (int i = a; i >= 1 && f;i--)
			{
				ll tmpb = 1;
				for (int j = 1;j <= b && f;j++)
				{
					tmpb *= b;
					if (tmpb % i == 0)
					{
						cout << i << endl;
						f = false;
					}
				}
			}
		}
		else
		{
			r = 1;
			QuickPow(b);
			cout << GCD(a, r) << endl;
		}
	}
	return 0;
}*/


import java.math.BigInteger;
import java.util.Scanner;

/**
* Created by laowang on 2016/6/24.
*/
public class Main {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		while (s.hasNext()) {
			String str = s.nextLine();
			String strs[] = str.split(" ");
			int num[] = new int[2];
			for (int i = 0; i<2; i++)
				num[i] = Integer.valueOf(strs[i]);
			BigInteger b = new BigInteger(strs[0]);
			BigInteger b1 = new BigInteger(strs[1]);
			BigInteger b2 = b1.pow(num[1]);
			BigInteger b3 = b.gcd(b2);
			System.out.println(b3);
			System.out.print("");
		}
	}
}