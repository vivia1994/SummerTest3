#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{

	vector<int>v;
	int n;
	while (scanf_s("%d",&n))
	{
		if (n == 0)
			cout <<"0" << endl;
		else
		{
			for (int i = abs(n);i;i = i / 3)
			{
				if (i % 3 == 1)
					v.push_back(1);
				else if (i % 3 == 2)
					v.push_back(2);
				else
					v.push_back(0);
			}
			
			while (!v.empty())
			{
				putchar(v.back()+'0');
				v.pop_back();
			}
			putchar('\n');
		}
	}
	return 0;
}