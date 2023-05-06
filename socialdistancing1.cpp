#include <bits/stdc++.h>
using namespace std;

int n, inf[100005], infc, bm = -1, ibm = INT_MAX;
//100005

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%1d", &t);
        if (t == 1)
        {
            inf[infc] = i;
            if (infc != 0)
            {
                ibm = min(ibm, inf[infc] - inf[infc - 1]);
            }
            infc++;
        }
    }
    if (infc == 0)
    {
        cout << n - 1 << endl;
        return 0;
    }

    int l = 1, r = n, pc, m;
    bool p = false;

    while (true)
    {
        pc = 0;
        m = (l + r) / 2;
        if (l > r)
        {
            break;
        }

        pc = pc + (inf[0] / m);

        for (int i = 1; i < infc; i++)
        {
            if ((inf[i] - inf[i - 1]) / m > 0)
            {
                pc = pc + ((inf[i] - inf[i - 1]) / m) - 1;
            }
        }

        if (inf[infc - 1] != (n - 1))
        {
            pc = pc + (((n - 1) - inf[infc - 1]) / m);
        }

        if (pc >= 2)
        {
            bm = max(bm, m);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    
    cout << min(bm, ibm) << endl;
}