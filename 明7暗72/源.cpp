#include<iostream>

using namespace std;


bool IsSenven(long long n)		//��7�ı���
{
	
	return !(n % 7);
}
//�ж�����n���Ƿ���7 
bool HaveSenve(int n)		//��������7
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
	long long  n;		//n����ʼ��
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




