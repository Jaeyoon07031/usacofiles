#include <bits/stdc++.h>
using namespace std;

int n, p;
int value[15005];

void intAdd(int idx, int u)
{
    cout << "INTADD: adding " << u << " to index " << idx << endl;
    value[idx] = value[idx] + u;
    if (value[idx] >= 10)
    {
        cout << "INTADD: value overflowing" << endl;
        value[idx] = value[idx] - 10;
        intAdd(idx + 1, 1);
    }
}

void square()
{
    cout << "SQUARE: squaring begin" << endl;
    for (int i = 0; i < 100; i++)
    {
        // make upper bound for i higher
        if (value[i] != 0)
        {
            cout << "SQUARE: digit " << i << " is not zero" << endl;
            long long squaredNumber = value[i] * n;
            cout << "SQUARE: squared number is for this digit is " << squaredNumber << endl;
            string squaredString = to_string(squaredNumber);
            reverse(squaredString.begin(), squaredString.end());
            for (int j = 0; j < squaredString.length(); j++)
            {
                cout << "SQUARE: adding " << squaredString[j] << " to digit " << j << endl;
                intAdd(i + j, squaredString[j]);
            }
        }
    }
}

void fast_exp(int power)
{
    cout << "FAST_EXP: squaring with power " << power << endl;
    if (power == 1)
    {
        cout << "FAST_EXP: power is 1, returning" << endl;
        return;
    }
    else if (power == 0)
    {
        cout << "FAST_EXP: power is 0, returning" << endl;
        return;
    }
    else if (power % 2 == 0)
    {
        cout << "FAST_EXP: power is even, squaring once" << endl;
        square();
        fast_exp(power / 2);
    }
    else if (power % 2 == 1)
    {
        cout << "FAST_EXP: power is odd, squaring twice" << endl;
        square();
        square();
        fast_exp((power - 1) / 2);
    }
}


int main()
{
    scanf("%d%d", &n, &p);
    string input = to_string(n);
    reverse(input.begin(), input.end());
    for (int i = 0; i < input.length(); i++)
    {
        value[i] = input[i] - 48;
    }

    fast_exp(p);

    for (int i = 0; i < 100; i++)
    {
        cout << value[i];
    }
}