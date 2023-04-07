#include <bits/stdc++.h>
using namespace std;

int ab, bc;
int l[3];

int main()
{
    scanf("%d%d%d", &l[0], &l[1], &l[2]);
    sort(l, l + 3);
    ab = l[1] - l[0];
    bc = l[2] - l[1];


    if (ab == 1 && bc == 1)
    {
        cout << 0 << endl;
    }
    else if (ab == 2 || bc == 2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    cout << max(ab, bc) - 1 << endl;
}