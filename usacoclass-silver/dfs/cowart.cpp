#include <bits/stdc++.h>
using namespace std;

int n, hac, cac, paint[105][105], visited[105][105], cvisited[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && !visited[xx][yy] && paint[x][y] == paint[xx][yy])
        {
            dfs(xx, yy);
        }
    }
}

void cowdfs(int x, int y)
{
    cvisited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && !cvisited[xx][yy] && (((paint[x][y] != 2) && (paint[xx][yy] != 2)) || ((paint[x][y] == 2) && (paint[xx][yy] == 2))))
        {
            cowdfs(xx, yy);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            char tc;
            scanf(" %c", &tc);
            if (tc == 'R')
            {
                paint[x][y] = 0;
            }
            else if (tc == 'G')
            {
                paint[x][y] = 1;
            }
            else
            {
                paint[x][y] = 2;
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (!visited[x][y])
            {
                dfs(x, y);
                hac++;
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (!cvisited[x][y])
            {
                cowdfs(x, y);
                cac++;
            }
        }
    }

    cout << hac << ' ' << cac << endl;
}