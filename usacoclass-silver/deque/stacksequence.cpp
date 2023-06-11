#include <bits/stdc++.h>
using namespace std;

int n, prcc = 1, seq[100005];
char prc[200010];

int nextpush = 2, nextpop = 0;
bool possible = true;
deque<int> dq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }

    dq.push_back(1);
    prc[0] = '+';

    while (true)
    {
        if (dq.size() != 0 && dq.back() == seq[nextpop])
        {
            //cout << "pop" << endl;
            prc[prcc] = '-';
            prcc++;

            dq.pop_back();
            nextpop++;

            if (nextpop == n)
            {
                break;
            }
        }
        else
        {
            //cout << "push " << endl;
            prc[prcc] = '+';
            prcc++;

            dq.push_back(nextpush);
            nextpush++;

            if (nextpush > n + 1)
            {
                possible = false;
                break;
            }
        }
    }

    if (possible)
    {
        for (int i = 0; i < prcc; i++)
        {
            printf("%c\n", prc[i]);
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}