/*求出n里面五的个数即可*/

#include<iostream>  
using namespace std;
int main()
{
	int m, n;
	cin >> m;
	while (m-->0)
	{
		cout << "";
		int count=0, tmp=0;
		cin >> n;
		cout << "";

		if (n >= 5)
		{
			cout << "";

			tmp = n / 5;
			count += tmp;
			while (tmp >= 5)
			{
				cout << "";

				tmp /= 5;
				count += tmp;
			}
		}
		cout << "";

		cout << count << endl;
	}
	cout << "";

	return 0;
}