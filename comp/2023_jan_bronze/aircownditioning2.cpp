#include <bits/stdc++.h>
using namespace std;

int activeAC[15], coolingReq[105], range1AC[15], range2AC[15], coolAC[15], costAC[15], cows, ACCount, bestCost = INT_MAX;

void nextPermutation(int digit)
{
    activeAC[digit]++;
    if (activeAC[digit] > 1)
    {
        activeAC[digit] = 0;
        nextPermutation(digit + 1);
    }
}

int main()
{
    scanf("%d%d", &cows, &ACCount);
    for (int i = 0; i < cows; i++)
    {
        int range1, range2, cool;
        scanf("%d%d%d", &range1, &range2, &cool);
        range1--;
        range2--;
        
        for (int j = range1; j < (range2 + 1); j++)
        {
            coolingReq[j] = cool;
        }
    }
    for (int i = 0; i < ACCount; i++)
    {
        int range1, range2, cool, cost;
        scanf("%d%d%d%d", &range1AC[i], &range2AC[i], &coolAC[i], &costAC[i]);
        range1AC[i]--;
        range2AC[i]--;
    }
    for (int perm = 0; perm < pow(2, ACCount) - 1; perm++)
    {
        nextPermutation(0);
        int cost = 0, coolingDone[105] = {0};
        for (int i = 0; i < ACCount; i++)
        {
            if (activeAC[i])
            {
                cost = cost + costAC[i];
                for (int j = range1AC[i]; j < (range2AC[i] + 1); j++)
                {
                    coolingDone[j] = coolingDone[j] + coolAC[i];
                }
            }
        }
        
        bool allCooled = true;

        for (int i = 0; i < 100; i++)
        {
            if (coolingReq[i] > coolingDone[i])
            {
                allCooled = false;
            }
        }

        if (allCooled)
        {
            bestCost = min(bestCost, cost);
        }
    }

    cout << bestCost << endl;
}