#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int, int>> valid;

int find(int x, int y, int cnt)
{
    if (x == n)
    {
        x = 0;
        y++;
    }
    if (y == n)
    {
        return cnt;
    }

    if (valid.count({x, y}) != 0)
    {   
        vector<pair<int, int>> removal;
        int tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            //figure why tf valid doesnt actually lose elements
            cout << "size before: " << valid.size();
            valid.erase({tx, ty});
            cout << "size after" << valid.size();
            removal.push_back({tx, ty});
            tx++;
            ty--;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            valid.erase({tx, ty});
            removal.push_back({tx, ty});
            tx++;
            ty++;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            valid.erase({tx, ty});
            removal.push_back({tx, ty});
            tx--;
            ty++;
        }
        tx = x, ty = y;
        while (tx >= 0 && tx < n && ty >= 0 && ty < n)
        {
            valid.erase({tx, ty});
            removal.push_back({tx, ty});
            tx--;
            ty--;
        }

        cnt++;
        cnt = max(cnt, find(x + 1, y, cnt));

        for (auto obj : removal)
        {
            valid.insert(obj);
        }

        cnt = max(cnt, find(x + 1, y, cnt));

        return cnt;
    }
    else
    {
        cnt = max(cnt, find(x + 1, y, cnt));
        return cnt;
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

    cout << find(0, 0, 0) << endl;
}