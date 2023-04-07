#include <bits/stdc++.h>
using namespace std;

int cc, bc, cw[55], bw[10005];
int m, rbc;

int main()
{
    scanf("%d", &cc);
    for (int i = 0; i < cc; i++)
    {
        scanf("%d", &cw[i]);
    }

    scanf("%d", &bc);
    for (int i = 0; i < bc; i++)
    {
        scanf("%d", &bw[i]);
    }

    sort(cw, cw + cc, greater<int>());

    while (rbc > 0)
    {
        sort(bw, bw + bc, greater<int>());
        m++;

        for (int c = 0; c < cc; c++)
        {
            
        }

    }

    cout << m << endl;
}