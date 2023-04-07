#include <bits/stdc++.h>
using namespace std;

int n, s, a, d;
int p[10005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        s = s + p[i];
    }

    a = s / n;

    for (int i = 0; i < n; i++)
    {
        d = d + abs(p[i] - a);
    }

    cout << d / 2 << endl;
}