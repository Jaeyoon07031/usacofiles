#include <bits/stdc++.h>
using namespace std;

int gx, gy, cwc;

void rec(int rx, int ry, int ct)
{
    //cout << "at a square sized " << rx << ", " << ry << endl;
    if ((rx % 2) == 1 && (ry % 2) == 1)
    {
        //cout << "center exists for this square" << endl;
        int cx = (rx + 1) / 2;
        int cy = (ry + 1) / 2;
        //cout << "this center is at " << cx << ", " << cy << endl;
    }
    else
    {
        //cout << "center does not exist for this square, returning" << endl;
        return;
    }

    //cout << "adding one cow to the grid" << endl;
    cwc = cwc + ct;

    if (rx != 1 && ry != 1)
    {
        rec((rx - 1) / 2, (ry - 1) / 2, ct * 4);
    }
    else
    {
        //cout << "too small to continue going, returning" << endl;
        return;
    }
}

int main()
{
    scanf("%d%d", &gx, &gy);
    
    rec(gx, gy, 1);

    cout << cwc << endl;
}