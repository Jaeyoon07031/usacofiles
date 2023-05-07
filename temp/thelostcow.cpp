#include <bits/stdc++.h>
using namespace std;

int x, y, goal, curr, dist;
bool behindcow;

int main()
{
    scanf("%d%d", &x, &y);
    curr = x;

    if (x < y)
    {
        behindcow = true;
        //cout << "starting behind the cow" << endl;
    }

    while (true)
    {
        if (goal == 0)
        {
            goal = -1;
        }
        else
        {
            goal = goal * 2;
        }

        goal = goal * (-1);

        //cout << "goal is " << goal << endl;
        //cout << "want to go to " << x + goal << endl;
        //cout << "extra distance from this is " << abs(curr - (x + goal)) << endl;

        dist = dist + abs(curr - (x + goal));
        curr = x + goal;

        //cout << "new total distance is " << dist << endl;
        //cout << "now at " << curr << endl;

        if (behindcow && curr >= y)
        {
            //cout << "at or went past y" << endl;
            dist = dist - (curr - y);
            //cout << "extra distance is " << curr - y << endl;
            //cout << "total distance is now " << dist << endl;
            break;
        }
        else if (!behindcow && curr <= y)
        {
            //cout << "at or went behind y" << endl;
            dist = dist - (y - curr);
            //cout << "extra distance is " << y - curr << endl;
            //cout << "total distance ise now " << dist << endl;
            break;
        }
    }
    cout << dist << endl;
}