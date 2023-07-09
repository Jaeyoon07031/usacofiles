#include <bits/stdc++.h>
using namespace std;

int n, m, best = INT_MAX, sumW[55], sumB[55], sumR[55];
char flag[55][55];

//sumW[55], sumB[55], sumR[55];
//flag[55][55];

//sumW[6], sumB[6], sumR[6];
//flag[6][6];

int main()
{
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int wc = 0, bc = 0, rc = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &flag[i][j]);
            if (flag[i][j] == 'W')
            {
                wc++;
            }
            else if (flag[i][j] == 'B')
            {
                bc++;
            }
            else
            {
                rc++;
            }
        }
        if (i != (n - 1))
        {
            scanf("\n");
        }
        sumW[i] = m - wc;
        sumB[i] = m - bc;
        sumR[i] = m - rc;

        if (i != 0)
        {
            sumW[i] = sumW[i] + sumW[i - 1];
            sumB[i] = sumB[i] + sumB[i - 1];
            sumR[i] = sumR[i] + sumR[i - 1];
        }
    }

    for (int h = 1; h < (n - 1); h++)
    {
        for (int k = h; k < (n - 1); k++)
        {
            int cost = sumW[h - 1] + sumB[k] - sumB[h - 1] + sumR[n - 1] - sumR[k];
            /*cout << "range " << h << ", " << k << endl;
            cout << "cost from white is " << sumW[h - 1] << endl;
            cout << "cost from blue is " << sumB[k] - sumB[h - 1] << endl;
            cout << "cost from red is " << sumR[n - 1] - sumR[k] << endl;*/
            best = min(best, cost);
        }
    }

    cout << best << endl;
}