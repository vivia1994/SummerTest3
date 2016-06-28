#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef double dbl;

const dbl G = 9.8;
const dbl PI = acos(-1.0);
const dbl Eps = 1e-8;

dbl distance(dbl ang, dbl v, dbl h)
{
	dbl s = sin(ang);
	dbl c = cos(ang);
	return v * s * (v * c + sqrt(v * v * c * c + 2.0 * G * h)) / G;
}

dbl Tris(dbl v, dbl h)
{
	dbl l = 0, r = PI / 2.0;
	int t = 30;
	while (t-- > 0)
	{
		dbl mid = (l + r) / 2.0;
		dbl midd = (l + mid) / 2.0;
		if (distance(midd, v, h) > distance(mid, v, h))
			r = mid;
		else
			l = midd;
	}
	return l;
}

dbl BisLeft(dbl l, dbl r, dbl d, dbl v, dbl h)
{
	int t = 30;
	while (t-- > 0)
	{
		dbl mid = (l + r) / 2.0;
		if (distance(mid, v, h) <= d)
			l = mid;
		else
			r = mid;
	}
	return l;
}

dbl BisRight(dbl l, dbl r, dbl d, dbl v, dbl h)
{
	return BisLeft(r, l, d, v, h);
}


int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		dbl h; 
		vector<dbl> v; 
		dbl pos[4]; 
		cin >> h >> pos[0] >> pos[1] >> pos[2] >> pos[3]; 
		for (int i = 0; i < n; i++)
		{
			dbl t; 
			cin >> t; 
			v.push_back(t); 
		}
		int res = 0; 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)

			{
				dbl farest = Tris(v[i], h); 
				if (distance(farest, v[i], h) < pos[j])
					continue; 
				dbl wi = pos[j]; 
				if (j == 0)
					wi += Eps; 
				if (j == 1)
					wi -= Eps; 
				if (j == 2)
					wi -= Eps; 
				if (j == 3)
					wi += Eps;
				dbl ang = BisLeft(0.0, farest, wi, v[i], h); 
				bool flag = true; 
				int c = 0; 
				for (int k = 0; k < n; k++)
				{
					dbl here = distance(ang, v[k], h); 
					if (here >= pos[2] && here <= pos[3])
					{
						flag = false; 
						break;
					}
					if (here >= pos[0] && here <= pos[1])
						++c; 
				}
				if (flag) res = max(res, c);
				if (res == n) break;

				ang = BisRight(farest, PI, wi, v[i], h);
				flag = true; 
				
				c = 0;
				for (int k = 0; k < n; k++)
				{
					dbl here = distance(ang, v[k], h);
					if (here >= pos[2] && here <= pos[3])
					{
						flag = false; 
						break;
					}
					if (here >= pos[0] && here <= pos[1])
						++c; 
				}
				if (flag) res = max(res, c);
				if (res == n)
					break; 
			}
		}
		cout << res << endl; 
	}
	return 0; 
}