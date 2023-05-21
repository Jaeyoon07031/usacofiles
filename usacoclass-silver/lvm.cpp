#include <bits/stdc++.h>
using namespace std;

int n, rg, param, line;
string instr;
deque<int> dq;
pair<string, int> prgrm[1005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> instr;
        if (instr == "PUSH" || instr == "IFZERO")
        {
            cin >> param;
        }
        prgrm[i].first = instr;
        prgrm[i].second = param;
    }

    while (true)
    {
        if (prgrm[line].first == "PUSH")
        {
            dq.push_back(prgrm[line].second);
        }
        else if (prgrm[line].first == "STORE")
        {
            rg = dq.back();
            dq.pop_back();
        }
        else if (prgrm[line].first == "LOAD")
        {
            dq.push_back(rg);
        }
        else if (prgrm[line].first == "PLUS")
        {
            int rg1 = dq.back();
            dq.pop_back();
            int rg2 = dq.back();
            dq.pop_back();
            dq.push_back(rg1 + rg2);
        }
        else if (prgrm[line].first == "TIMES")
        {
            int rg1 = dq.back();
            dq.pop_back();
            int rg2 = dq.back();
            dq.pop_back();
            dq.push_back(rg1 * rg2);
        }
        else if (prgrm[line].first == "IFZERO")
        {
            int rg1 = dq.back();
            dq.pop_back();
            if (rg1 == 0)
            {
                line = prgrm[line].second - 1;
            }
        }
        else if (prgrm[line].first == "DONE")
        {
            cout << dq.back() << endl;
            return 0;
        }

        line++;
    }
}