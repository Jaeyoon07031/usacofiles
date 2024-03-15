#include <bits/stdc++.h>
using namespace std;

#define lld long long

lld n, ans;
lld err[(int)2e5+5];

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &err[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (err[i] == 0)
        {
            continue;
        }

        lld L, cnt;

        if (i == 0)
        {
            L = n - i + abs(err[i]) - 1;
            cnt = 1;
        }
        else
        {
            L = n - i;
            cnt = abs(err[i]);
        }

        for (int j = i + 1; j < n; j++)
        {
             if (err[i] < 0)
            {
                err[j] += (L - (n - j - 1)) * cnt;
            }
            else
            {
                err[j] -= (L - (n - j - 1)) * cnt;
            }

        }

        ans += cnt;
    }

    cout << ans << endl;
}