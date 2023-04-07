#include <bits/stdc++.h>
using namespace std;

int binary[1000], inputBinary[1000];

void binaryAdd(int index)
{
    binary[index] = binary[index] + 1;
    if (binary[index] == 2)
    {
        binary[index] = 0;
        binaryAdd(index + 1);
    }
}

int main()
{
    string input;
    cin >> input;

    for (int i = 0; i < input.length() + 1; i++)
    {
        binary[i] = input[input.length() - i - 1];
        inputBinary[i] =  input[input.length() - i - 1];
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (inputBinary[i] == 49)
        {
            cout << "number at binary index " << i << " is a 1" << endl;
            binaryAdd(i + 4);
        }
    }

    for (int i = 0; i < input.length() + 4; i++)
    {
        cout << binary[input.length() + 4 - i];
    }
}