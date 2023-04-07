#include <bits/stdc++.h>
using namespace std;

int cows, buses, bsize, h, t, center;
int times[100005]; 

bool check (int maxw)
{
	
	
	int lmaxw = 0;
	int tmaxw = 0;
	int asize = 0;
	int ua = 0;

	for (int i = 0; i < cows; i++)
	{
		if (asize == bsize || (times[i - asize] - times[i]) > maxw)
		{
			tmaxw = times[i - 1] - times[i - asize];
			if (tmaxw > lmaxw)
			{
				lmaxw = tmaxw;
			}
			asize = 0;
			ua++;
		}
		asize++;
	}

	ua++;

	tmaxw = times[cows - 1] - times[cows - asize];
	if (tmaxw > lmaxw)
	{
		lmaxw = tmaxw;
	}

	if (ua > buses || lmaxw > maxw)
	{
		return false;
	}
	return true;
}

int main()
{
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	//cout << "727727";
	cin >> cows >> buses >> bsize;
    for (int i = 0; i < cows; i++)
    {
        cin >> times[i];
    }

    sort(times, times + cows);

	h = 0;
	t = cows - 1;
    center = (h + t) / 2;

	while (true)
	{
		center = (h + t) / 2;
		bool res = check (center);

		if (h == t)
		{
			cout << center << endl;
			break;
		}
		else if (res)
		{
			t = center;
			continue;
		}
		else
		{
			h = center + 1;
			continue;
		}
	}
}