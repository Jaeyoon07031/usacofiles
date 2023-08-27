#include <bits/stdc++.h>
using namespace std;

int ans, n;
int visited[100005], arr[100005];

void dfs(int x, int move)
{
    if (visited[x] == -1)
    {
        return;
    }

    if (visited[x] > 0)
    {
        ans = ans + move - visited[x];
        return;
    }

    visited[x] = move;
    dfs(arr[x], move + 1);
    visited[x] = -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, 1);
        }
    }

    cout << ans << endl;
}