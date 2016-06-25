#include<iostream>  
#include<cmath>  
using namespace std;

long long f[1005];
int mod = 1071017;;
//����P��1071017����ŷ��ֵ
int Eular(int p)
{
	int r = 1;
	for (int i = 2;i * i <= p;i++)
		if (p % i == 0)		//i��p������
		{
			p /= i;
			r *= (i - 1);
			while (p % i == 0)
			{
				p /= i;
				r *= i;
			}
		}
	if (p > 1)
		r *= (p - 1);
	return r;
}

//����a^(b mod 
int pow(int a, int b, int mod)
{
	int r = 1;
	for (int i = 1;i <= b;++i) {
		r *= a;		
		r = r % mod;
	}
	return r;
}

//������
int GetR(int n, int mod) {
	if (n == 0)
		return 1;
	return pow(3, GetR(n - 1, Eular(mod)), mod);
}
int main()
{
	
	f[0] = 1;
	int t;
	cin >> t;
	while (t-->0)
	{
		int n;
		cin >> n;
		if (n >= 6) 
		{
			cout << "525919" << endl;
			continue;
		}
		int i = 1;
		int tmpr = GetR(n, mod);
		cout << tmpr << endl;

	}

	return 0;
}