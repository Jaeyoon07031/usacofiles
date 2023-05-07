#include <bits/stdc++.h>
using namespace std;

int n, bc = INT_MAX, q[30005], o[30005], t[30005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    if (q[0] == 1)
    {
        o[0] = 1;
    }
    else
    {
        t[0] = 1;
    }
    
    for (int i = 1; i < n; i++)
    {
        if (q[i] == 1)
        {
            o[i] = o[i - 1] + 1;
            t[i] = t[i - 1];
        }
        else
        {
            o[i] = o[i - 1];
            t[i] = t[i - 1] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int c = t[i] + o[n - 1] - o[i] ;
        if (q[i] == 2)
        {
            c--;
        }
        bc = min(c, bc);
    }

    cout << bc << endl;
}