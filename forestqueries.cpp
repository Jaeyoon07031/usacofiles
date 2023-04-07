#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int len, quer, xc1, xc2, yc1, yc2, total, top, side, over;
int fst[1000005], pfx[1000005], sqs[1000005], quers[800020];

int main()
{
	cin >> len >> quer;

	for (int i = 0; i < (len * len); i++)
	{
		char tmp;
		cin >> tmp;
		if (tmp == '.')
		{
			fst[i] = 0;
			continue;
		}
		fst[i] = 1;
	}
	for (int i = 0; i < quer; i++)
	{
		scanf("%d%d%d%d", &quers[(i * 4) + 2], &quers[(i * 4)], &quers[(i * 4) + 3], &quers[(i * 4) + 1]);
	}
	for (int i = 0; i < quer * 4; i++)
	{
		quers[i] = quers[i] - 1;
	}
	for (int col = 0; col < len; col++)
	{
		int sum = 0;
		for (int row = 0; row < len; row++)
		{
			sum = sum + fst[(col * len) + row];
			pfx[(col * len) + row] = sum;
		}
	}
	for (int row = 0; row < len; row++)
	{
		for (int col = 0; col < len; col++)
		{
			int sum = 0;
			for (int i = 0; i < row + 1; i++)
			{
				sum = sum + pfx[(i * len) + col];
			}
			sqs[(row * len) + col] = sum;
		}
	}
	for (int i = 0; i < quer; i++)
	{
		xc1 = quers[(i * 4)];
		xc2 = quers[(i * 4) + 1];
		yc1 = quers[(i * 4) + 2];
		yc2 = quers[(i * 4) + 3];
		total = sqs[(yc2 * len) + xc2];
		if (yc1 == 0)
		{
			top = 0;
		}
		else
		{
			top = sqs[((yc1 - 1) * len) + xc2];
		}
		if (xc1 == 0)
		{
			side = 0;
		}
		else
		{
			side = sqs[(yc2 * len) + (xc1 - 1)];
		}
		if (xc1 == 0 || yc1 == 0)
		{
			over = 0;
		}
		else
		{
			over = sqs[((yc1 - 1) * len) + (xc1 - 1)];
		}
		int ans = total - top - side + over;
		printf("%d\n", ans);
	}
}
