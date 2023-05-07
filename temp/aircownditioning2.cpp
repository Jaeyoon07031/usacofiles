#include <bits/stdc++.h>
using namespace std;

int ac_r_s[15], ac_r_e[15], ac_m[15], ac_p[15], cr[105], c_r_s[25], c_r_e[25], c_r_w[25], tcr[105];
int n, m, cc, maxn, l, bm = INT_MAX;
bool eac[15], pass;

void checkCooling()
{
    for (int i = 0; i < 105; i++)
    {
        cerr << cr[i] << " ";
    }
    cerr << endl;
}

int main()
{
	// INPUT PROCESSING

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &c_r_s[i], &c_r_e[i], &c_r_w[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &ac_r_s[i], &ac_r_e[i], &ac_p[i], &ac_m[i]);
    }

    // CREATE COOLING REQUIREMENTS

    for (int i = 0; i < n; i++)
    {
        //cout << "for cow " << i << " cooling from " << c_r_s[i] << " to " << c_r_e[i] << " with " << c_r_w[i] << endl;
        for (int j = c_r_s[i]; j < c_r_e[i]; j++)
        {
            tcr[j] = tcr[j] + c_r_w[i];
        }
    }

    // CHECKING ALL PERMUTATIONS

    maxn = pow(2, m);
    for(int i = 0; i < maxn; i++)
    {
        //cerr << "permutation is ";
        /*for (int j = 0; j < m; j++)
        {
            cerr << eac[j];
        }
        cerr << endl;*/
        
        for (int j = 0; j < 105; j++)
        {
            cr[j] = 0;
        }
        cc = 0;

        //cerr << "reset cooling" << endl;

        for (int j = 0; j < m; j++)
        {
            if (eac[j])
            {
                //cerr << "ac " << j << " is enabled " << endl;
                //cerr << "cooling area from " << ac_r_s[j] << " to " << ac_r_e[j] << " by " << ac_p[j] << endl;
                cc = cc + ac_m[j];
                for (int k = ac_r_s[j]; k <= ac_r_e[j]; k++)
                {
                    cr[k] = cr[k] + ac_p[j];
                }
                //checkCooling();
            }
        }
        //cerr << "comparing with cows requirements" << endl;
        pass = true;
        for (int j = 0; j < 105; j++)
        {
            if (tcr[j] > cr[j])
            {
                pass = false;
            }
        }
        
        if (pass)
        {
            //cerr << "passed requirements with cost " << cc << endl;
            if (bm > cc)
            {
                bm = cc;
            }
        }
        
        l = m - 1;
        ckpt:
        if(eac[l] == false)
        {
            eac[l] = true;
        }
        else
        {
            eac[l] = false;
            l--;
            goto ckpt;
        }
    }

    cout << bm << endl;
}