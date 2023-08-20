#include <bits/stdc++.h>
using namespace std;

int n, m, ic;
int visited[55][55], land[55][55];
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 8; dir++)
    {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy] && land[xx][yy])
        {
            dfs(xx, yy);
        }
    }
}

int main()
{
    while(true)
    {
        ic = 0;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
       
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                scanf("%d", &land[x][y]);
                visited[x][y] = 0;
            }
        }

        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (!visited[x][y] && land[x][y])
                {
                    dfs(x, y);
                    ic++;
                }
            }
        }
        cout << ic << endl;
    }
}