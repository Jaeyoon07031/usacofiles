#include <bits/stdc++.h>
using namespace std;

int n, m;
int light[505];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int opertyp, rangea, rangeb;
        scanf("%d%d%d", &opertyp, &rangea, &rangeb);
        if (opertyp == 0)
        {
            for (int i = rangea; i < rangeb + 1; i++)
            {
                light[i] = abs(light[i] - 1);
            }
        }
        else
        {
            int cnt = 0;
            for (int i = rangea; i < rangeb + 1; i++)
            {
                cnt = cnt + light[i];
            }
            cout << cnt << endl;
        }
    }
}