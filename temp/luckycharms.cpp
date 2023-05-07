#include <bits/stdc++.h>
using namespace std;

int blength, charmct, nailloc;
int charmloc[520], charmlen[520];

int main()
{
    scanf("%d%d%d", &blength, &charmct, &nailloc);
    for (int i = 0; i < charmct; i++)
    {
        scanf("%d%d", &charmlen[i], &charmloc[i]);
    }

    for (int i = 0; i < charmct; i++)
    {
        cout << charmlen[i] + abs(charmloc[i] - nailloc) << endl;
    }
}