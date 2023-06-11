#include <bits/stdc++.h>
using namespace std;

int n, maxK, rangeL, rangeR = -1, maxL;
int numCount[100005], num[200005];

int main()
{
    scanf("%d%d", &n, &maxK);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    while(rangeR != (n - 1))
    {
        rangeR++;
        numCount[num[rangeR]]++;
        
        while(numCount[num[rangeR]] > maxK)
        {
            numCount[num[rangeL]]--;
            rangeL++;
        }

        maxL = max(maxL, (rangeR - rangeL + 1));
    }

    cout << maxL << endl;
}