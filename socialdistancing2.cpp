#include <bits/stdc++.h>
using namespace std;

struct cow
{
    int index;
    bool infected;
};

bool cowCompare(cow cow1, cow cow2)
{
    return cow1.index < cow2.index;
}

int n, minct, infcowct, maxR = INT_MAX;
cow cows[1005], infCows[1005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        cows[i].index = t1;
        cows[i].infected = t2;

        if (t2)
        {
            infCows[infcowct].index = t1;
            infCows[infcowct].infected = t2;
            infcowct++;
        }
    }

    sort(cows, cows + n, cowCompare);
    sort(infCows, infCows + infcowct, cowCompare);

    for (int i = 0; i < n; i++)
    {
        if (cows[i].infected)
        {
            continue;
        }

       // cout << "cow " << i << " is not infected" << endl;

        if (i != 0 && cows[i - 1].infected)
        {
            maxR = min(maxR, cows[i].index - cows[i - 1].index);
        }
        if (i != (n - 1) && cows[i + 1].infected)
        {
            maxR = min(maxR, cows[i + 1].index - cows[i].index);
        }

        //cout << "maxR is now " << maxR << endl;
    }

    maxR--;
    minct++;

    for (int i = 1; i < infcowct; i++)
    {
        //cout << "this cow at " << infCows[i].index << " and left cow at " << infCows[i - 1].index << endl;
        //cout << "difference is " << infCows[i].index - infCows[i - 1].index << " and maxR is " << maxR << endl;
        if (infCows[i].index - infCows[i - 1].index > maxR)
        {
            //cout << "one more minimum" << endl;
            minct++;
        }
    }

    cout << minct << endl;
}