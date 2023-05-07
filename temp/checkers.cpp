#include <bits/stdc++.h>
using namespace std;

int n, bchkc;
int bchk[35][35];
vector<pair<int, int>> bkng, bpth;
bool s;

struct chks
{
    int arr[35][35];
};

bool isValid(int x, int y)
{
    if (x < n && x >= 0 && y < n && y >= 0)
    {
        return true;
    }
    return false;
}

chks chkstr;

void rcs(chks chk, vector<pair<int, int>> kng, vector<pair<int, int>> pth, int chkc, int k, int kxc, int kyc)
{
    kng[k].first = kng[k].first + kxc;
    kng[k].second = kng[k].second + kyc;

    pair<int, int> tp;
    tp.first = kng[k].first;
    tp.second = kng[k].second;
    pth.push_back(tp);

    if (isValid((kng[k].first + 1), (kng[k].second + 1)) && chk.arr[kng[k].first + 1][kng[k].second + 1]
    && isValid((kng[k].first + 2), (kng[k].second + 2)) && !chk.arr[kng[k].first + 2][kng[k].second + 2])
    {
        //cout << "found checker to bottom right, " << kng[k].first + 1 << ", " << kng[k].second + 1 << endl;
        chk.arr[kng[k].first + 1][kng[k].second + 1] = 0;
        rcs(chk, kng, pth, chkc - 1, k, 2, 2);
    }

    if (isValid((kng[k].first + 1), (kng[k].second - 1)) && chk.arr[kng[k].first + 1][kng[k].second - 1]
    && isValid((kng[k].first + 2), (kng[k].second - 2)) && !chk.arr[kng[k].first + 2][kng[k].second - 2])
    {
        //cout << "found checker to top right, " << kng[k].first + 1 << ", " << kng[k].second - 1 << endl;
        chk.arr[kng[k].first + 1][kng[k].second - 1] = 0;
        rcs(chk, kng, pth, chkc - 1, k, 2, -2);
    }

    if (isValid((kng[k].first - 1), (kng[k].second + 1)) && chk.arr[kng[k].first - 1][kng[k].second + 1]
    && isValid((kng[k].first - 2), (kng[k].second + 2)) && !chk.arr[kng[k].first - 2][kng[k].second + 2])
    {
        //cout << "found checker to bottom left, " << kng[k].first - 1 << ", " << kng[k].second + 1 << endl;
        chk.arr[kng[k].first - 1][kng[k].second + 1] = 0;
        rcs(chk, kng, pth, chkc - 1, k, -2, 2);
    }

    if (isValid((kng[k].first - 1), (kng[k].second - 1)) && chk.arr[kng[k].first - 1][kng[k].second - 1]
    && isValid((kng[k].first - 2), (kng[k].second - 2)) && !chk.arr[kng[k].first - 2][kng[k].second - 2])
    {
        //cout << "found checker to top left, " << kng[k].first - 1 << ", " << kng[k].second - 1 << endl;
        chk.arr[kng[k].first - 1][kng[k].second - 1] = 0;
        rcs(chk, kng, pth, chkc - 1, k, -2, -2);
    }

    if (chkc == 0)
    {
        for (int i = 0; i < pth.size(); i++)
        {
            cout << pth[i].second + 1 << " " << pth[i].first + 1 << endl;
        }
        s = true;
    }
}

int main()
{
    scanf("%d\n", &n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n + 1; x++)
        {
            char c;
            scanf("%c", &c);
            if (y != n)
            {
                if (c == 'o')
                {
                    chkstr.arr[x][y] = 1;
                    bchkc++;
                }
                else if (c == 'K')
                {
                    pair<int, int> tp;
                    tp.first = x;
                    tp.second = y;
                    bkng.push_back(tp);
                }
            }
        }
    }

    for (int i = 0; i < bkng.size(); i++)
    {
        //cout << "trying with starting king " << i << " which is at " << bkng[i].first << ", " << bkng[i].second << endl;
        rcs(chkstr, bkng, bpth, bchkc, i, 0, 0);
    }

    if (!s)
    {
        cout << "impossible" << endl;
    }
}