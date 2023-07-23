#include <bits/stdc++.h>
using namespace std;

multiset<int> s;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%d", &ipt);
        if (ipt == 0)
        {
            if(s.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                auto it = s.end();
                it--;
                int maxv = *it;
                cout << maxv << '\n';
                s.erase(it);
            }
        } 
        else
        {
            s.insert(ipt);
        }
    }
}