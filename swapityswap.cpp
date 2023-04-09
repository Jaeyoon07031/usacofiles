#include <bits/stdc++.h>
using namespace std;

int n, a1, a2, b1, b2;
long long k;
vector<int> path[105];

int main()
{
    scanf("%d %lld\n%d %d\n%d %d", &n, &k, &a1, &a2, &b1, &b2);

    for (int i = 0; i < n; i++)
    {
        int currentPos = i;
        while(true)
        {
            if (currentPos >= a1 && currentPos <= a2)
            {
                if ((currentPos - a1) < (a2 - currentPos))
                {
                    currentPos = a2 - (currentPos - a1);
                }
                else if ((currentPos - a1) > (a2 - currentPos))
                {
                    currentPos = a1 - (currentPos - a2);
                }
            }
            if (currentPos >= b1 && currentPos <= b2)
            {
                if ((currentPos - b1) < (b2 - currentPos))
                {
                    currentPos = b2 - (currentPos - b1);
                }
                else if ((currentPos - b1) > (b2 - currentPos))
                {
                    currentPos = b1 - (currentPos - b2);
                }
            }

            path[i].push_back(currentPos);

            if (currentPos == i)
            {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((k % path[i].size() == 0))
        {
            cout << path[i][path[i].size() - 1] << endl;
        }
        else
        {
            cout << path[i][k % path[i].size()] << endl;
        }
    }
}