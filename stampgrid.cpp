#include <bits/stdc++.h>
using namespace std;

int tcc, gn, sn, gg[25][25], s[25][25];

auto rotate(int in[25][25])
{
    int nn = sn;
    int mm = sn;
    int out[25][25] = new int[mm][nn];

    for (int i=0; i < nn; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            out[j][nn - 1 - i] = in[i][j];
        } 
    }
    
    return out;
}

bool validPlacement(int xx, int yy, int bx, int by)
{
    if (bx - (sn - (sn - xx)) >= 0 &&
    bx + (sn - xx + 1) > gn &&
    by - (sn - (sn - yy)) >= 0 &&
    by + (sn - yy + 1) > gn)
    {
        return true;
    }
    return false;
}

bool validStamping(int xx, int yy, int bx, int by, int ort)
{
    int os[25][25];
    if (ort == 0)
    {
        for (int osy = 0; osy < sn; osy++)
        {
            for (int osx = 0; osx < sn; osx++)
            {
                os[osx][osy] = s[osx][osy];
            }
        }
    }
    else if (ort == 1)
    {
        os = rotate(s);
    }
    else if (ort == 2)
    {
        os = rotate(s);
        os = rotate(os);
    }
    else
    {
        os = rotate(s);
        os = rotate(os);
        os = rotate(os);
    }

    for (int osy = 0; osy < sn; osy++)
    {
        for (int osx = 0; osx < sn; osx++)
        {
            if ((gg[osx + bx + xx][osy + by + yy] == 0 && os[osx][osy] == 1) ||
            (gg[osx + bx + xx][osy + by + yy] == 1 && os[osx][osy] == 0))
            {
                return false;
            }
            else if ((gg[osx + bx + xx][osy + by + yy] == 1 && os[osx][osy] == 1))
            {
                gg[osx + bx + xx][osy + by + yy] = 2;
            }
        }
    }
    return true;
}

void checkPossible()
{
    for (int y = 0; y < gn; y++)
    {
        for (int x = 0; x < gn; x++)
        {
            if (gg[x][y] == 1)
            {
                bool p = false;
                for (int sy = 0; sy < sn; sy++)
                {
                    for (int sx = 0; sx < sn; sx++)
                    {
                        for (int orti = 0; orti < 4; orti++)
                        {
                            if (validPlacement(sx, sy, x, y) && validStamping(sx, sy, x, y, orti))
                            {
                                p = true;
                            }
                        }
                        
                    }
                }
                if (!p)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{
    scanf("%d", &tcc);
    for (int tc = 0; tc < tcc; tc++)
    {
        scanf("%d\n", gn);
        for (int y = 0; y < gn; y++)
        {
            for (int x = 0; x < gn + 1; x++)
            {
                char ch;
                scanf('%c', &ch);
                if (x != gn)
                {
                    if (ch == '*')
                    {
                        gg[x][y] = 1;
                    }
                    else
                    {
                        gg[x][y] = 0;
                    }
                }
            }
        }

        scanf("%d\n", sn);
        for (int y = 0; y < sn; y++)
        {
            for (int x = 0; x < sn + 1; x++)
            {
                char ch;
                scanf('%c', &ch);
                if (x != sn)
                {
                    if (ch == '*')
                    {
                        s[x][y] = 1;
                    }
                    else
                    {
                        s[x][y] = 0;
                    }
                }
            }
        }

        checkPossible();
    }
}