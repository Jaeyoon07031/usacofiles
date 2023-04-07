#include <bits/stdc++.h>
using namespace std;

long long n, k, h, t;
long long nums[200005];

bool check (long long lim)
{
	long long lk = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + nums[i] > lim)
		{
			lk++;
			sum = 0;
		}
		sum += nums[i];
	}

	lk++;

	if (lk > k)
	{
		return false;
	}
	return true;
}

int main ()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > h)
		{
			h = nums[i];
		}
		t += nums[i];
	}
	
	long long center = (h + t) / 2;

	while (true)
	{
		// cout << h << " " << t << endl;
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
