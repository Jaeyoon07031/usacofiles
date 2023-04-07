#include <bits/stdc++.h>
using namespace std;
 
long long nums[200005], sums[200005], sml[200005], tot[200005];
long long sum;
long long len, sumd, small, big = -10000000000000000;
 
int main()
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> nums[i];
        sumd = sumd + nums[i];
        sums[i] = sumd;
        if (i == 0)
        {
            sml[i] = 0;
        }
        else if (small > sums[i - 1])
        {
            small = sums[i - 1];
            sml[i] = small;
        }
        else
        {
            sml[i] = small;
        }
        tot[i] = sums[i] - sml[i];
        if (tot[i] > big)
        {
            big = tot[i];
        }
    }
    cout << big << endl;
}