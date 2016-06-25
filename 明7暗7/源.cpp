/*题目描述
今天是个特殊的日子。周尼玛、小豪、小贤、boss还有小d围坐在一张桌子上玩起了明7暗7的游戏。游戏规则是这样的：

一个人报出一个起始数，接下来按照逆时针的顺序轮流报数，如果碰到数是7的倍数或含有7，则拍手，下一个人接着报数。直到有一个人报错了数字或者没有及时拍手为止。

玩游戏嘛，当然得有惩罚，数错的惩罚是很残酷的---怒刷杭电100题。这么简单的游戏对于周尼玛、小豪、小贤、boss这些学霸与大神的集合体来说实在是太无脑了，轻轻松松数到上万不在话下。但是对于数学是历史老师教的小d来说，这是要怒跪100题的节奏，当时他就震惊了。这个时候小d想到了你----传说中的神秘程序员。快帮小d算算什么时候应该拍手什么时候应该报数吧。

输入
有多组输入数据，每组占一行，每一行有两个数字M和N，分别表示起始数字和M以后需要拍手的第N个数字（1≤M,N≤5000000）

输出
每一行输出M以后的第N个需要拍手的数字

样例输入
30 7
56 1
样例输出
57
57*/
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
bool IsSenven(long_int n)		//是7的倍数
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
bool HavSenve(long_int n)		//含有数字7
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
	string m;		//起始数字
	string n;		//第n个需要拍手的数字
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