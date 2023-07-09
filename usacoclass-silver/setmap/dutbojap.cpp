#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> ns, ms;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        ns.insert(str);
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (ns.count(str) != 0)
        {
            ms.insert(str);
        }
    }

    cout << ms.size() << endl;
    for (auto x : ms)
    {
        cout << x << '\n';
    }
}