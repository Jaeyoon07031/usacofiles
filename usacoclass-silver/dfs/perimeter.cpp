#include <bits/stdc++.h>
using namespace std;

int n, p;
int visited[105][105], haybale[105][105];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int r = 0; r < 4; r++)
    {
        if (!(x + dx[r] < 102 && x + dx[r] >= 0 && y + dy[r] < 102 && y + dy[r] >= 0))
        {
            continue;
        }
        if (haybale[x + dx[r]][y + dy[r]])
        {
            p++;
        }
        else if (!visited[x + dx[r]][y + dy[r]])
        {
            dfs(x + dx[r], y + dy[r]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        haybale[x][y] = 1;
    }

    dfs(0, 0);

    cout << p << endl;
}