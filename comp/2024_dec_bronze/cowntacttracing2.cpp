#include <bits/stdc++.h>
using namespace std;

const int ARR = 3e5+5;
int cow[ARR];
int n, ans;

int main()
{
    // input

    vector<int> comp;
    scanf("%d", &n);

    int last = 1, count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &cow[i]);
        if (cow[i] == 0)
        {
            if (count != 0)
            {
                comp.push_back(count);
                count = 0;
            }
        }
        else { count++; }
    }

    if (count != 0) {comp.push_back(count);}

    // code

    int days = INT_MAX;

    for (int i = 0; i < comp.size(); i++)
    {
        if ((i == 0 && cow[0] == 1) || (i + 1 == comp.size() && cow[n - 1] == 1))
        {
            days = min(comp[i] - 1, days);
        }
        else
        {
            days = min((comp[i] - 1) / 2, days);
        }
    }

    for (auto obj : comp)
    {
        ans += (obj + (2 * days + 1) - 1) / (2 * days + 1);
    }

    cout << ans << endl;
}