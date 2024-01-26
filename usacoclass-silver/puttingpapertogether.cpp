#include <bits/stdc++.h>
using namespace std;

array<array<int, 10>, 10> paper;

struct rmd{
    int rm1 = 5;
    int rm2 = 5;
    int rm3 = 5;
    int rm4 = 5;
    int rm5 = 5;
};

int find(rmd count, int score, int x, int y)
{
    if (x == 10)
    {
        x = 0;
        y++;
    }
    if (y == 10)
    {
        bool equals = true;
        for (int fy = 0; fy < 10; fy++)
        {
            for (int fx = 0; fx < 10; fx++)
            {
                if (paper[fx][fy] != 0)
                {
                    equals = false;
                    break;
                }
            }
            if (!equals)
            {
                break;
            }
        }
        
        if (equals)
        {
            score = (5 - count.rm1) + (5 - count.rm2) + (5 - count.rm3) + (5 - count.rm4) + (5 - count.rm5);
            return score;
        }
        else
        {
            return INT_MAX;
        }
        
    }

    if (paper[x][y] != 1)
    {
        find(count, score, x++, y);
    }

    bool work5 = true;
    if (x < 5 && y < 5)
    {
        for (int ay = 0; ay < 4; ay++)
        {
            for (int ax = 0; ax < 4; ax++)
            {
                if (paper[x + ax][y + ay] != 1)
                {
                    work5 = false;
                    break;
                }
            }
            if (!work5)
            {
                break;
            }
        }
    }
    else
    {
        work5 = false;
    }
    
    bool work4 = true;
    if (x < 6 && y < 6)
    {
        for (int ay = 0; ay < 3; ay++)
        {
            for (int ax = 0; ax < 3; ax++)
            {
                if (paper[x + ax][y + ay] != 1)
                {
                    work4 = false;
                    break;
                }
            }
            if (!work4)
            {
                break;
            }
        }
    }
    else
    {
        work4 = false;
    }
    
    bool work3 = true;
    if (x < 7 && y < 7)
    {
        for (int ay = 0; ay < 2; ay++)
        {
            for (int ax = 0; ax < 2; ax++)
            {
                if (paper[x + ax][y + ay] != 1)
                {
                    work3 = false;
                    break;
                }
            }
            if (!work3)
            {
                break;
            }
        }
    }
    else
    {
        work3 = false;
    }
    
    bool work2 = true;
    if (x < 8 && y < 8)
    {
        for (int ay = 0; ay < 1; ay++)
        {
            for (int ax = 0; ax < 1; ax++)
            {
                if (paper[x + ax][y + ay] != 1)
                {
                    work2 = false;
                    break;
                }
            }
            if (!work2)
            {
                break;
            }
        }
    }
    else
    {
        work2 = false;
    }
    

    if (work5 && count.rm5 != 0)
    {
        for (int ay = 0; ay < 4; ay++)
        {
            for (int ax = 0; ax < 4; ax++)
            {
                paper[x + ax][y + ay] = 0;
            }
        }

        count.rm5--;
        score = min(score, find(count, score, x++, y));
        count.rm5++;

        for (int ay = 0; ay < 4; ay++)
        {
            for (int ax = 0; ax < 4; ax++)
            {
                paper[x + ax][y + ay] = 1;
            }
        }
    }

    if (work4 && count.rm4 != 0)
    {
        for (int ay = 0; ay < 3; ay++)
        {
            for (int ax = 0; ax < 3; ax++)
            {
                paper[x + ax][y + ay] = 0;
            }
        }

        count.rm4--;
        score = min(score, find(count, score, x++, y));
        count.rm4++;

        for (int ay = 0; ay < 3; ay++)
        {
            for (int ax = 0; ax < 3; ax++)
            {
                paper[x + ax][y + ay] = 1;
            }
        }
    }

    if (work3 && count.rm3 != 0)
    {
        for (int ay = 0; ay < 2; ay++)
        {
            for (int ax = 0; ax < 2; ax++)
            {
                paper[x + ax][y + ay] = 0;
            }
        }

        count.rm3--;
        score = min(score, find(count, score, x++, y));
        count.rm3++;

        for (int ay = 0; ay < 2; ay++)
        {
            for (int ax = 0; ax < 2; ax++)
            {
                paper[x + ax][y + ay] = 1;
            }
        }
    }

    if (work2 && count.rm2 != 0)
    {
        for (int ay = 0; ay < 1; ay++)
        {
            for (int ax = 0; ax < 1; ax++)
            {
                paper[x + ax][y + ay] = 0;
            }
        }

        count.rm2--;
        score = min(score, find(count, score, x++, y));
        count.rm2++;

        for (int ay = 0; ay < 1; ay++)
        {
            for (int ax = 0; ax < 1; ax++)
            {
                paper[x + ax][y + ay] = 1;
            }
        }
    }

    if (count.rm1 != 0)
    {
        paper[x][y] = 0;

        count.rm1--;
        score = min(score, find(count, score, x++, y));
        count.rm1++;

        paper[x][y] = 1;
    }
}


int main()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            scanf("%d", &paper[x][y]);
        }
    }

    rmd strct;

    int ans = find(strct, INT_MAX, 0, 0);

    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}