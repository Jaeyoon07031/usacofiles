#include <bits/stdc++.h>
using namespace std;

int citn, rodn, rod1, rod2, compn;
int v[100005], comp[100005];
vector<int> rod[100005];

void find(int num, int first)
{
    if (v[num] == 1)
    {
        return;
    }
    if (first == 1)
    {
        comp[compn] = num;
        compn++;
    }
    v[num] = 1;
    for (int i = 0; i < rod[num].size(); i++)
    {
        if (v[rod[num][i]] != 1)
        {
            find(rod[num][i], 0);
        }
    }
}

int main()
{
    scanf("%d%d", &citn, &rodn);
    for (int i = 0; i < rodn; i++)
    {
        scanf("%d%d", &rod1, &rod2);
        rod[rod1].push_back(rod2);
        rod[rod2].push_back(rod1);
    }
    for (int i = 1; i < citn + 1; i++)
    {
        find(i, 1);
    }
    printf("%d\n", compn - 1);
    for (int i = 0; i < compn - 1; i++)
    {
        printf("%d %d\n", comp[0], comp[i + 1]);
    }
}