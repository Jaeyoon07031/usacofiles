#include <bits/stdc++.h>
using namespace std;

int vn, cn;
int visited[255];
vector<int> adj[255];

void dfs(int v)
{
    visited[v] = 1;

    for (auto x : adj[v])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    scanf("%d%d", &vn, &cn);
    for (int i = 0; i < cn; i++)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }

    dfs(1);

    bool misbehave = 0;
    for (int i = 1; i < vn + 1; i++)
    {
        if (!visited[i])
        {
            misbehave = 1;
            cout << i << endl;
        }
    }

    if (!misbehave)
    {
        cout << 0 << endl;
    }
}

