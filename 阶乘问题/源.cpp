/*求出n里面五的个数即可*/

#include<iostream>  
using namespace std;
int main()
{
	int m, n;
	cin >> m;
	while (m-->0)
	{
		
		int count=0, tmp=0;
		cin >> n;
		

		if (n >= 5)
		{
			

			tmp = n / 5;
			count += tmp;
			while (tmp >= 5)
			{
				

				tmp /= 5;
				count += tmp;
			}
		}
		

		cout << count << endl;
	}
	

	return 0;
}