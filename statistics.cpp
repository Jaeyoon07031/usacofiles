#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> ns;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        ns.push_back(t);
        s = s + t;
    }

    float avg = float(s) / n;
    cout << avg << endl;

    sort(ns.begin(), ns.end());
    if (n % 2 == 1)
    {
        cout << ns[(n - 1) / 2] << endl;
    }
    else
    {
        cout << float(ns[n / 2] + ns[(n / 2) - 1]) / 2 << endl;
    }
}