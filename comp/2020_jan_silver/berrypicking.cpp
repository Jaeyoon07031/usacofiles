#include <bits/stdc++.h>
using namespace std;

int trees, baskets, best;
int berries[1005];

int main()
{
    //freopen("berries.in","r",stdin);
	//freopen("berries.out","w",stdout);

    scanf("%d%d", &trees, &baskets);
    for (int i = 0; i < trees; i++)
    {
        scanf("%d", &berries[i]);
    }

    sort(berries, berries + trees, greater<int>());

    for (int goal = berries[0]; goal > 0; goal--)
    {
        vector<int> newBaskets;
        for (int i = 0; i < trees; i++)
        {
            int index = newBaskets.size();
            int begin = index;

            if (berries[i] < goal)
            {
                newBaskets.push_back(berries[i]);
            }
            else
            {
                for (int j = 0; j < (berries[i] / goal); j++)
                {
                    newBaskets.push_back(goal);
                }
                int end = newBaskets.size() - 1;
                
                int remainder = berries[i] % goal;
                
                while (remainder != 0)
                {
                    newBaskets[index]++;
                    remainder--;

                    index++;
                    if (index > end)
                    {
                        index = begin;
                    }
                }
            }
        }

        sort(newBaskets.begin(), newBaskets.end(), greater<int>());

        int total = 0;
        for (int i = (baskets / 2); i < baskets; i++)
        {
            total = total + newBaskets[i];
        }

        best = max(best, total);
    }

    cout << best;
}