#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tcc;
const ll ARR_SIZE = 10;
//100005

int main()
{
    scanf("%lld", &tcc);
    for (ll tc = 0; tc < tcc; tc++)
    {
        ll n, ans = 0, cows[ARR_SIZE];
        bool possible = true;
        multiset<ll> set;
        scanf("%lld", &n);

        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &cows[i]);
            set.insert(cows[i]);
        }

        while (true)
        {
            bool fed = false;
            ll goal = *set.begin(); 
            for (ll i = 0; i < (n - 1); i++)
            {
                ll adj = max(cows[i], cows[i + 1]) - goal;

                if (adj > min(cows[i], cows[i + 1]))
                {
                    possible = false;
                }
                else if (adj == 0)
                {
                    continue;
                }
                else
                {
                    fed = true;
                    ans = ans + adj;

                    set.erase(cows[i]);
                    set.insert(cows[i] - adj);

                    set.erase(cows[i + 1]);
                    set.insert(cows[i + 1] - adj);

                    cows[i] = cows[i] - adj;
                    cows[i + 1] = cows[i + 1] - adj;
                }
            }

            if (!possible || !fed)
            {
                break;
            }
        }

        if (possible)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}