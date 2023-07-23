#include <bits/stdc++.h>
using namespace std;

long long sum;
int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%d", &ipt);
        pq.push(ipt);
    }

    for (int i = 0; i < (n - 1); i++)
    {
        int add1, add2;

        add1 = pq.top();
        pq.pop();
        add2 = pq.top();
        pq.pop();
        
        sum = sum + add1 + add2;
        pq.push(add1 + add2);
    }

    cout << sum << endl;
}