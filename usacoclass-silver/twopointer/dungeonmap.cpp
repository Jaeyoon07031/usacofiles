#include <bits/stdc++.h>
#define ll long long
using namespace std;
    
string block[28];
ll n, m, k;

int main()
{
    cin >> n >> m >> k;
    for (ll i = 0; i < k; i++)
    {
        cin >> block[i];
    }
    string s;
    cin >> s;

    ll ret = 0;
    ll sp = m - 2, ep = m - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            for (ll j = m - 2; j >= 0; j--)
            {
                if (block[s[i] - 'A'][j] == 'U')
                {
                    sp = j;
                    break;
                }
                sp = -1;
            }
            ret += ep - sp;
            continue;
        }

        for (ll j = ep; j > sp; j--)
        {
            if (block[s[i] - 'A'][j] == 'U')
            {
                ep = j;
                break;
            }
            ep = sp;
        }

        if (ep == sp)
        {
            break;
        }

        for (ll j = sp; j >= 0; j--)
        {
            if (block[s[i] - 'A'][j] == 'U')
            {
                sp = j;
                break;
            }
            sp = -1;
        }
        ret += ep - sp;
    }

    cout << ret << endl;
}