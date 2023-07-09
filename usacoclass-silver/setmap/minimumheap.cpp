#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        if (ipt == 0)
        {
            if(pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top();
                pq.pop();
            }
        } 
        else
        {
            pq.push(ipt);
        }
    }
}