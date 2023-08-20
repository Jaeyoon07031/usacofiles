#include <bits/stdc++.h>
using namespace std;

int vn, cn, ccc;
int visited[1005];
vector<int> adj[1005];

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
        c1--;
        c2--;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }

    for (int i = 0; i < vn; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            ccc++;
        }
    }

    cout << ccc << endl;
    
}

