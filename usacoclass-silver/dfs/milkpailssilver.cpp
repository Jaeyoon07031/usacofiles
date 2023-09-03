#include <bits/stdc++.h>
using namespace std;

int x, y, k, m, ans = INT_MAX;
queue<pair<pair<int, int>, int>> q;
bool chk[105][105];

int main()
{
    scanf("%d%d%d%d", &x, &y, &k, &m);

    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        int a, b, d;
        auto v = q.front();
        q.pop();
        a = v.first.first;
        b = v.first.second;
        d = v.second;
        
        if (d == k)
        {
            break;
        }
        if (a > 0)
        {
            if (y - b >= a)
            {
                if (!chk[0][a + b])
                {
                    chk[0][a + b] = 1;
                    q.push({{0, a + b}, d + 1});
                }
            }
            else
            {
                if (!chk[a - (y - b)][y])
                {
                    chk[a - (y - b)][y] = 1;
                    q.push({{a - (y - b), y}, d + 1});
                }
            }
            if (!chk[0][b])
            {
                chk[0][b] = 1;
                q.push({{0, b}, d + 1});
                if (abs(b - m) < ans)
                {
                    ans = abs(b - m);
                }
            }
        }
        if (b > 0)
        {
            if (x - a >= b)
            {
                if (!chk[a + b][0])
                {
                    chk[a + b][0] = 1;
                    q.push({{a + b, 0}, d + 1});
                }
            }
            else
            {
                if (!chk[x][b - (x - a)])
                {
                    chk[x][b - (x - a)] = 1;
                    q.push({{x, b - (x - a)}, d + 1});
                }
            }
            if (!chk[a][0])
            {
                chk[a][0] = 1;
                q.push({{a, 0}, d + 1});
                if (abs(a - m) < ans)
                {
                    ans = abs(a - m);
                }
            }
        }
        if (a < x)
        {
            if (!chk[x][b])
            {
                chk[x][b] = 1;
                q.push({{x, b}, d + 1});
                if (abs((x + b) - m) < ans)
                {
                    ans = abs((x + b) - m);
                }
            }
        }
        if (b < y)
        {
            if (!chk[a][y])
            {
                chk[a][y] = 1;
                q.push({{a, y}, d + 1});
                if (abs((a + y) - m) < ans)
                {
                    ans = abs((a + y) - m);
                }
            }
        }
    }
    cout << ans << endl;
}
