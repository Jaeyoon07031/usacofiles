#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binaryHeap[100005];
ll nodeCount = -1, n;

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
    nodeCount = nodeCount - 1;

    shiftDown(0);
    return minValue;
}

void insertNode(ll value)
{
    nodeCount = nodeCount + 1;
    binaryHeap[nodeCount] = value;
    shiftUp(nodeCount);
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll ipt;
        scanf("%lld", &ipt);
        if (ipt == 0)
        {
            if(nodeCount == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << extractMin() << endl;
            }
        } 
        else
        {
            insertNode(ipt);
        }
    }
}