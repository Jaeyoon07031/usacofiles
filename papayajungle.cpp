#include <bits/stdc++.h>
using namespace std;

int r, c, ppy[45][45], xloc, yloc, score, test;

int main()
{
    scanf("%d%d", &c, &r);
    for (int y = 0; y < c; y++)
    {
        for (int x = 0; x < r; x++)
        {
            scanf("%d", &ppy[x][y]);
        }
    }

    while(true)
    {
        score = score + ppy[xloc][yloc];
        ppy[xloc][yloc] = -1;

        if (xloc == (r - 1) && yloc == (c - 1))
        {
            break;
        }

        int nc = -1, ec = -1, wc = -1, sc = -1;

        if (yloc != 0)
        {
            nc = ppy[xloc][yloc - 1];
        }
        if (xloc != (r - 1))
        {
            ec = ppy[xloc + 1][yloc];
        }
        if (yloc != (c - 1))
        {
            sc = ppy[xloc][yloc + 1];
        }
        if (xloc != 0)
        {
            wc = ppy[xloc - 1][yloc];
        }

        if (nc > ec && nc > sc && nc > wc)
        {
            yloc--;
        }
        else if (ec > nc && ec > sc && ec > wc)
        {
            xloc++;
        }
        else if (sc > nc && sc > ec && sc > wc)
        {
            yloc++;
        }
        else if (wc > nc && wc > ec && wc > sc)
        {
            xloc--;
        }
    }

    cout << score << endl;
}