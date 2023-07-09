#include <bits/stdc++.h>
using namespace std;

int n, bc;
vector<string> bnl;
map<string, int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s[str]++;
    }
    for (auto x : s)
    {
        if (x.second > bc)
        {
            bnl.clear();
            bnl.push_back(x.first);
            bc = x.second;
        }
        else if (x.second == bc)
        {
            bnl.push_back(x.first);
        }
    }
    cout << *bnl.begin() << endl;
}