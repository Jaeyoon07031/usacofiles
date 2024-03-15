#include <bits/stdc++.h>
using namespace std;

int tcc;

int main()
{
    scanf("%d", &tcc);
    for (int tc = 0; tc < tcc; tc++)
    {
        set<int> ans;
        int n;
        scanf("%d", &n);
        int cow[(int)2e5+5], prev = -1, prev2 = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cow[i]);
            if (prev == cow[i] || prev2 == cow[i])
            {
                ans.insert(cow[i]);
            }
            prev2 = prev;
            prev = cow[i];
        }
        if (ans.empty())
        {
            cout << -1;
        }
        else
        {
            int i = 0;
            for (auto obj : ans)
            {
                if (i != 0)
                {
                    cout << " ";
                }
                cout << obj;
                i++;
            }
        }

        cout << endl;
    }
}