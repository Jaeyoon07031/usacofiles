#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        size_t searchResult = input.find("MOO");
        if (searchResult != string::npos)
        {
            cout << input.length() - 3 << endl;
            continue;
        }
        searchResult = input.find("MOM");
        if (searchResult != string::npos)
        {
            cout << input.length() - 3 + 1 << endl;
            continue;
        }
        searchResult = input.find("OOO");
        if (searchResult != string::npos)
        {
            cout << input.length() - 3 + 1 << endl;
            continue;
        }
        searchResult = input.find("OOM");
        if (searchResult != string::npos)
        {
            cout << input.length() - 3 + 2 << endl;
            continue;
        }
        cout << -1 << endl;
    }

}