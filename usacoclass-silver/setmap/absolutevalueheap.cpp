#include <bits/stdc++.h>
using namespace std;

multiset<int> neg, pos;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%d", &ipt);
        if (ipt == 0)
        {
            if(neg.empty() && pos.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                if (!neg.empty() && !pos.empty())
                {
                    auto posIter = pos.begin();
                    auto negIter = neg.end();
                    negIter--;

                    int posVal = *posIter;
                    int negVal = *negIter;

                    if (abs(posVal) < abs(negVal))
                    {
                        cout << posVal << '\n';
                        pos.erase(posIter);
                    }
                    else
                    {
                        cout << negVal << '\n';
                        neg.erase(negIter);
                    }
                }
                else if (neg.empty())
                {
                    auto posIter = pos.begin();
                    cout << *posIter << '\n';
                    pos.erase(posIter);
                }
                else
                {
                    auto negIter = neg.end();
                    negIter--;
                    cout << *negIter << '\n';
                    neg.erase(negIter);
                }
            }
        }
        else
        {
            if (ipt > 0)
            {
                pos.insert(ipt);
            }
            else
            {
                neg.insert(ipt);
            }
        }
    }
}