#include <bits/stdc++.h>
using namespace std;

int n, s;

void rec(int h, int t)
{
    //cout << "h is " << h << " and t is " << t << endl;
    if (h == t)
    {
        //cout << "sent home with rose" << endl;
        return;
    }
    else if (h - t == 1)
    {
        //cout << "diff is 1" << endl;
        //cout << (h * t) << "added to sum which is now " << s + (h * t) << endl;
        s = s + (h * t);
        return;
    }

    if ((h - t + 1) % 2 == 1)
    {
        rec(((h - t) / 2) + t, t);
        rec(h, ((h - t) / 2) + t + 1);
    }
    else
    {
        rec(((h - t - 1) / 2) + t, t);
        rec(h, ((h - t - 1) / 2) + t + 1);
    }
}

int main()
{
    scanf("%d", &n);
    rec(n, 1);
    cout << s << endl;
}