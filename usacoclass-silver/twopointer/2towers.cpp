#include <bits/stdc++.h>
using namespace std;

int n, h, t, dist[50005], pfx[50005], tdist, mdist;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dist[i]);
        pfx[i + 1] = pfx[i] + dist[i];
        tdist = tdist + dist[i];
    }

    for (t = 0; t < n; t++)
    {
        for (h = t + 1; h < n; h++)
        {
            mdist = max(mdist, min((pfx[h] - pfx[t]), (tdist - (pfx[h] - pfx[t]))));
        }
    }

    cout << mdist << endl;
}