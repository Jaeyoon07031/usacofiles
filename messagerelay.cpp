#include <bits/stdc++.h>
using namespace std;

vector<int> conn[1005];
int n, nlc;
bool evisited[1005][1005];

void find(int ni, bool visited[])
{
    //cout << "at node " << ni << endl;
    if (visited[ni])
    {
        //cout << "have been to this node before" << endl;
        return;
    }
    visited[ni] = true;

    if (conn[ni][0] == -1)
    {
        //cout << "at a finish node" << endl;
        nlc++;
        return;
    }
    find(conn[ni][0], visited);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        conn[i].push_back(t - 1);
    }

    for (int i = 0; i < n; i++)
    {
        //cout << "starting from node " << i << endl;
        find(i, evisited[i]);
    }

    cout << nlc << endl;
}|