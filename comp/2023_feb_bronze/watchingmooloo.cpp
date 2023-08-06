#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, sum, days[100005];

int main()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &days[i]);
    }

    sum = 1 + k;

    for (ll i = 1; i < n; i++)
    {
        sum = sum + min((1 + k), (days[i] - days[i - 1]));
    }

    cout << sum << endl;
}