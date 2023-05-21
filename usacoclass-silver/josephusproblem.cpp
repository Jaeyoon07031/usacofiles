#include <bits/stdc++.h>
using namespace std;

int n, k, tick, outc, out[5005];
deque<int> dq;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        dq.push_back(i);
    }

    while (true)
    {
        tick++;
        if (tick == k)
        {
            out[outc] = dq.front();
            outc++;
            tick = 0;

            if (outc == n)
            {
                break;
            }
        }
        else
        {
            dq.push_back(dq.front());
        }
        dq.pop_front();
    }

    cout << "<" << out[0] + 1;
    for (int i = 1; i < n; i++)
    {
        cout << ", " << out[i] + 1;
    }
    cout << ">" << endl;
}