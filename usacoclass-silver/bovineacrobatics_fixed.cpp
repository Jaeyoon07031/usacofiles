#include <bits/stdc++.h>
using namespace std;

#define lld long long

lld n, m, k, ans, bt;

bool compare(pair<lld, lld> p1, pair<lld, lld> p2)
{
    return p1.first > p2.first;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<pair<lld, lld>> cows(n);
    for (lld i = 0; i < n; i++)
    {
        scanf("%lld%lld", &cows[i].first, &cows[i].second);
    }

    sort(cows.begin(), cows.end(), compare);

    lld place = m;
    queue<pair<lld, lld>> qd;
    for (auto cow : cows)
    {
        while (!qd.empty() && qd.front().first - k >= cow.first)
        {
            place += qd.front().second;
            qd.pop(); 
        }

        lld pf = min(place, cow.second);
        if (pf > 0)
        {
            qd.push({cow.first, pf});
            place -= pf;
            ans += pf;
        }
    }

    cout << ans << endl;
}