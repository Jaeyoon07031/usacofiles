#include <bits/stdc++.h>
using namespace std;

int boardSize, appleCount, turnCount, score, direction;
int appleLocations[105][105];
char turnTimes[10005];
pair<int, int> directions[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
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
        appleLocations[rg2 - 1][rg1 - 1] = 1;
    }
    scanf("%d", &turnCount);
    for (int i = 0; i < turnCount; i++)
    {
        int rg1;
        char rg2;
        scanf("%d %c", &rg1, &rg2);
        turnTimes[rg1 - 1] = rg2;
    }

    // Simulation Initial Setup

    snake.push_back({0, 0});
    snakeOccupied.insert({0, 0});
    snakeDirection = directions[0];

    // Simulation

    while (true)
    {
        //cout << "Time is " << score << endl;
        // Move the Snake Forward 
        int setSizeBefore = snakeOccupied.size();
        snake.push_back({snake.back().first + snakeDirection.first, snake.back().second + snakeDirection.second});
        //cout << "Added " << snake.back().first << ", " << snake.back().second << " to the snake" << endl;
        snakeOccupied.insert(snake.back());

        // Check for Collisions
        if (setSizeBefore == snakeOccupied.size())
        {
            //cout << "Snake hit itself, game over" << endl;
            break;
        }
        else if (snake.back().first < 0 || snake.back().second < 0 || snake.back().first >= boardSize || snake.back().second >= boardSize)
        {
            //cout << "Snake hit a wall, game over" << endl;
            break;
        }
        
        // Eat an Apple and Remove Tail
        if (appleLocations[snake.back().first][snake.back().second])
        {
            //cout << "Snake ate an apple" << endl;
            appleLocations[snake.back().first][snake.back().second] = 0;
        }
        else
        {
            //cout << "Snake ate no apple, removing front" << endl;
            snakeOccupied.erase(snake.front());
            snake.pop_front();
        }

        // Check for Turns
        if (turnTimes[score] == 'L')
        {
            //cout << "Snake turned left" << endl;
            int newDirection = direction + 1;
            if (newDirection == 4)
            {
                newDirection = 0;
            }
            //cout << "Now looking in direction " << newDirection << "(" << directions[newDirection].first << ", " << directions[newDirection].second << ")" << endl;
            snakeDirection = directions[newDirection];
            direction = newDirection;
        }
        else if (turnTimes[score] == 'D')
        {
            //cout << "Snake turned right" << endl;
            int newDirection = direction - 1;
            if (newDirection == -1)
            {
                newDirection = 3;
            }
            //cout << "Now looking in direction " << newDirection << "(" << directions[newDirection].first << ", " << directions[newDirection].second << ")" << endl;
            snakeDirection = directions[newDirection];
            direction = newDirection;
        }

        score++;
    }

    cout << score + 1 << endl;
}