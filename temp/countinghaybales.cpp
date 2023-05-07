#include <bits/stdc++.h>
using namespace std;

int len, quer;
int hay[100005], ql[100005], qr[100005];

void query (int qid)
{
    int l, r;
    l = ql[qid];
    r = qr[qid];

    if (l > hay[len - 1])
    {
        printf("0\n");
        return;
    }

    int lowerl = lower_bound(hay, hay + len, l) - hay;
    int lowerr = upper_bound(hay, hay + len, r) - hay;

    printf("%d\n", lowerr - lowerl);
}

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

	scanf("%d%d", &len, &quer);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &hay[i]);
    }
    for (int i = 0; i < quer; i++)
    {
        scanf("%d%d", &ql[i], &qr[i]);
    }

    sort(hay, hay + len);

    for (int i = 0; i < quer; i++)
    {
        query(i);
    }
}