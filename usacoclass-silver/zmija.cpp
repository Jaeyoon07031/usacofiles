#include <bits/stdc++.h>
using namespace std;

int boardSize, appleCount, turnCount, time;
int appleLocations[105][105];
char turnTimes[10005];
deque<pair<int, int>> snake;
set<pair<int, int>> snakeOccupied;
pair<int, int> snakeDirection;

int main()
{
    // Input Processing

    scanf("%d%d", &boardSize, &appleCount);
    for (int i = 0; i < appleCount; i++)
    {
        int rg1, rg2;
        scanf("%d%d", &rg1, &rg2);
        appleLocations[rg1 - 1][rg2 - 1] = 1;
    }
    scanf("%d", &turnCount);
    for (int i = 0; i < turnCount; i++)
    {
        int rg1;
        char rg2;
        scanf("%d %c", &rg1, &rg2);
        turnTimes[rg1] = rg2;
    }

    // Simulation Initial Setup

    snake.push_back({0, 0});
    snakeOccupied.insert({0, 0});
    snakeDirection = {1, 0};

    // Simulation

    while (true)
    {
        // Move the Snake Forward 
        snake.push_back({snake.back().first + snakeDirection.first, snake.back().second + snakeDirection.second});
        snakeOccupied.insert(snake.back());
        time++;
        
        // Eat an Apple and Remove Tail
        if (appleLocations[snake.back().first][snake.back().second])
        {
            appleLocations[snake.back().first][snake.back().second] = 0;
        }
        else
        {
            snakeOccupied.erase(snake.front());
            snake.pop_front();
        }

        // Check for Collisions

        // Check for Turns
    }
}