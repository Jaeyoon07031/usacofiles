#include <bits/stdc++.h>
using namespace std;

long long wdc, bp, p;
long long wd[100005];

int main()
{
    scanf("%lld%lld", &wdc, &bp);
    for (int i = 0; i < wdc; i++)
    {
        scanf("%lld", &wd[i]);
    }

    p = 1 + bp;

    for (int i = 1; i < wdc; i++)
    {
        p = p + min((1 + bp), (wd[i] - wd[i - 1]));
    }

    cout << p << endl;
}