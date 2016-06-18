/*Description
定理：把一个至少两位的正整数的个位数字去掉，再从余下的数中减去个位数的5倍。当且仅当差是17的倍数时，原数也是17的倍数 。

例如，34是17的倍数，因为3-20=-17是17的倍数；201不是17的倍数，因为20-5=15不是17的倍数。输入一个正整数n，你的任务是判断它是否是17的倍数。

Input
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=10100），表示待判断的正整数。n=0表示输入结束，你的程序不应当处理这一行。

Output
对于每组测试数据，输出一行，表示相应的n是否是17的倍数。1表示是，0表示否。*/

#include<iostream>
#include<sstream>
#include<vector> 
using namespace std;


typedef vector<int> long_int;
//字符串转换成long_int,逆序压栈
long_int ChangeToLongInt(string str)
{
	long_int result;
	for (int i = str.size() - 1;i >= 0;i--)
	{
		if (str[i] < '0' || str[i] > '9')		//非数字
			return result;
		result.push_back(str[i] - '0');
	}
	return result;
}
//已知整数与n个0，构造long_int
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
//高精度相加
long_int LongIntAdd(long_int a, long_int b)
{
	long_int r;
	int flag = 0;
	for (size_t i = 0;i < a.size() || i < b.size() || flag != 0;i++)
	{
		int sum = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + flag;
		flag = sum / 10;			//进位数
		sum %= 10;
		r.push_back(sum);
	}
	return r;
}

//高精度相减
long_int LongIntSub(long_int a, long_int b)
{
	long_int r;
	int flag = 0;		//借位
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

//高精度相乘
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

//变成字符串逆序输出
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