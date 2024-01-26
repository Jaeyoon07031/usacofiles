#include <bits/stdc++.h>
using namespace std;

int adie[4], bdie[4], wint[4], loset[4];
int tcc;

bool awinsb(int a[4], int b[4])
{
    int awin = 0;
    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i] > b[j])
            {
                awin++;
                total++;
            }
            else if (b[j] > a[i])
            {
                total++;
            }
        }
    }

    if (awin * 2 > total)
    {
        return true;
    }
    return false;
}

bool nontransitive(int c[4])
{
    if (awinsb(c, wint) && awinsb(loset, c))
    {
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &tcc);

    for (int tc = 0; tc < tcc; tc++)
    {
        scanf("%d%d%d%d%d%d%d%d", &adie[0], &adie[1], &adie[2], &adie[3], &bdie[0], &bdie[1], &bdie[2], &bdie[3]);

        if (awinsb(adie, bdie))
        {
            wint[0] = adie[0];
            wint[1] = adie[1];
            wint[2] = adie[2];
            wint[3] = adie[3];

            loset[0] = bdie[0];
            loset[1] = bdie[1];
            loset[2] = bdie[2];
            loset[3] = bdie[3];
        }
        else
        {
            wint[0] = bdie[0];
            wint[1] = bdie[1];
            wint[2] = bdie[2];
            wint[3] = bdie[3];

            loset[0] = adie[0];
            loset[1] = adie[1];
            loset[2] = adie[2];
            loset[3] = adie[3];
        }

        bool possible = false;

        for (int a = 1; a < 11; a++)
        {
            for (int b = 1; b < 11; b++)
            {
                for (int c = 1; c < 11; c++)
                {
                    for (int d = 1; d < 11; d++)
                    {
                        int arr[4] = {a, b, c, d};
                        possible = max(possible, nontransitive(arr));
                    }
                }
            }
        }

        if (possible)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}