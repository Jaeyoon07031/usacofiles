#include <bits/stdc++.h>
using namespace std;

int binary[1050], inputBinary[1050];

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
    string input = "";
    string output = "";
    cin >> input;

    reverse(input.begin(), input.end());

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 48)
        {
            binary[i] = 0;
            inputBinary[i] = 0;
        }
        else
        {
            binary[i] = 1;
            inputBinary[i] = 1;
        }
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (inputBinary[i] == 1)
        {
            binaryAdd(i + 4);
        }
    }

    for (int i = 0; i < input.length() + 4; i++)
    {
        output = output + to_string(binary[i]);
    }

    reverse(output.begin(), output.end());

    cout << output << endl;
}