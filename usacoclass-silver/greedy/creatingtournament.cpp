#include <bits/stdc++.h>
using namespace std;

int n, cost;
vector<int> game;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        game.push_back(tmp);
    }

    while (game.size() != 1)
    {
        int largestVal = -1, largestIndex;
        for (int i = 0; i < game.size(); i++)
        {
            if (game[i] > largestVal)
            {
                largestVal = game[i];
                largestIndex = i;
            }
        }

        
    }
    
    cout << cost << endl;
}