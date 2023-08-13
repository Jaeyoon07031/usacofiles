#include <bits/stdc++.h>
using namespace std;

int n, breed[100005], listE[100005], pGLeader, pHLeader, glc, hlc, firstG = INT_MAX, lastG = -1, firstH = INT_MAX, lastH = -1;
std::set<pair<int, int>> ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char tmp;
        scanf(" %c", &tmp);
        if (tmp == 'G')
        {
            breed[i] = 0;
            firstG = min(firstG, i);
            lastG = max(lastG, i);
        }
        else
        {
            breed[i] = 1;
            firstH = min(firstH, i);
            lastH = max(lastH, i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &listE[i]);
        listE[i]--;
    }

    if (listE[firstG] >= lastG)
    {
        pGLeader = firstG;
        glc = 1;
    }
    if (listE[firstH] >= lastH)
    {
        pHLeader = firstH;
        hlc = 1;
    }

    for (int i = 0; i < pGLeader; i++)
    {
        if (breed[i] == 1 && listE[i] >= pGLeader)
        {
            ans.insert({pGLeader, i});
        }
    }

    for (int i = 0; i < pHLeader; i++)
    {
        if (breed[i] == 0 && listE[i] >= pHLeader)
        {
            ans.insert({i, pHLeader});
        }
    }

    if (glc && hlc)
    {
        ans.insert({pGLeader, pHLeader});
    }
    cout << ans.size() << endl;
}