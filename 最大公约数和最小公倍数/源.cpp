/*Description
�������ļ��ж�����������a��b�������Լ��GCD(a,b)����С��������LCM(a,b)��
Input
�����������У�ÿ������������a��b��(|a|,|b|<65536)��
����ֱ���ļ����������
Output

��ÿһ�в������ݣ���һ�����������Case #:�������С�#���ǲ������ݵ��б�ţ���1��ʼ��������������������Ϸֱ�������������������Լ������С����������������������������no GCD����������С���������������no LCM���������������֮���һ�С�
*/

#include<iostream>
#include<cmath>
using namespace std;

int GCD(int a, int b)
{
	int r=-1;
	if (a == 0 && b == 0)
		return r ;
	if (a == 0)
		return abs(b);
	if (b == 0)
		return abs(a);
	if (abs(a) >= abs(b))
	{
		if (a%b == 0)
			return r = abs(b);		//���Լ��Ϊb
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
			return r = abs(a);		//���Լ��Ϊb
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

//��С������
int LCM(int a, int b)
{
	int r=-1;
	if (a == 0 || b == 0)
		return r;
	return r= abs(a*b/GCD(a,b));
}
int main()
{
	int a, b;
	int count = 0;
	while (cin >> a >> b)
	{
		count++;
		cout << "Case " << count << ":" << endl;
		if (GCD(a, b) == -1)
			cout <<"no GCD" << endl;
		else
			cout << "GCD(" << a << "," << b << ") = " << GCD(a, b) << endl;
		if (LCM(a, b) == -1)
			cout << "no LCM" << endl;
		else
			cout << "LCM(" << a << "," << b << ") = " <<LCM(a, b) << endl;
		cout << endl;
	}
	return 0;
}