#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int pfx[1005][1005];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            scanf("%d", &t);
            if (i != 0)
            {
                t = t + pfx[i - 1][j];
            }
            if (j != 0)
            {
                t = t + pfx[i][j - 1];
            }
            if (i != 0 && j != 0)
            {
                t = t - pfx[i - 1][j - 1];
            }
            pfx[i][j] = t;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int n1, n2, m1, m2, sum;
        scanf("%d%d%d%d", &n1, &m1, &n2, &m2);

        n1 = n1 - 1;
        m1 = m1 - 1;
        n2 = n2 - 1;
        m2 = m2 - 1;

        sum = pfx[n2][m2];
        if (n1 != 0)
        {
            sum = sum - pfx[n1 - 1][m2];
        }
        if (m1 != 0)
        {
            sum = sum - pfx[n2][m1 - 1];
        }
        if (n1 != 0 && m1 != 0)
        {
            sum = sum + pfx[n1 - 1][m1 - 1];
        }

        cout << sum / ((m2 - m1 + 1) * (n2 - n1 + 1)) << endl;
    }
}