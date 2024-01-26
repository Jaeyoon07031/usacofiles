#include <bits/stdc++.h>
using namespace std;

const int ARR_SIZE = 10;
int n, ans, goal[ARR_SIZE], diff[ARR_SIZE], loc[ARR_SIZE];
vector<int> arr;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        loc[tmp] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> goal[i];
        diff[goal[i]] = loc[goal[i]] - i;
    }
    
    while (true)
    {
        int largestVal = -INT_MAX;
        int largestIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (diff[i] > largestVal)
            {
                largestVal = diff[i];
                largestIndex = i;
            }
            
            int numberToMove = arr.at(largestIndex);
            arr.erase(arr.begin() + largestIndex);
            arr.insert(arr.begin() + largestIndex - largestVal, numberToMove);
        }
    }
}