#include <bits/stdc++.h>
using namespace std;

struct transaction
{
    int cowX;
    int cowY;
    int time;
};

int n, t, pCowCt, minK = INT_MAX, maxK = 0;
array<int, 105> cowInf;
transaction transList[255];

bool transCompare(transaction structA, transaction structB)
{
    return structA.time < structB.time;
}

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%1d", &ipt);
        if (ipt)
        {
            cowInf[i] = 1;
        }
        else
        {
            cowInf[i] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        int tm, x, y;
        scanf("%d%d%d", &tm, &x, &y);
        transList[i].cowX = x - 1;
        transList[i].cowY = y - 1;
        transList[i].time = tm;
    }

    sort(transList, transList + t, transCompare);

    for (int cowi = 0; cowi < n; cowi++)
    {
        if (cowInf[cowi] == 0)
        {
            continue;
        }
        bool pPZero = false;
        for (int simK = 1; simK <= t; simK++)
        {
            //cout << "testing for patient zero " << cowi << ", K value " << simK << endl;
            array<int, 105> tCowInf;
            array<int, 105> transmitC;

            tCowInf.fill(0);
            transmitC.fill(0);

            tCowInf[cowi] = 1;

            for (int i = 0; i < t; i++)
            {
                //cout << "this transaction is id " << i << " at time " << transList[i].time << " for cows " << transList[i].cowX << " and " << transList[i].cowY << endl; 
                if (tCowInf[transList[i].cowX])
                {
                    //cout << "cow x is infected" << endl;
                    transmitC[transList[i].cowX]++;
                    if (tCowInf[transList[i].cowY])
                    {
                        transmitC[transList[i].cowY]++;
                    }
                    if (transmitC[transList[i].cowX] <= simK)
                    {
                        //cout << "cow x is capable of infecting with current K" << endl;
                        tCowInf[transList[i].cowY] = 1;
                    }
                }
                else if (tCowInf[transList[i].cowY])
                {
                    //cout << "cow y is infected" << endl;
                    if (tCowInf[transList[i].cowX])
                    {
                        transmitC[transList[i].cowX]++;
                    }
                    transmitC[transList[i].cowY]++;
                    if (transmitC[transList[i].cowY] <= simK)
                    {
                        //cout << "cow Y is capable of infecting with current K" << endl;
                        tCowInf[transList[i].cowX] = 1;  
                    }
                }
            }

            if (tCowInf == cowInf)
            {
                //cout << "comparison success" << endl;
                if (!pPZero)
                {
                    pCowCt++;
                    pPZero = true;
                }
                minK = min(minK, simK);
                maxK = max(maxK, simK);
            }
        }
    }

    cout << pCowCt << " " << minK << " ";
    if (maxK == t)
    {
        cout << "Infinity" << endl;
    }
    else
    {
        cout << maxK << endl;
    }
}