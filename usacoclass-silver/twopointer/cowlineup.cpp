#include <bits/stdc++.h>
using namespace std;

int n, uc, bs = INT_MAX, front = -1, back;
pair<int, int> cows[50005];
map<int, int> cnt;

bool compare_pair(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &cows[i].first, &cows[i].second);
        cnt[cows[i].second] = 1;
    }
    
    uc = cnt.size();
    cnt.clear();
    sort(cows, cows + n, compare_pair);

    while(front < (n - 1))
    {
        if (cnt.size() < uc)
        {
            front++;
            cnt[cows[front].second]++;
        }
        else if (cnt.size() >= uc)
        {
            bs = min(bs, cows[front].first - cows[back].first);
            cnt[cows[back].second]--;
            if (cnt[cows[back].second] == 0)
            {
                cnt.erase(cows[back].second);
            }
            back++;
        }
    }

    while(cnt.size() >= uc && back < n)
    {
        bs = min(bs, cows[front].first - cows[back].first);
        cnt[cows[back].second]--;
        if (cnt[cows[back].second] == 0)
        {
            cnt.erase(cows[back].second);
        }
        back++;
    }

    cout << bs << endl;
}