#include <bits/stdc++.h>
using namespace std;

int tc;

int main()
{
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++)
    {
        string tc;
        bool valid = true;
        deque<int> dq;

        cin >> tc;

        for (int c = 0; c < tc.size(); c++)
        {
            if (tc[c] == '(')
            {
                //cout << "add 0" << endl;
                dq.push_back(0);
            }
            else
            {
                if (dq.size() != 0 && dq.back() == 0)
                {
                    //cout << "removing 0" << endl;
                    dq.pop_back();
                }
                else
                {
                    //cout << "not valid anymore" << endl;
                    valid = false;
                    break;
                }
            }
        }

        if (valid && dq.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}