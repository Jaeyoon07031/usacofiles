#include <bits/stdc++.h>
using namespace std;

int n, s, p = 1, ans, tc;
pair<int, int> loc[(int)1e5+5];

set<pair<int, int>> history;

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &loc[i].first, &loc[i].second);
        if (loc[i].first == 1)
        {
            tc++;
        }
    }

    s--;

    while (true)
    {
        if (loc[s].first == 0)
        {
            if (p < 0)
            {
                p -= loc[s].second;
            }
            else
            {
                p += loc[s].second;
            }

            p *= -1;
        }
        else if (loc[s].first == 1)
        {
            if (abs(p) >= loc[s].second)
            {
                loc[s].first = -1;
                ans++;
                tc--;
                if (tc == 0)
                {
                    break;
                }
            }
        }

        s += p;

        int size = history.size();

        history.insert({s, p});

        if (size == history.size())
        {
            break;
        }

        if (s < 0 || s >= n)
        {
            break;
        }
    }

    cout << ans << endl;
}