#include <bits/stdc++.h>
using namespace std;

int pos[255];
// change sizes to 255
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        pos[i] = i;
    }

    int curr = 1;
    int move;

    while(true)
    {
        move = curr;
        pos[curr] = -1;
        int dest = ((curr + move) % n);
        if (dest == 0)
        {
            dest = n;
        }

        if (pos[dest] == -1)
        {
            cout << curr << endl;
            return 0;
        }

        curr = dest;
    }
}