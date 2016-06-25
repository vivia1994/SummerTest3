#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> value;
vector<pair<int, int>> wh;
vector<pair<int, int>> wnh;
vector<pair<int, int>> mm;

void init()
{
	wh.push_back(pair<int, int>(1, 1));
	wnh.push_back(pair<int, int>(0, 0));
	mm.push_back(pair<int, int>(0, 1));
	value.push_back(1);
	for (int i = 1, if_signed = -1; i <= 15; ++i, if_signed *= -1)
	{
		int v = pow(2, i) * if_signed;
		value.push_back(v);
		wh.push_back(pair<int, int>(mm[i - 1].first + v, mm[i - 1].second + v));
		wnh.push_back(pair<int, int>(mm[i - 1].first, mm[i - 1].second));
		mm.push_back(pair<int, int>(min(wh[i].first, wnh[i].first), max(wh[i].second, wnh[i].second)));
	}
}

int BitToInt(string bit)
{
	int r = 0;
	for (int i = bit.size() - 1, power = 0, if_signed = 1; i >= 0; --i, ++power, if_signed *= -1)
		r += pow(2, power) * if_signed * (bit[i] - '0');
	return r;
}

string IntToBit(int n)
{
	string r(16, '0');
	for (int i = 15; i >= 0 && n != 0; --i)
	{
		if (wh[i].first <= n && wh[i].second >= n)
		{
			r[15 - i] = '1';
			n -= value[i];
		}
	}
	while (r.front() == '0' && r.length() > 1)
		r.erase(r.begin());
	return r;
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t-- > 0)
	{
		char tp;
		cin >> tp;
		if (tp == 'b')
		{
			string bit;
			cin >> bit;
			cout << "From binary: " << bit << " is " << BitToInt(bit) << endl;
		}
		else
		{
			int n;
			cin >> n;
			cout << "From decimal: " << n << " is " << IntToBit(n) << endl;
		}
	}
	return 0;
}