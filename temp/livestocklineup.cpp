#include <bits/stdc++.h>
using namespace std;

int cc;
pair<string, string> req[8];
string trash1, trash2, trash3, trash4;
string cows[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main()
{
    cin >> cc;
    for (int i = 0; i < cc; i++)
    {
        cin >> req[i].first >> trash1 >> trash2 >> trash3 >> trash4 >> req[i].second;
    }

    sort(cows, cows + 8);

    while(next_permutation(cows, cows + 8))
    {
        bool possible = true;
        for (int i = 0; i < cc; i++)
        {
            //cout << req[i].first << " needs to be milked with " << req[i].second << endl;
            int c1index = -1;
            for (int j = 0; j < 8; j++)
            {
                if (cows[j] == req[i].first)
                {
                    c1index = j;
                    break;
                }
            }

            //cout << req[i].first << " can be found at index " << c1index << endl;

            if (!(((c1index != 0) && cows[c1index - 1] == req[i].second) || ((c1index != 7) && cows[c1index + 1] == req[i].second)))
            {
                possible = false;
            }
        }
        
        if (possible)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << cows[j] << endl;
            }
            return 0;
        }   
    }
}
