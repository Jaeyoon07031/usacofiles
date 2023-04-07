#include <bits/stdc++.h>
using namespace std;

int hei, wth, bdiff, tmp, ckptn, ckptfn, h, t, center;
int selv = 1.1e+9;
int belv = -1;
int elv[250005], v[250005], ckpt[250005];

void reset()
{
	ckptfn = 0;
	for (int i = 0; i < hei * wth + 5; i++)
	{
		v[i] = 0;
	}
}

void find(int num, int diff)
{
	//cout << "inside " << num << endl;
	if (v[num] == 1)
	{
		//cout << "already visited" << endl;
		return;
	}
	for (int i = 0; i < ckptn; i++)
	{
		if (num == ckpt[i])
		{
			//cout << "is checkpoint" << endl;
			ckptfn++;
		}
	}
	v[num] = 1;
	if (num > wth - 1 && abs(elv[num] - elv[num - wth]) <= diff)
	{
		//cout << "going up" << endl;
		//cout << "elv difference is " << abs(elv[num] - elv[num - wth]) << endl;
		if (v[num - wth] != 1)
        {
            find(num - wth, diff);
        }
	}
	if (num % wth != wth - 1 && abs(elv[num] - elv[num + 1]) <= diff)
	{
		//cout << "going right" << endl;
		//cout << "elv difference is " << abs(elv[num] - elv[num + 1]) << endl;
		if (v[num + 1] != 1)
		{
			find(num + 1, diff);
		}
	}
	if (num + wth < wth * hei && abs(elv[num] - elv[num + wth]) <= diff)
	{
		//cout << "going down" << endl;
		//cout << "elv difference is " << abs(elv[num] - elv[num + wth]) << endl;
		if (v[num + wth] != 1)
		{
			find(num + wth, diff);
		}
	}
	if (num % wth != 0 && abs(elv[num] - elv[num - 1]) <= diff)
	{
		//cout << "going left" << endl;
		//cout << "elv difference is " << abs(elv[num] - elv[num - 1])<< endl;
		if (v[num - 1] != 1)
		{
			find(num - 1, diff);
		}
	}
}

bool dfs(int diff)
{
	reset();
	find(ckpt[0], diff);
	if (ckptfn == ckptn)
	{
		return true;
	}
	return false;
}

int main()
{
	freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
	
	scanf("%d%d", &hei, &wth);
	for (int i = 0; i < hei * wth; i++)
	{
		scanf("%d", &elv[i]);
		if (elv[i] < selv)
		{
			selv = elv[i];
		}
		if (elv[i] > belv)
		{
			belv = elv[i];
		}
	}
	for (int i = 0; i < hei * wth; i++)
	{
		scanf("%d", &tmp);
		if (tmp == 1)
		{
			ckpt[ckptn] = i;
			ckptn++;
		}
	}
	
	if (ckptn == 0)
	{
		cout << 0;
		return 0;
	}

	for(int i = 0; i < 100; i++)
	{
		center = (belv + selv) / 2;
		//cout << "belv and selv are " << belv << " " << selv << endl;
		//cout << "checking for " << center << endl;
		bool res = dfs(center);
		//cout << "got " << res << endl;

		if (belv == selv)
		{
			cout << center << endl;
			return 0;
		}
		else if (res)
		{
			belv = center;
			continue;
		}
		else
		{
			selv = center + 1;
			continue;
		}
	}
}