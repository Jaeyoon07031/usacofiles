#include <bits/stdc++.h>
using namespace std;

int arrA[105], arrB[105], correctIndex[105];
int n;

bool alrInv[105];
int cycleCt, largestCycle;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrA[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrB[i]);
        correctIndex[arrB[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (alrInv[i])
        {
            //cout << "this cow has already been involved in a previous cycle, skipping" << endl;
            continue;
        }
        if (arrA[i] == arrB[i])
        {
            //cout << "this cow is already in the correct location, skipping" << endl;
            continue;
        }

        cycleCt++;
        int cycleSize = 0;
        int cycleBegin = i;
        
        while (true)
        {
            //cout << "cow " << arrA[cycleBegin] << " going to correct location " << correctIndex[arrA[cycleBegin]] << endl;
            alrInv[arrA[cycleBegin]];
            cycleSize++;
            int oldCow = arrA[correctIndex[arrA[cycleBegin]]];
            arrA[correctIndex[arrA[cycleBegin]]] = arrA[cycleBegin];
            arrA[cycleBegin] = oldCow;
            if (correctIndex[arrA[cycleBegin]] == cycleBegin)
            {
                break;
            }
        }

        if (cycleSize > largestCycle)
        {
            largestCycle = cycleSize;
        }
    }

    if (cycleCt > 0)
    {
        cout << cycleCt << " " << largestCycle + 1 << endl;
    }
    else
    {
        cout << "0 -1" << endl;
    }
}