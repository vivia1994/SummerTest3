/*��Ŀ����
�����Ǹ���������ӡ������ꡢС����С�͡�boss����СdΧ����һ����������������7��7����Ϸ����Ϸ�����������ģ�

һ���˱���һ����ʼ����������������ʱ���˳�����������������������7�ı�������7�������֣���һ���˽��ű�����ֱ����һ���˱��������ֻ���û�м�ʱ����Ϊֹ��

����Ϸ���Ȼ���гͷ�������ĳͷ��Ǻܲп��---ŭˢ����100�⡣��ô�򵥵���Ϸ���������ꡢС����С�͡�boss��Щѧ�������ļ�������˵ʵ����̫�����ˣ������������������ڻ��¡����Ƕ�����ѧ����ʷ��ʦ�̵�Сd��˵������Ҫŭ��100��Ľ��࣬��ʱ�������ˡ����ʱ��Сd�뵽����----��˵�е����س���Ա�����Сd����ʲôʱ��Ӧ������ʲôʱ��Ӧ�ñ����ɡ�

����
�ж����������ݣ�ÿ��ռһ�У�ÿһ������������M��N���ֱ��ʾ��ʼ���ֺ�M�Ժ���Ҫ���ֵĵ�N�����֣�1��M,N��5000000��

���
ÿһ�����M�Ժ�ĵ�N����Ҫ���ֵ�����

��������
30 7
56 1
�������
57
57*/
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
bool IsSenven(long_int n)		//��7�ı���
{

	if (n.size() > 5)
	{
		int tmp = n.front();
		n.erase(n.begin());
		return IsSenven(LongIntSub(n, LongIntMulti(ChangeToLongInt(2, 0), ChangeToLongInt(tmp, 0))));
	}
	stringstream sstr;
	sstr << LongIntToString(n);
	int t;
	sstr >> t;
	if (t % 7 == 0)
		return true;
	return false;
}
bool HavSenve(long_int n)		//��������7
{
	for (int i = 0;i < n.size();i++)
	{
		if (n[i] == 7)
			return true;
	}
	return false;
}
int main()
{
	string m;		//��ʼ����
	string n;		//��n����Ҫ���ֵ�����
	while (cin >>m>>n)
	{
		stringstream sstr;
		int k;
		sstr << n;
		sstr >> k;
		int i = 1;
		while(true)
		{
			long_int r = LongIntAdd(ChangeToLongInt(m), ChangeToLongInt(i,0));
			 if (IsSenven(r) || HavSenve(r) )
			 {
				 k--;
			 }
			 if ((IsSenven(r) || HavSenve(r)) && k == 0)
			 {
				 cout << LongIntToString(r) << endl;
				 break;
			 }
			 i += 1;
			 cout << i << endl;
		}
		
		//cout << LongIntToString(LongIntAdd(ChangeToLongInt(m), LongIntMulti(ChangeToLongInt("7"), ChangeToLongInt(n))));
		
	}
	return 0;
}