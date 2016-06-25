#include<iostream>

using namespace std;


bool IsSenven(long long n)		//是7的倍数
{
	
	return !(n % 7);
}
//判断整数n中是否含有7 
bool HaveSenve(int n)		//含有数字7
{
	int tmp=n;
	while (tmp)
	{
		if (7 == tmp % 10)
			return true;
		else
			tmp /= 10;
	}
	return false;
}

int main()
{
	long long  n;		//n是起始数
	long long m;
	while (cin >> n >> m)
	{
		long long k = 1;
		while (true)
		{
			long long r = n + k;
			if ((IsSenven(r) || HaveSenve(r)) && m != 0)
				m--;
			if ((IsSenven(r) || HaveSenve(r)) && m == 0)
			{
				cout << r << endl;
				break;
			}
			k += 1;
			//cout << k << endl;

		}
	}
	return 0;
}




