#include <bits/stdc++.h>
using namespace std;

int sc, cc, res;
int cowRank[15][25];

int main()
{
    scanf("%d%d", &sc, &cc);
    for (int s = 0; s < sc; s++)
    {
        for (int c = 0; c < cc; c++)
        {
            int t;
            scanf("%d", &t);
            cowRank[s][t - 1] = c;
        }
    }

    for (int c = 0; c < cc; c++)
    {
        for (int oc = 0; oc < cc; oc++)
        {
            if (oc == c)
            {
                continue;
            }

            bool consistent = true;

            for (int s = 0; s < sc; s++)
            {
                if (!(cowRank[s][c] < cowRank[s][oc]))
                {
                    consistent = false;
                    break;
                }
            }

            if (consistent)
            {
                res++;
            }
        }
    }

    cout << res << endl;
}