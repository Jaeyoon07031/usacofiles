#include <bits/stdc++.h>
using namespace std;

int n, b, c, p, btc;
int gc[1005], sc[1005], tc[1005];

int main()
{
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &gc[i], &sc[i]);
		tc[i] = gc[i] + sc[i];
	}

	sort(tc, tc + n);

	for (int i = 0; i < n; i++)
	{
		if (c + tc[i] <= b)
		{
			c = c + tc[i];
			p++;
		}
		else
		{
            btc = tc[i];
            for (int j = 0; j < n; j++)
            {
                if ((gc[j] / 2) >= (c + tc[i]) - b && gc[j] + sc[j] <= btc)
                {
                    p++;
                    break;
                }
            }
			break;
		}
	}
	
	cout << p << endl;
}
