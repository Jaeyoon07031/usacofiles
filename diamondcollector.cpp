#include <bits/stdc++.h>
using namespace std;

int n, k, mdc;
int d[10005];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    sort(d, d + n);

    for (int i = 0; i < n; i++)
    {
        //cout << "starting dia index is " << i << " and size is " << d[i] << endl;
        int dc = 0;
        for (int j = 0; j < n; j++)
        {
            //cout << "diamond index " << j << " has weight " << d[j] << " and difference is " << d[j] - d[i] << endl;
            if (((d[j] - d[i]) <= k) && ((d[j] - d[i]) >= 0))
            {
                //cout << "diamond can be added" << endl;
                dc++;
            }
        }
        //cout << dc << " diamonds can be displayed" << endl;
        if (dc > mdc)
        {
            mdc = dc;
        }
    }
    
    cout << mdc << endl;
}