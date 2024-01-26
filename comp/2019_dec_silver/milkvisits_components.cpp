#include <bits/stdc++.h>
using namespace std;

const int arrayCount = 100005;

int farmCount, friendCount;
int comp[arrayCount], visited[arrayCount];
char farm[arrayCount], type[arrayCount];
vector<int> conn[arrayCount];

void find(int node, int tag, char group)
{
    visited[node] = 1;
    comp[node] = tag;

    for (int nextNode : conn[node])
    {
        if (farm[nextNode] == group && !visited[nextNode])
        {
            find(nextNode, tag, group);
        }
    }
}

int main()
{
    scanf("%d%d\n", &farmCount, &friendCount);
    for (int i = 0; i < farmCount; i++)
    {
        scanf("%c", &farm[i]);
    }
    for (int i = 0; i < farmCount - 1; i++)
    {
        int f1, f2;
        scanf("%d%d", &f1, &f2);
        conn[f1 - 1].push_back(f2 - 1);
        conn[f2 - 1].push_back(f1 - 1);
    }

    for (int i = 0; i < farmCount; i++)
    {
        if (!visited[i])
        {
            type[i] = farm[i];
            find(i, i, farm[i]);
        }
    }

    for (int i = 0; i < friendCount; i++)
    {
        int node1, node2;
        char goal;

        scanf("%d %d %c", &node1, &node2, &goal);

        node1--;
        node2--;

        if (comp[node1] == comp[node2])
        {
            if (type[comp[node1]] == goal)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            cout << 1;
        }
    }
}