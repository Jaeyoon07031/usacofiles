#include <bits/stdc++.h>
using namespace std;

int n, b[100005], ei[100005], gl[100005], hl[100005], fg = INT_MAX, lg = -1, fh = INT_MAX, lh = -1, glc, hlc, pp;
char bs[100005];
set<pair<int, int>> ppl;

int main()
{
	// ONLY ONE LEADER POSSIBLE

	// INPUT PROCESSING

	scanf("%d\n%s", &n, bs);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ei[i]);

		if(bs[i] == 'G')
		{
			b[i] = 0;
		}
		else
		{
			b[i] = 1;
		}

		if (b[i] == 0)
		{
			if (i < fg)
			{
				fg = i;
				continue;
			}
			if (i > lg)
			{
				lg = i;
				continue;
			}
		}
		else
		{
			if (i < fh)
			{
				fh = i;
				continue;
			}
			if (i > lh)
			{
				lh = i;
				continue;
			}
		}
	}

	// FIND POSSIBLE LEADERS FROM FULL LIST

	for (int i = 0; i < n; i++)
	{
		if (i == fh || i == fg)
		{
			if (b[i] == 0)
			{
				if (ei[i] - 1 >= lg)
				{
					//cout << "index " << i << " possible for G leader from full list" << endl;
					gl[glc] = i;
					glc++;
				}
			}
			if (b[i] == 1)
			{
				if (ei[i] - 1 >= lh)
				{
					//cout << "index " << i << " possible for H leader from full list" << endl;
					hl[hlc] = i;
					hlc++;
				}
			}
		}
	}

	// FIND POSSIBLE PAIRS FROM LEADER LIST AND INCLUDE OTHER LEADER

	for (int i = 0; i < hlc; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= hl[i])
			{
				break;
			}
			if (b[j] == 0 && ei[j] - 1 >= hl[i])
			{
				//cout << "index " << j << " could be g leader with h index " << hl[i] << endl;
				ppl.insert(pair<int,int>(j, hl[i]));
			}
			
		}
	}

	for (int i = 0; i < glc; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= gl[i])
			{
				break;
			}
			if (b[j] == 1 && ei[j] - 1 >= gl[i])
			{
				//cout << "index " << j << " could be h leader with g index " << gl[i] << endl;
				ppl.insert(pair<int,int>(gl[i], j));
			}
			
		}
	}

	// MATCH LEADERS WITH OTHER LEADERS

	for (int i = 0; i < hlc; i++)
	{
		for (int j = 0; j < glc; j++)
		{
			// cout << "paring leaders " << gl[j] << " and " << hl[i] << endl;
			ppl.insert(pair<int, int>(gl[j], hl[i]));
		}
	}
	
	printf("%d\n", ppl.size());
}
