#include <bits/stdc++.h>
using namespace std;

int n;
string boxes = "";

int main()
{
    scanf("%d\n", &n);
    cin >> boxes;

    int l = 0, r = n;
    int m = (l + r) / 2;

    while (true)
    {
        m = (l + r) / 2;

        if (l == r)
        {
            break;
        }

        bool possible = false;
        set<string> combs;

        for (int b = 0; b < (n - m) + 1; b++)
        {
            string t = "";
            for (int c = 0; c < m; c++)
            {
                t = t + boxes[b + c];
            }
            combs.insert(t);
        }
        
        if (combs.size() == ((n - m) + 1))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << m << endl;
}