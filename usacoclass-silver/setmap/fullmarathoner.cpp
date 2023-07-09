#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> m;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (m.count(str) == 0)
        {
            m[str] = 1;
        }
        else
        {
            m[str]++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        string str;
        cin >> str;
        m[str]--;
        if (m[str] == 0)
        {
            m.erase(str);
        }
    }

    cout << (*m.begin()).first << endl;
}