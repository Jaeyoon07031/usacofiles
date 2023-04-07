#include <bits/stdc++.h>
using namespace std;

int dc, sc, expc, pc;
int dr[25], expr[25][25];

void solve()
{
    bool p = false;
    int nc[25];

    for (int i = 0; i < 25; i++)
    {
        nc[i] = 0;
    }

    for (int i = 0; i < dc; i++)
    {
        nc[dr[i]]++;
    }

    for (int i = 0; i < expc; i++)
    {
        bool expp = true;
        for (int j = 1; j < sc + 1; j++)
        {
            if (!(nc[j] >= expr[i][j]))
            {
                expp = false;
            }
        }
        if (expp)
        {
            p = true;
            break;
        }
    }

    if (p)
    {
        pc++;
    }
}

bool increment(int n)
{
    if (dc - n < 0)
    {
        return true;
    }
    dr[dc - n]++;
    if (dr[dc - n] > sc)
    {
        dr[dc - n] = 1;
        increment(n + 1);
    }

    return false;
}

int main()
{
    scanf("%d%d%d\n", &dc, &sc, &expc);

    for (int i = 0; i < 25; i++)
    {
        dr[i] = 1;
    }

    for (int i = 0; i < expc; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int n1 = -1, n2 = -1;
            char c;
            scanf("%dx%d%c", &n1, &n2, &c);
            expr[i][n2] = n1;
            if (c != '+')
            {
                break;
            }
        }
    }

    for (int ic = 0; ic < pow(sc, dc); ic++)
    {
        increment(1);
        solve();
    }

    cout << pc << endl;

}