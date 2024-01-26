#include <bits/stdc++.h>
#define lld long long
using namespace std;

lld n, h, t, center;

int check(lld ce)
{
	lld chk = ce - (ce / 3) - (ce / 5) + (ce / 15);

    if (n < chk)
    {
        return true;
    }
	else if (n > chk)
	{
		return false;
	}
	else
	{
		if ((ce % 3) == 0 || (ce % 5) == 0)
		{
			ce--;
		}
		if ((ce % 3) == 0 || (ce % 5) == 0)
		{
			ce--;
		}
		cout << ce << endl;
		return 2;
	}
}

int main()
{
    scanf("%lld", &n);
    t = n;
    h = 2 * n;

    while (true)
	{
		center = (h + t) / 2;
        lld res = check(center);

		if(res == 1)
		{
			h = center;
		}
		else if (res == 0)
		{
			t = center;
		}
		else
		{
			return 0;
		}
	}
}