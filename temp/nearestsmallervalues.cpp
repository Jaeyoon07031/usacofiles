#include <bits/stdc++.h>
using namespace std;

int ipt[200001], stk[200001], rst[200001];
int t = 0;

int main()
{
	int n;
	cin >> n;

	stk[0] = 200000;

	for (int i = 0; i < n; i++)
	{
		cin >> ipt[i];
	}

	for (int i = 0; i < n; i++)
	{
		while (ipt[stk[t]] >= ipt[i])
		{
			t--;
		}

		t++;
		stk[t] = i;
		rst[i] = stk[t - 1];
	}

	for (int i = 0; i < n; i++)
	{
		cout << (rst[i] + 1) % 200001 << " ";
	}
}
