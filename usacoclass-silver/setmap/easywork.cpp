#include <bits/stdc++.h>
using namespace std;

int n;
set<string> s;
vector<string> vs;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string nm, act;
        cin >> nm >> act;
        if (act[0] == 'e')
        {
            s.insert(nm);
        }
        else
        {
            s.erase(nm);
        }
    }

    for (auto x : s)
    {
        vs.push_back(x);
    }
    for (int i = vs.size() - 1; i >= 0; i--)
    {
        cout << vs[i] << '\n';
    }
}