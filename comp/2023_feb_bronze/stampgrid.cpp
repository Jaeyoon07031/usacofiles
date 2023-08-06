#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    for (int testCaseN = 0; testCaseN < t; testCaseN++)
    {
        int gridSize, stampSize;
        int stampGrid[25][25] = {0};
        int stamp[4][25][25] = {0};

        scanf("%d", &gridSize);
        int goalGrid[gridSize][gridSize] = {0};
        // TODO: migrate to above code
        for (int y = 0; y < gridSize; y++)
        {
            for (int x = 0; x < gridSize; x++)
            {
                char input;
                scanf(" %c", &input);
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

        scanf("%d", &stampSize);
        for (int y = 0; y < stampSize; y++)
        {
            for (int x = 0; x < stampSize; x++)
            {
                char input;
                scanf(" %c", &input);
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
            for (int stampY = 0; stampY < (gridSize - stampSize + 1); stampY++)
            {
                for (int stampX = 0; stampX < (gridSize - stampSize + 1); stampX++)
                {
                    bool noOverfitting = true;
                    for (int checkY = 0; checkY < stampSize; checkY++)
                    {
                        for (int checkX = 0; checkX < stampSize; checkX++)
                        {
                            if (stamp[rotation][checkX][checkY] == 1 && goalGrid[stampX + checkX][stampY + checkY] == 0)
                            {
                                noOverfitting = false;
                            }
                        }
                    }

                    if (noOverfitting)
                    {
                        for (int checkY = 0; checkY < stampSize; checkY++)
                        {
                            for (int checkX = 0; checkX < stampSize; checkX++)
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

            for (int rotateY = 0; rotateY < stampSize; rotateY++)
            {
                for (int rotateX = 0; rotateX < stampSize; rotateX++)
                {
                    stamp[rotation + 1][rotateX][rotateY] = stamp[rotation][rotateY][stampSize - rotateX - 1];
                }
            }
        }

        bool matchesGoal = true;
        for (int checkY = 0; checkY < gridSize; checkY++)
        {
            for (int checkX = 0; checkX < gridSize; checkX++)
            {
                if (goalGrid[checkX][checkY] != stampGrid[checkX][checkY])
                {
                    matchesGoal = false;
                }
            }
        }

        if (matchesGoal)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}