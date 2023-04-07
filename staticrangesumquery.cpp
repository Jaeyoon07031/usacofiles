#include <bits/stdc++.h>
using namespace std;

long long arr[200005];
long long sums[200005];
long long  tsum, len, quer, l, r = 0;

void findSum(int left, int right)
{
    if (left == 1)
    {
        cout << sums[right - 1] << endl;
        return;
    }
    cout << sums[right - 1] - sums[left - 2] << endl;
    return;
}

int main()
{
    cin >> len >> quer;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        tsum = tsum + arr[i];
        sums[i] = tsum;
    }
    for (int i = 0; i < quer; i++)
    {
        cin >> l >> r;
        findSum(l, r);
    }
};
