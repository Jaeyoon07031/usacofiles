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
    vector<pair<lld, lld>> cow(n);
    for (lld i = 0; i < n; i++)
    {
        scanf("%lld%lld", &cow[i].first, &cow[i].second);
    }

    sort(cow.begin(), cow.end(), compare);

    while (bt < m)
    {
        vector<lld> cows;
        lld cnt = 2^63, below = 2^63, i = 0;
        for (auto pair : cow)
        {
            if (cows.empty() || below - pair.first >= k)
            {
                cows.push_back(i);
                below = pair.first;
                cnt = min(cnt, pair.second);
            }
            i++;
        }

        cnt = min(cnt, m - bt);

        lld erased = 0;
        for (lld q : cows)
        {
            cow[q - erased].second -= cnt;
            if (cow[q - erased].second == 0)
            {
                cow.erase(cow.begin() + q - erased);
                erased++;
            }
        }

        ans += cnt * cows.size();
        bt += cnt;
    }

    cout << ans << endl;
}