#include <bits/stdc++.h>
using namespace std;

int n, a1, a2, b1, b2, period;
long long k;
int ipt[105], mdf[105];

int main()
{
    scanf("%d %lld\n%d %d\n%d %d", &n, &k, &a1, &a2, &b1, &b2);
    for (int i = 1; i < n + 1; i++)
    {
        ipt[i] = i;
        mdf[i] = i;
    }

    while(true)
    {
        reverse(mdf + a1, mdf + a2 + 1);
        reverse(mdf + b1, mdf + b2 + 1);

        period++;
        bool same = true;
        
        for (int i = 1; i < n + 1; i++)
        {
            if (ipt[i] != mdf[i])
            {
                same = false;
                break;
            }
        }

        if (same)
        {
            break;
        }
    }

    for (int i = 0; i < (k % period); i++)
    {
        reverse(mdf + a1, mdf + a2 + 1);
        reverse(mdf + b1, mdf + b2 + 1);
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << mdf[i] << endl;
    }
    
}