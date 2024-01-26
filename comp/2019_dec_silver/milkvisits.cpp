#include <bits/stdc++.h>
using namespace std;

// IMPORTANT: DONT FORGET ABOUT DEPTH/FATHER EXCEPTION FOR NODE 1

struct farm
{
    int depth;
    int father;
    char cow;
};

int farmCount, friendCount;
int layerAdded[100005];
vector<int> conn[100005], layer[100005];
farm farms[100005];

bool find(int node1, int node2, char goal)
{
    int at1 = node1, at2 = node2;

    if (farms[at1].cow == goal || farms[at2].cow == goal)
    {
        return true;
    }

    while (farms[at1].depth != farms[at2].depth)
    {
        if (farms[at1].depth > farms[at2].depth)
        {
            at1 = farms[at1].father;

            if (farms[at1].cow == goal)
            {
                return true;
            }
        }
        else
        {
            at2 = farms[at2].father;

            if (farms[at2].cow == goal)
            {
                return true;
            }
        }
    }

    while (at1 != at2)
    {
        at1 = farms[at1].father;
        at2 = farms[at2].father;
        if (farms[at1].cow == goal || farms[at2].cow == goal)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    scanf("%d%d\n", &farmCount, &friendCount);
    for (int i = 0; i < farmCount; i++)
    {
        scanf("%c", &farms[i].cow);
    }
    for (int i = 0; i < farmCount - 1; i++)
    {
        int f1, f2;
        scanf("%d%d", &f1, &f2);
        conn[f1 - 1].push_back(f2 - 1);
        conn[f2 - 1].push_back(f1 - 1);
    }

    int depth = 0;
    layer[0].push_back(0);
    layerAdded[0] = 1;
    while (true)
    {
        if (layer[depth].empty())
        {
            break;
        }

        for (int node : layer[depth])
        {
            for (int nextNode : conn[node])
            {
                if (!layerAdded[nextNode])
                {
                    layer[depth + 1].push_back(nextNode);
                    farms[nextNode].father = node;
                    farms[nextNode].depth = depth + 1;
                    layerAdded[nextNode] = 1;
                }
            }
        }
        depth++;
    }

    for (int i = 0; i < friendCount; i++)
    {
        int node1, node2;
        char goal;

        scanf("%d %d %c", &node1, &node2, &goal);

        if (find(node1 - 1, node2 - 1, goal))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}