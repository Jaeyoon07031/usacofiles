#include <bits/stdc++.h>
using namespace std;

char ans[3][3], gss[3][3], trash;
int ansc[26], gssc[26];
int green, yellow;

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%c", &ans[i][j]);
        }
        scanf("%c", &trash);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%c", &gss[i][j]);
        }
        scanf("%c", &trash);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ans[i][j] == gss[i][j])
            {
                green++;
            }
            else
            {
                ansc[ans[i][j] - 65]++;
                gssc[gss[i][j] - 65]++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        yellow = yellow + min(ansc[i], gssc[i]);
    }

    cout << green << endl << yellow << endl;
}