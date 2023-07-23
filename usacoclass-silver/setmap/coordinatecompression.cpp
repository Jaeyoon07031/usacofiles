#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binaryHeap[1000005], originalInput[1000005], uniqueCount;
ll nodeCount = -1, n;
map<ll, ll> compressedCoords, duplicates;

ll parentNode(ll i)
{
    return (i - 1) / 2;
}

void shiftUp(ll node)
{
    while (node > 0 && binaryHeap[parentNode(node)] > binaryHeap[node])
    {
        swap(binaryHeap[parentNode(node)], binaryHeap[node]);
        node = parentNode(node);
    }
}

void shiftDown(ll node)
{
    ll maxIndex = node;
    ll l = ((2 * node) + 1);
    ll r = ((2 * node) + 2);
 
    if (binaryHeap[l] < binaryHeap[maxIndex] && l <= nodeCount)
    {
        maxIndex = l;
    }
    if (binaryHeap[r] < binaryHeap[maxIndex] && r <= nodeCount)
    {
        maxIndex = r;
    }
 
    if (node != maxIndex)
    {
        swap(binaryHeap[node], binaryHeap[maxIndex]);
        shiftDown(maxIndex);
    }
}

ll extractMin()
{
    ll minValue = binaryHeap[0];
 
    binaryHeap[0] = binaryHeap[nodeCount];
    nodeCount--;

    shiftDown(0);
    return minValue;
}

void insertNode(ll value)
{
    nodeCount++;
    binaryHeap[nodeCount] = value;
    shiftUp(nodeCount);
}

int main()
{
    scanf("%d\n", &n);
    for (ll i = 0; i < n; i++)
    {
        ll ipt;
        scanf("%lld", &ipt);
        if (duplicates[ipt] == 0)
        {
            uniqueCount++;
            insertNode(ipt);
        }
        duplicates[ipt] = duplicates[ipt] + 1;
        originalInput[i] = ipt;
    }
    for (ll i = 0; i < uniqueCount; i++)
    {
        ll val = extractMin();
        if (compressedCoords.count(val) == 0)
        {
            compressedCoords[val] = i;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << compressedCoords[originalInput[i]] << " ";
    }
    cout << endl;
}