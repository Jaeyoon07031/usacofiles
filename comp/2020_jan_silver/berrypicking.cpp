#include <bits/stdc++.h>
using namespace std;

int trees, baskets, best;
int berries[1005];

int main()
{
    scanf("%d%d", &trees, &baskets);
    for (int i = 0; i < trees; i++)
    {
        scanf("%d", &berries[i]);
    }

    sort(berries, berries + trees, greater<int>());

    for (int goal = 1; goal <= berries[0]; goal++)
    {
        int full = 0;
        for (int i = 0; i < trees; i++)
        {
            full += berries[i] / goal;
        }

        if (full < baskets / 2) { break; }

        if (full >= baskets)
        {
            best = max(best, goal * (baskets / 2));
            continue;
        }

        vector<int> newBaskets;
        for (int i = 0; i < trees; i++)
        {
            int index = newBaskets.size();

            for (int j = 0; j < berries[i] / goal; j++)
            {
                newBaskets.push_back(goal);
            }
            for (int j = 0; j < berries[i] % goal; j++)
            {
                newBaskets[index + j]++;
            }
        }

        sort(newBaskets.begin(), newBaskets.end(), greater<int>());

        int total = 0;
        for (int i = (baskets / 2); i < baskets; i++)
        {
            total = total + newBaskets[i];
        }

        best = max (best, total);
    }

    cout << best;
}
