#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    string blank;
    for (int testCaseN = 0; testCaseN < t; testCaseN++)
    {
        int gridSize, stampSize;
        cin.ignore(100, '\n');
        getline(cin, blank);
        cin >> gridSize;
        int goalGrid[gridSize][gridSize];
        int stampGrid[gridSize][gridSize];
       
        for (int x = 0; x < gridSize; x++)
        {
            for (int y = 0; y < gridSize; y++)
            {
              stampGrid[x][y] = 0;
                char input;
                cin >> input;
                if (input == '*')
                {
                    goalGrid[x][y] = 1;
                }
                else
                {
                    goalGrid[x][y] = 0;
                }
            }
        }

        cin >> stampSize;
        int stamp[4][stampSize][stampSize];
       
        for (int x = 0; x < stampSize; x++)
        {
            for (int y = 0; y < stampSize; y++)
            {
                char input;
                cin >> input;
                if (input == '*')
                {
                    stamp[0][x][y] = 1;
                }
                else
                {
                    stamp[0][x][y] = 0;
                }
            }
        }

        for (int rotation = 0; rotation < 4; rotation++)
        {
            for (int stampX = 0; stampX < (gridSize - stampSize + 1); stampX++)
            {
                for (int stampY = 0; stampY < (gridSize - stampSize + 1); stampY++)
                {
                    bool noOverfitting = true;
                    for (int checkX = 0; checkX < stampSize; checkX++)
                    {
                        for (int checkY = 0; checkY < stampSize; checkY++)
                        {
                            if (stamp[rotation][checkX][checkY] == 1 && goalGrid[stampX + checkX][stampY + checkY] == 0)
                            {
                                noOverfitting = false;
                                break;
                            }
                        }
                        if(!noOverfitting)
                          break;
                    }

                    if (noOverfitting)
                    {
                        for (int checkX = 0; checkX < stampSize; checkX++)
                        {
                            for (int checkY = 0; checkY < stampSize; checkY++)
                            {
                                if (stamp[rotation][checkX][checkY] == 1)
                                {
                                    stampGrid[stampX + checkX][stampY + checkY] = 1;
                                }
                            }
                        }
                    }
                }
            }

            for (int rotateX = 0; rotateX < stampSize; rotateX++)
            {
                for (int rotateY = 0; rotateY < stampSize; rotateY++)
                {
                    stamp[ (rotation + 1) % 4][rotateX][rotateY] = stamp[rotation][rotateY][stampSize - rotateX - 1];
                }
            }
        }

        bool matchesGoal = true;
        for (int checkX = 0; checkX < gridSize; checkX++)
        {
            for (int checkY = 0; checkY < gridSize; checkY++)
            {
                if (goalGrid[checkX][checkY] != stampGrid[checkX][checkY])
                {
                    matchesGoal = false;
                }
            }
        }

        if (matchesGoal)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}