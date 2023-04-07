#include <bits/stdc++.h>
using namespace std;

int n, s, bs, s1[105], s2[105], g[105];
bool sh[5];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &s1[i], &s2[i], &g[i]);
	}

	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sh[j] = false;
		}

		sh[i] = true;
		s = 0;
		
		for (int j = 0; j < n; j++)
		{
			bool t = sh[s2[j]];
			sh[s2[j]] = sh[s1[j]];
			sh[s1[j]] = t;
			
			if (sh[g[j]])
			{
				s++;
			}
		}
		
		if (s > bs)
		{
			bs = s;
		}
	}

	printf("%d", bs);
}
