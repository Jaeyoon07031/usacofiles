#include <bits/stdc++.h>
using namespace std;

long long n, k, rangeL, rangeR, cnt, sum;
long long num[100005];

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &num[i]);
    }
    scanf("%lld", &k);

    while(true)
    {
        if (rangeR == n)
        {
            if (sum > k)
            {
                cnt++;
                sum = sum - num[rangeL];
                rangeL++;
            }
            else
            {
                break;
            }
            continue;
        }

        if (sum <= k)
        {
            sum = sum + num[rangeR];
            rangeR++;
        }
        else
        {
            cnt = cnt + (n - rangeR) + 1;
            sum = sum - num[rangeL];
            rangeL++;
        }
    }

    cout << cnt << endl;
}