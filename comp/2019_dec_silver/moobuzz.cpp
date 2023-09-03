#include <bits/stdc++.h>
using namespace std;

int n, h, t, center;

bool check(int ce)
{
    if (n > ce - (ce / 3) - (ce / 5) + (ce / 15))
    {
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    t = n;
    h = 2 * n;

    while (true)
	{
		center = (h + t) / 2;
        bool res = check(center);

		if (h == t)
		{
			cout << center << endl;
			break;
		}
		else if (res)
		{
			t = center + 1;
			continue;
		}
		else
		{
			h = center;
			continue;
		}
	}
}