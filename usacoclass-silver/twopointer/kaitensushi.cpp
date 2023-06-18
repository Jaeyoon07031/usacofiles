#include <bits/stdc++.h>
using namespace std;

int n, d, k, c, v, bv, ae[3005], pl[3000005];

int main()
{
    scanf("%d%d%d%d", &n, &d, &k, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pl[i]);
    }

    for (int i = 0; i < k; i++)
    {
        ae[pl[i]]++;
        if (ae[pl[i]] == 1)
        {
            v++;
        }
    }

    if (ae[c] == 0)
    {
        v++;
        bv = max(bv, v);
        v--;
    }
    else
    {
        bv = max(bv, v);
    }

    for (int i = 0; i < n; i++)
    {
        ae[pl[i]]--;
        if (ae[pl[i]] == 0)
        {
            v--;
        }

        ae[pl[(i + k) % n]]++;
        if (ae[pl[(i + k) % n]] == 1)
        {
            v++;
        }

        if (ae[c] == 0)
        {
            v++;
            bv = max(bv, v);
            v--;
        }
        else
        {
            bv = max(bv, v);
        }
    }

    cout << bv << endl;
}