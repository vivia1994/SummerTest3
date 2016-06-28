
/*������ C[ i ][ j ]�����������C��i  ,  j����

���ݳ�ԭ��

��A=  �ϱ�û��
    B = �±�û��
    C = ���û��
    D = �ұ�û��
�ĸ�����������һ����û�е�  =  A + B +  C  + D -AB - AC - AD  - BC - BD  -CD + ABC + ABD + ACD + BCD - ABCD*/

#include<iostream>
#include<string.h>
using namespace std;

#define ll long long
const int mod = 1000007;
ll C[405][405];

//����������  
void StoreC() {
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for (int i = 2;i < 401;i++) 
	{
		for (int j = 0;j <= i;j++) 
		{
			if (j == 0 || j == i)
				C[i][j] = 1;
			else 
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
}
int main() 
{
	StoreC();
	int T;
	cin >> T;
	while (T--) {
		int m, n, k;
		cin >> m >> n >> k;
		if (k < 2 || k > m * n)
		{
			cout << 0 << endl;
			continue;
		}
		ll sum;
		sum = (C[n*m][k] - 2 * C[(n - 1)*m][k] - 2 * C[n*(m - 1)][k] + mod) % mod;
		while (sum < 0)
			sum += mod;
		sum = (sum + C[(n - 2)*m][k] + C[(m - 2)*n][k] + 4 * C[(n - 1)*(m - 1)][k]) % mod;
		while (sum < 0)
			sum += mod;
		sum = (sum - 2 * C[(n - 2)*(m - 1)][k] - 2 * C[(m - 2)*(n - 1)][k] + mod) % mod;
		while (sum < 0)
			sum += mod;
		sum = (sum + C[(n - 2)*(m - 2)][k]) % mod;
		while (sum < 0)
			sum += mod;
		cout << sum << endl;
	}
	return 0;
}