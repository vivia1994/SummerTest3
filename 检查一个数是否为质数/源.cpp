#include<iostream>

using namespace std;

bool IsPrime(int n)
{
	if (n == 2)
		return true;
	for (int i = 2;i < n / 2 + 1;i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int N;
	cin >> N;
	if (IsPrime(N))
	{
		cout << "Y" << endl;
		return 0;
	}
	cout << "N" << endl;
	return 0;
}