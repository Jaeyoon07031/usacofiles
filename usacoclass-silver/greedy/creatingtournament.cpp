#include <bits/stdc++.h>
using namespace std;

int n, cost;
vector<int> tournament;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        tournament.push_back(tmp);
    }

    while (tournament.size() != 1)
    {
        vector<int> newTournament;
        int pointer = 0;
        while (true)
        {
            if (pointer + 2 < tournament.size() && abs(tournament[pointer] - tournament[pointer + 1]) > abs(tournament[pointer + 1] - tournament[pointer + 2]))
            {
                newTournament.push_back(tournament[pointer]);
                newTournament.push_back(min(tournament[pointer + 1], tournament[pointer + 2]));
                cost = cost + abs(tournament[pointer + 1] - tournament[pointer + 2]);
                pointer = pointer + 3;
            }
            else
            {
                newTournament.push_back(min(tournament[pointer], tournament[pointer + 1]));
                cost = cost + abs(tournament[pointer] - tournament[pointer + 1]);
                pointer = pointer + 2;
            }
            if (pointer >= tournament.size() - 1)
            {
                if (pointer == tournament.size() - 1)
                {
                    newTournament.push_back(tournament[pointer]);
                }
                tournament.swap(newTournament);
                break;
            }
        }
    }
    
    cout << cost << endl;
}