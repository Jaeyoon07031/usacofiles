#include <bits/stdc++.h>
using namespace std;

int tcc, n, trash, t;

int main()
{
    scanf("%d\n", &tcc);
    for (int tc = 0; tc < tcc; tc++)
    {
        deque<int> dq;
        string func = "";
        int dir = 0;
        bool error = false;

        cin >> func;
        scanf("%d\n%c", &n, &trash);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if (i != (n - 1))
            {
                scanf("%c", &trash);
            }
            dq.push_back(t);
        }

        scanf("%c\n", &trash);
        
        for (int c = 0; c < func.length(); c++)
        {
            if (func[c] == 'R')
            {
                dir = (dir + 1) % 2;
            }
            else if (func[c] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << endl;
                    error = true;
                    break;
                }
                else
                {
                    if (!dir)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
            }
        }
        
        if (!error)
        {
            int s = dq.size();

            cout << "[";

            if (!dq.empty())
            {
                if (!dir)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
            }

            while(!dq.empty())
            {
                cout << ",";

                if (!dir)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
            }
            cout << "]" << endl;
        }
    }
}