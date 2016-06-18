/*Description
������һ��������λ���������ĸ�λ����ȥ�����ٴ����µ����м�ȥ��λ����5�������ҽ�������17�ı���ʱ��ԭ��Ҳ��17�ı��� ��

���磬34��17�ı�������Ϊ3-20=-17��17�ı�����201����17�ı�������Ϊ20-5=15����17�ı���������һ��������n������������ж����Ƿ���17�ı�����

Input
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=10100������ʾ���жϵ���������n=0��ʾ�����������ĳ���Ӧ��������һ�С�

Output
����ÿ��������ݣ����һ�У���ʾ��Ӧ��n�Ƿ���17�ı�����1��ʾ�ǣ�0��ʾ��*/

#include<iostream>
#include<sstream>
#include<vector> 
using namespace std;


typedef vector<int> long_int;
//�ַ���ת����long_int,����ѹջ
long_int ChangeToLongInt(string str)
{
	long_int result;
	for (int i = str.size() - 1;i >= 0;i--)
	{
		if (str[i] < '0' || str[i] > '9')		//������
			return result;
		result.push_back(str[i] - '0');
	}
	return result;
}
//��֪������n��0������long_int
long_int ChangeToLongInt(int N, int znum)
{
	long_int result;
	stringstream sstr;
	string str;
	sstr << N;
	while (znum-- > 0)
	{
		sstr << "0";
	}
	sstr >> str;
	result = ChangeToLongInt(str);
	return result;
}
//�߾������
long_int LongIntAdd(long_int a, long_int b)
{
	long_int r;
	int flag = 0;
	for (size_t i = 0;i < a.size() || i < b.size() || flag != 0;i++)
	{
		int sum = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + flag;
		flag = sum / 10;			//��λ��
		sum %= 10;
		r.push_back(sum);
	}
	return r;
}

//�߾������
long_int LongIntSub(long_int a, long_int b)
{
	long_int r;
	int flag = 0;		//��λ
	for (size_t i = 0;i < a.size() || i < b.size() || flag != 0;i++)
	{
		int sum = (i < a.size() ? a[i] : 0) - (i < b.size() ? b[i] : 0) - flag;
		flag = 0;
		if (sum < 0) {
			sum += 10;
			flag = 1;
		}
		r.push_back(sum);
	}
	while (r.back() == 0)
	{
		r.pop_back();
	}
	return r;
}

//�߾������
long_int LongIntMulti(long_int a, long_int b)
{
	long_int r;
	for (size_t i = 0;i<a.size();i++)
		for (size_t j = 0;j < b.size();j++)
		{
			long_int tmp = ChangeToLongInt(a[i] * b[j], i + j);
			r = LongIntAdd(r, tmp);
		}
	return r;
}

//����ַ����������
string LongIntToString(long_int a)
{
	string str;
	stringstream sstr;
	while (!a.empty())
	{
		sstr << a.back();
		a.pop_back();
	}
	sstr >> str;
	return str;
}
bool Is(long_int n)
{
	
	if (n.size() > 5)
	{
		int tmp = n.front();
		n.erase(n.begin());
		return Is(LongIntSub(n,LongIntMulti( ChangeToLongInt(5,0), ChangeToLongInt(tmp,0))));
	}
	stringstream sstr;
	sstr << LongIntToString(n);
	int t;
	sstr >> t;
	if ( t % 17 == 0)
		return true;
	return false;
}

int main()
{
	string n;
	while (cin >> n)
	{
		if (n[0] == '0')
			return 0;
		if (Is(ChangeToLongInt(n)))
		{
			cout << "1" << endl;
		}
		else
			cout << "0" << endl;
	}
	return 0;
}