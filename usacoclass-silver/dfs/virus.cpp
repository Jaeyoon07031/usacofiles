#include <bits/stdc++.h>
using namespace std;

int vn, cn, infcount;
int visited[105];
vector<int> adj[105];

void dfs(int v)
{
    if (v != 1)
    {
        infcount++;
    }

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

    cout << infcount << endl;
}
