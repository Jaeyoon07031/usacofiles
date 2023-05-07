#include <bits/stdc++.h>
using namespace std;

int n, l, h, cc, c[100005];

int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	sort(c, c + n);

	for (int i = 0; i < n; i++)
	{
		if ((n - i) >= c[i])
		{
			h = c[i];
		}	
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i] == h)
		{
			if (cc < l)
			{
				c[i]++;
				cc++;
			}
		}
	}

	sort(c, c + n);

	for (int i = 0; i < n; i++)
	{
		if ((n - i) >= c[i])
		{
			h = c[i];
		}	
	}

	cout << h << endl;
}
