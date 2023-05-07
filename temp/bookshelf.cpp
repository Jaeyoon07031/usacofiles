#include <bits/stdc++.h>
using namespace std;

int n, g, ch;
int h[20005];

int main()
{
    scanf("%d%d", &n, &g);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    sort(h, h + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        ch = ch + h[i];
        if (ch >= g)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}