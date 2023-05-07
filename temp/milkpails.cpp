#include <bits/stdc++.h>
using namespace std;

int a, b, c, g;

int main()
{
    scanf("%d%d%d", &a, &b, &c);

    for (int i = 0; i < (c / a) + 1; i++)
    {
        g = max(g, (a * i) + (((c - (a * i)) / b) * b));
    }

    cout << g << endl;
}