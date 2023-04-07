#include <bits/stdc++.h>
using namespace std;

int n, dist, m, o, oi = -1;
int ow[100005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ow[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (ow[i] > 0)
        {
            //cout << "got " << ow[i] << " money" << endl;
            m = m + ow[i];
            //cout << "now have " << m << " money" << endl;
            if (m >= o && o!= 0)
            {
                //cout << "enough money to pay back in bulk" << endl;
                m = m - o;
                o = 0;
                //cout << "now have " << m << " money" << endl;
                //cout << "distance to first lender is " << (i - oi) << endl;
                dist = dist + (2 * (i - oi));
                oi = -1;
            }
        }
        else if (ow[i] < 0 && -ow[i] <= m)
        {
            //cout << "have to owe back " << ow[i] << " money and have enough now" << endl;
            m = m + ow[i];
            //cout << "now have " << m << " money" << endl;
        }
        else
        {
            //cout << "have to owe back " << ow[i] << " money and not have enough now" << endl;
            o = o - ow[i];
            //cout << "now cumulative " << o << " money to pay back" << endl;
            if (oi == -1)
            {
                //cout << "first one in this batch, index is " << i << endl;
                oi = i;
            }
        }
        dist++;
    }

    cout << dist << endl;
}