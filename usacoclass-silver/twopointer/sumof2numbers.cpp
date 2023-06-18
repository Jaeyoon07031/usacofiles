#include <bits/stdc++.h>
using namespace std;

int n, x, c, a[1005], bn[1005], h, t;

// not finished

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);

    sort(a, a + n);

    h = (n - 1);
    t = 0;

    while(true)
    {
        if (a[h] + a[t] < x)
        {
            t++;
        }
        else if (a[h] + a[t] > x)
        {
            h--;
        }
        else if (a[h] + a[t] == x)
        {
            c++;
            t++;
        }
        if (t == h)
        {
            break;
        }
    }

    cout << c << endl;
}