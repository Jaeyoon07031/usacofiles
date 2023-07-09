#include <bits/stdc++.h>
using namespace std;

int n, k, r, front = -1, back, best = INT_MAX, cond, base[200010], cnt[200010], req[200010];

int main()
{
    scanf("%d%d%d", &n, &k, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &base[i]);
    }
    for (int i = 0; i < r; i++)
    {
        int ncl, ord;
        scanf("%d%d", &ncl, &ord);
        req[ncl] = ord;
    }


    while(front < (n - 1))
    {
        if (cond < r)
        {
            front++;
            //cout << "increasing front, which is " << base[front] << endl;
            cnt[base[front]]++;
            //cout << "now have " << cnt[base[front]] << " of this in order" << endl;
            //cout << "want " << req[base[front]] << " of this" << endl;
            if (cnt[base[front]] == req[base[front]])
            {
                cond++;
                //cout << "now met requirement for this base order" << endl;
                //cout << "met " << cond << " requirements now out of " << r << endl;
            }
        }
        if (cond >= r)
        {
            //cout << "already met requirements with distance " << front - back + 1 << endl;
            best = min(best, front - back + 1);
            //cout << "increasing back, which is " << base[back] << endl;
            cnt[base[back]]--;
            if (cnt[base[back]] < req[base[back]])
            {
                //cout << "no longer meets requirements" << endl;
                cond--;
            }
            back++;
        }
    }

    while (cond >= r && back < n)
    {
        //cout << "already met requirements with distance " << front - back + 1 << endl;
        best = min(best, front - back + 1);
        //cout << "increasing back, which is " << base[back] << endl;
        cnt[base[back]]--;
        if (cnt[base[back]] < req[base[back]])
        {
            //cout << "no longer meets requirements" << endl;
            cond--;
        }
        back++;
    }
    
    if (best == INT_MAX)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << best << endl;
    }
}