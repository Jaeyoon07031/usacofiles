#include <bits/stdc++.h>
using namespace std;

int f[1000005], n[105], cn, x;

int main()
{
    fill_n(f, 1000005, INT_MAX);
    scanf("%d%d", &cn, &x);
    for (int i = 0; i < cn; i++)
    {
        scanf("%d", &n[i]);
        f[n[i]] = 1;
    }

    for (int i = 0; i < x + 5; i++)
    {
        if (f[i] != 1)
        {
            int min = INT_MAX;
            for (int j = 0; j < cn; j++)
            {
                if ((i - n[j]) >= 0 && abs(f[i - n[j]]) < min)
                {
                    min = f[i - n[j]];
                }
            }
            if (min != INT_MAX)
            {
                f[i] = min + 1;
            }
            else
            {
                f[i] = INT_MAX;
            }
            
        }
    }

    if (f[x] == INT_MAX)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << f[x] << endl;
}