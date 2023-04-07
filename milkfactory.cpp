#include <bits/stdc++.h>
using namespace std;

int n, in[101], out[101];

int main()
{
	freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < (n - 1); i++)
	{
		int ti = 0, to = 0;
		scanf("%d%d", &ti, &to);
		in[to]++;
		out[ti]++;
	}
	
	int ans = -1;

	for (int i = 1; i < n; i++)
	{
		if (out[i] == 0 && ans != -1)
		{
			ans = -1;
			break;
		}
		else if (out[i] == 0)
		{
			ans = i;
		}
	}

	printf("%d", ans);
}
