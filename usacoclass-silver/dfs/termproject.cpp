#include <bits/stdc++.h>
using namespace std;

int tcc, n, ans;
int visited[100005], arr[100005];

void dfs(int v, int dpth)
{
    if (visited[v] == -1)
    {
        return;
    }

    if (visited[v] > 0)
    {
        ans = ans + dpth - visited[v];
        return;
    }

    visited[v] = dpth;
    dfs(arr[v], dpth + 1);
    visited[v] = -1;
}

int main()
{
    scanf("%d", &tcc);
    for (int tc = 0; tc < tcc; tc++)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i]--;
            visited[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, 1);
            }
        }

        cout << n - ans << endl;
    }
}