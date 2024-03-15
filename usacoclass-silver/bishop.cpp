#include <bits/stdc++.h>
using namespace std;

int n, best;
set<pair<int, int>> valid;

void find(int x, int y, int cnt)
{
    if (x == n)
    {
        x = 0;
        y++;
    }
    if (y == n)
    {
        best = max(best, cnt);
        return;
    }

    if (valid.empty())
    {
        best = max(best, cnt);
        return;
    }

    if (valid.size() + cnt <= best)
    {
        return;
    }

    if (valid.count({x, y}) != 0)
    {   
        vector<pair<int, int>> removal;
        int tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            if (valid.erase({tx, ty}) != 0)
            {
                removal.push_back({tx, ty});
            }
            tx++;
            ty--;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            if (valid.erase({tx, ty}) != 0)
            {
                removal.push_back({tx, ty});
            }
            tx++;
            ty++;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            if (valid.erase({tx, ty}) != 0)
            {
                removal.push_back({tx, ty});
            }
            tx--;
            ty++;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            if (valid.erase({tx, ty}) != 0)
            {
                removal.push_back({tx, ty});
            }
            tx--;
            ty--;
        }

        find(x + 1, y, cnt + 1);

        for (auto obj : removal)
        {
            valid.insert(obj);
        }

        find(x + 1, y, cnt);

        return;
    }
    else
    {
        find(x + 1, y, cnt);
        return;
    }
}

int main()
{
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp)
            {
                valid.insert({x, y});
            }
        }
    }

    find(0, 0, 0);

    cout << best << endl;
}