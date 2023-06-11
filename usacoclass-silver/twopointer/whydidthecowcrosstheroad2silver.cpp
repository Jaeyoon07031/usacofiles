#include <bits/stdc++.h>
using namespace std;

int n, k, b, minB = INT_MAX, rangeL, rangeR, sum;
int brokenS[100005];

int main()
{
    scanf("%d%d%d", &n, &k, &b);
    for (int i = 0; i < b; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        brokenS[tmp - 1]++;
    }

    for (int i = 0; i < k; i++)
    {
        sum = sum + brokenS[i];
    }

    //cout << sum << " broken lights found in range 0 to " << k - 1 << endl; 
    minB = min(minB, sum);

    rangeL = 0;
    rangeR = k - 1;

    while(rangeR != (n - 1))
    {
        //cout << "removing " << rangeL << " (" << brokenS[rangeL] << ")" <<  ", adding " << rangeR + 1 << "(" << brokenS[rangeR + 1] << ")" << endl;
        sum = sum - brokenS[rangeL];
        sum = sum + brokenS[rangeR + 1];
        rangeL++;
        rangeR++;
        //cout << "checking range " << rangeL << " to " << rangeR << endl;
        //cout << "found " << sum << " broken lights" << endl;
        minB = min(minB, sum);
    }

    cout << minB << endl;
}