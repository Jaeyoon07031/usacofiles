#include <bits/stdc++.h>
using namespace std;

int n, m, bmc;
char bch[55][55];

bool validPos(int x, int y)
{
    if (x >= 0 && x <= (m - 1) && y >= 0 && y <= (n - 1))
    {
        return true;
    }
    return false;
}

void solve(char ms, char os)
{
    int bc = 0;
   
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (bch[x][y] != ms)
            {
                continue;
            }
            
            if (validPos(x, y - 1) && validPos(x, y - 2))
            {
                if (bch[x][y - 1] == os && bch[x][y - 2] == os)
                {
                    bc++;
                }
            }
            if (validPos(x, y + 1) && validPos(x, y + 2))
            {
                if (bch[x][y + 1] == os && bch[x][y + 2] == os)
                {
                    bc++;
                }
            }
            if (validPos(x - 1, y) && validPos(x - 2, y))
            {
                if (bch[x - 1][y] == os && bch[x - 2][y] == os)
                {
                    bc++;
                }
            }
            if (validPos(x + 1, y) && validPos(x + 2, y))
            {
                if (bch[x + 1][y] == os && bch[x + 2][y] == os)
                {
                    bc++;
                }
            }
            if (validPos(x + 1, y + 1) && validPos(x + 2, y + 2))
            {
                if (bch[x + 1][y + 1] == os && bch[x + 2][y + 2] == os)
                {
                    bc++;
                }
            }
            if (validPos(x - 1, y - 1) && validPos(x - 2, y - 2))
            {
                if (bch[x - 1][y - 1] == os && bch[x - 2][y - 2] == os)
                {
                    bc++;
                }
            }
            if (validPos(x + 1, y - 1) && validPos(x + 2, y - 2))
            {
                if (bch[x + 1][y - 1] == os && bch[x + 2][y - 2] == os)
                {
                    bc++;
                }
            }
            if (validPos(x - 1, y + 1) && validPos(x - 2, y + 2))
            {
                if (bch[x - 1][y + 1] == os && bch[x - 2][y + 2] == os)
                {
                    bc++;
                }
            }
        }
    }
    
    if (bc > bmc)
    {
        bmc = bc;
    }
}

int main()
{
    scanf("%d%d\n", &m, &n);
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n + 1; x++)
        {
            char c;
            scanf("%c", &c);
            if (c == '\n')
            {
                continue;
            }
            bch[y][x] = c;
        }
    }

    for (int c1 = 65; c1 < 91; c1++)
    {
        for (int c2 = 65; c2 < 91; c2++)
        {
            if (int('M') == c1 || int('O' == c2) || c1 == c2)
            {
                continue;
            }
            solve(char(c1), char(c2));
        }
    }

    cout << bmc << endl;
}