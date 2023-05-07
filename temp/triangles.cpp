#include <bits/stdc++.h>
using namespace std;

int n, lt = -1;
pair<int, int> fence[105];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &fence[i].first, &fence[i].second);
    }


    for (int f1 = 0; f1 < n; f1++)
    {
        for (int f2 = 0; f2 < n; f2++)
        {
            if (f1 == f2)
            {
                continue;
            }
            for (int f3 = 0; f3 < n; f3++)
            {
                if ((f1 == f3 || f2 == f3) || !(fence[f1].first == fence[f2].first || fence[f2].first == fence[f3].first || fence[f1].first == fence[f3].first) ||
                !(fence[f1].second == fence[f2].second || fence[f2].second == fence[f3].second || fence[f1].second == fence[f3].second))
                {
                    continue;
                }

                lt = max((abs(max(max(fence[f1].first, fence[f2].first), fence[f3].first) - min(min(fence[f1].first, fence[f2].first), fence[f3].first)) 
                    * abs(max(max(fence[f1].second, fence[f2].second), fence[f3].second) - min(min(fence[f1].second, fence[f2].second), fence[f3].second))), lt);
            }
        }
    }
    cout << lt << endl;
}