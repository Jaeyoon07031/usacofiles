#include <bits/stdc++.h>
using namespace std;

int testCases;

int main()
{
    scanf("%d\n", &testCases);
    for (int tc = 0; tc < testCases; tc++)
    {
        string input;
        deque<char> front, back;
        cin >> input;
        for (int ch = 0; ch < input.length(); ch++)
        {
            
            if (input[ch] == '-')
            {
                if (!front.empty())
                {
                    front.pop_back();
                }
            }
            else if (input[ch] == '<')
            {
                if (!front.empty())
                {
                    back.push_front(front.back());
                    front.pop_back();
                }
            }
            else if (input[ch] == '>')
            {
                if (!back.empty())
                {
                    front.push_back(back.front());
                    back.pop_front();
                }
            }
            else
            {
                front.push_back(input[ch]);
            }
        }
        
        while(!front.empty())
        {
            cout << front.front();
            front.pop_front();
        }
        while(!back.empty())
        {
            cout << back.front();
            back.pop_front();
        }
        cout << endl;
    }
}