#include <bits/stdc++.h>
using namespace std;

int n;
char dice[4][6];

bool solve()
{
    string word;
    cin >> word;

    bool possible = false;

    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            for (int c = 0; c < 6; c++)
            {
                for (int d = 0; d < 6; d++)
                {
                    string str = "____";
                    str[0] = dice[0][a];
                    str[1] = dice[1][b];
                    str[2] = dice[2][c];
                    str[3] = dice[3][d];

                    sort(str.begin(), str.end());

                    do
                    {
                        bool equal = true;        

                        if (word.size() == 1)
                        {
                            if (!(str[0] == word[0]))
                            {
                                equal = false;
                            }
                        }
                        else if (word.size() == 2)
                        {
                            if (!(str[0] == word[0] && str[1] == word[1]))
                            {
                                equal = false;
                            }
                        }
                        else if (word.size() == 3)
                        {
                            if (!(str[0] == word[0] && str[1] == word[1] && str[2] == word[2]))
                            {
                                equal = false;
                            }
                        }
                        else if (word.size() == 4)
                        {
                            if (!(str[0] == word[0] && str[1] == word[1] && str[2] == word[2] && str[3] == word[3]))
                            {
                                equal = false;
                            }
                        }

                        if (equal)
                        {
                            return true;
                        }
                    } while (next_permutation(str.begin(), str.end()));
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n;
  
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char c;
            cin >> c;
            dice[i][j] = c;
        }
    }

    for (int tc = 0; tc < n; tc++)
    {
        if (solve())
        {
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
}