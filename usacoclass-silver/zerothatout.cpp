#include <bits/stdc++.h>
using namespace std;

int n, t, a;
deque<int> dq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t == 0)
        {
            dq.pop_back();
        }
        else
        {
            dq.push_back(t);
        }
    }

    while (!dq.empty())
    {
        a = a + dq.back();
        dq.pop_back();
    }

    cout << a << endl;
}