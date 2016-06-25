#include<stdio.h>
int main()
{
	int n;
	char ch[200];
	
	while (~scanf_s("%d", &n))
	{
		if (n == 0)
		{
			putchar('0');
			putchar('\n');
		}
		else
		{
			int i = 0;
			int flag = 0;
			if (n<0)
			{
				flag = -1;
				n = -n;
			}
			int tmp;
			while (n>0)
			{
				tmp = n % 3;
				if (tmp >= 10)
					ch[i] = tmp - 10 + 'A';
				else
					ch[i] = tmp + '0';
				i++;
				n /= 3;
			}

			if (flag == -1)
				putchar('-');
			for (int j = i - 1;j >= 0;j--)
				putchar(ch[j]);
			putchar('\n');
		}
		
	}
	return 0;
}