#include <bits/stdc++.h>
using namespace std;

int k, v, e;
int visited[5][20005], color[5][20005];
vector<int> adj[5][20005];
bool isbipart;

void dfs(int x, int ck, int col)
{
    visited[ck][x] = 1;
    color[ck][x] = col;

    for (auto z : adj[ck][x])
    {
        if (color[ck][z] == col)
        {
            isbipart = false;
        }
        if (!visited[ck][z])
        {
            dfs(z, ck, 3 - col);
        }
    }
}

int main()
{
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &v, &e);
        for (int j = 0; j < e; j++)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            adj[i][v1].push_back(v2);
            adj[i][v2].push_back(v1);
        }

        isbipart = true;
        
        for (int j = 1; j < v + 1; j++)
        {
            if (!visited[i][j])
            {
                dfs(j, i, 1);
            }
        }
        
        if (isbipart)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}