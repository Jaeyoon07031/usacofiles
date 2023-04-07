#include <bits/stdc++.h>
using namespace std;

long long dc, maxd, hb, csm;
pair<long long, long long> dv[100005];

// CHANGE DV SIZE TO 100005

int main()
{
    scanf("%lld%lld", &dc, &maxd);
    for (int i = 0; i < dc; i++)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        dv[i].first = a;
        dv[i].second = b;
    }

    hb = hb + dv[0].second;
    if (hb > 0)
    {
        csm++;
        hb--;
    }
    

    for (int i = 1; i < dc; i++)
    {
        csm = csm + min((dv[i].first - dv[i - 1].first - 1), hb);
        hb = hb - min((dv[i].first - dv[i - 1].first - 1), hb);

        hb = hb + dv[i].second;

        if (hb > 0)
        {
            csm++;
            hb--;
        }
    }

    csm = csm + min((maxd - dv[dc - 1].first), hb);

    cout << csm << endl;
}