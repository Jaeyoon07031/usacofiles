#include <bits/stdc++.h>
using namespace std;

int n, k;
int game[15][105];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> component;

void dfs(int x, int y, int visited[15][105])
{
    visited[x][y] = 1;
    component.push_back({x, y});
    for (int r = 0; r < 4; r++)
    {
        int nx = x + dx[r], ny = y + dy[r];
        if (nx < 0 || nx > 9 || ny < 0 || ny > (n - 1) || visited[nx][ny])
        {
            continue;
        }
        if (game[x][y] == game[nx][ny])
        {
            dfs(nx, ny, visited);
        }
    }
}

void gravity(int x, int y)
{
    while (y < (n - 1))
    {
        if (game[x][y + 1] == 0)
        {
            game[x][y + 1] = game[x][y];
            game[x][y] = 0;
        }
        y++;
    }
}

int main()
{
    //freopen("mooyomooyo.in", "r", stdin);
	//freopen("mooyomooyo.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            int val;
            scanf("%1d", &val);
            game[x][y] = val;
        }
    }

    while (true)
    {
        int visited[15][105] = {0};
        vector<pair<int, int>> toRemove;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                if (!visited[x][y] && game[x][y] != 0)
                {
                    component.clear();
                    dfs(x, y, visited);
                    if (component.size() >= k)
                    {
                        for (auto z : component)
                        {
                            toRemove.push_back(z);
                        }
                    }
                }
            }
        }

        for (auto x : toRemove)
        {
            game[x.first][x.second] = 0;
        }

        if (toRemove.empty())
        {
            break;
        }

        for (int y = (n - 1); y > -1; y--)
        {
            for (int x = 0; x < 10; x++)
            {
                gravity(x, y);
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << game[x][y];
        }
        cout << endl;
    }
}