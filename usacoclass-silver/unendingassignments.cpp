#include <bits/stdc++.h>
using namespace std;

int n, pts;
deque<pair<int, int>> dq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int rg1, rg2, rg3;
        cin >> rg1;
        if (rg1)
        {
            cin >> rg2 >> rg3;
            dq.push_back({rg2, rg3});
        }
        if (!dq.empty())
        {
            dq.back().second = dq.back().second - 1;
            if (dq.back().second == 0)
            {
                pts = pts + dq.back().first;
                dq.pop_back();
            }
        }
    }
    cout << pts << endl;
}