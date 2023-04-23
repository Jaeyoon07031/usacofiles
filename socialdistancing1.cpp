#include <bits/stdc++.h>
using namespace std;

int n, strk1, strk2, oldcowd = INT_MAX, newcowd, cow[100005], tcowc;

int main()
{
    scanf("%d", &n);
    int strk = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%1d", &t);
        cow[i] = t;
        if (t == 0)
        {
            strk++;
        }
        else
        {
            tcowc++;
            if (strk > strk1)
            {
                strk2 = strk1;
                strk1 = strk;
            }
            else if (strk > strk2)
            {
                strk2 = strk;
            }
            strk = 0;
        }
    }

    if (strk2 % 2 == 0)
    {
        strk2 = strk2 - 1;
    }

    newcowd = ((strk2 - (strk2 % 2)) / 2) + 1;

    strk = 0;
    int cowc = 0;
    for (int i = 0; i < n; i++)
    {
        if (cow[i] == 0)
        {
            strk++;
        }
        else
        {
            cowc++;
            if (cowc == 1)
            {
                strk = 1;
                continue;
            }
            else if (cowc == tcowc)
            {
                oldcowd = min(oldcowd, strk);
                break;
            }
            else
            {
                oldcowd = min(oldcowd, strk);
                strk = 1;
            }
        }
    }

    cout << min(newcowd, oldcowd) << endl;
}