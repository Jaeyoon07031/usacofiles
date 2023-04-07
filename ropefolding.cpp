#include <bits/stdc++.h>
using namespace std;

int n, l, pp;
int kn[105], rope[10];

int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &kn[i]);
		rope[kn[i]] = 1;
	}
	sort(kn, kn + n);
	for (int i = 1; i < l; i++)
	{
		cout << "folding at " << i << endl;
		bool p = true;
		for (int k = 0; k < n; k++)
		{
			cout << "checking knot " << kn[k] << " at " << i - (kn[k] - i) << endl;
			if (!rope[i - (kn[k] - i)])
			{
				if (i - (kn[k] - i) > 0 && i - (kn[k] - i) <= l)
				{
					cout << "fail" << endl;
					p = false;
				}
			}
		}
		if (p)
		{
			pp++;
		}
	}
	cout << pp << endl;
}