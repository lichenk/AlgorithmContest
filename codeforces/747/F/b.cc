#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, k;
int ai[20];
LL f[20][20];
LL fac[20];
int as[20];
LL C(int a, int b)
{
	return fac[a] / fac[b] / fac[a - b];
}
int tot;
LL get(int l)
{
	LL sum = 0;
	for (int i = 0; i <= 16; ++ i)
		for (int j = 0; j <= l; ++ j)
			f[i][j] = 0;
	f[0][0] = 1;
	for (int i = 0; i < 16; ++ i)
		for (int j = 0; j <= ai[i]; ++ j)
			for (int k = 0; k <= l - j; ++ k)
				f[i + 1][j + k] += f[i][k] * C(l - k, j);
	return f[16][l];
}
int main()
{
	scanf("%d%d", &n, &k); n --;
	fac[0] = 1;
	for (int i = 1; i <= 16; ++ i) fac[i] = fac[i - 1] * i;
	
	for (int i = 0; i < 16; ++ i) ai[i] = k; tot = 1; ai[0] --;
	while (1)
	{
		LL p = get(tot - 1) * 15;
		if (n >= p) n -= p, tot ++;
		else break;
	} ai[0] ++;
	int aaa = tot;
	while (tot)
	{
		for (int i = tot == aaa; i < 16; ++ i)
			if (ai[i])
			{
				ai[i] --;
				LL p = get(tot - 1);
				if (n >= p) n -= p;
				else {as[tot] = i; break;}
				ai[i] ++;
			}
		tot --;
	}
	for (int i = aaa; i >= 1; -- i)
		if (as[i] >= 10)
			printf("%c", as[i] - 10 + 'a');
		else 
			printf("%d", as[i]);
	printf("\n");
}