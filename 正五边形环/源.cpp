/*Description
       ������ͼ��ʾ��������λ������Ϻ͸����е㶼�������飬����10�����顣ÿ�����������C�ֲ�ͬ��ɫ��Ⱦɫ��һ�����Եõ������ֲ�ͬ����ʽ���������һ����������������ת����ת������һ��������Σ���ô������������Ϊ��ͬһ����ʽ��



���ڸ�����C����Ŀ���������㵽���ж����ֲ�ͬ��������λ���

Input
�ж���������ݡ�ÿ�����������һ��������C��C<=20������ʾ��ɫ����

Output
����ÿ��������ݣ���һ���������ͬ��������λ�����

Sample Input
2
3
Sample Output
136
6273*/
/*���ں�n��������û�ȺG����t����ɫ��ɫ�Ĳ�ͬ������Ϊ��*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long long  GetR(int c)
{
	long long  r;
	return r = pow(c, 2) * 4 + pow(c, 6) * 5 + pow(c, 10);
}
int main()
{
	int c;
	while (cin >> c)
	{
		cout <<fixed<<setprecision(0)<<(1.0/10)* GetR(c) << endl;
	}
	return 0;
}