#include <bits/stdc++.h>
using namespace std;

int n, uniqueCount, originalInput[1000005];
set<int> s;
map<int, int> compressedCoords;

int main()
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%d", &ipt);
        s.insert(ipt);
        originalInput[i] = ipt;
    }
    uniqueCount = s.size();
    for (int i = 0; i < uniqueCount; i++)
    {
        int val = *s.begin();
        s.erase(s.begin());
        compressedCoords[val] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << compressedCoords[originalInput[i]] << " ";
    }
    cout << endl;
}

/*
int binaryHeap[1000005], originalInput[1000005], uniqueCount;
int nodeCount = -1, n;
map<int, int> compressedCoords, duplicates;

int parentNode(int i)
{
    return (i - 1) / 2;
}

void shiftUp(int node)
{
    while (node > 0 && binaryHeap[parentNode(node)] > binaryHeap[node])
    {
        swap(binaryHeap[parentNode(node)], binaryHeap[node]);
        node = parentNode(node);
    }
}

void shiftDown(int node)
{
    int maxIndex = node;
    int l = ((2 * node) + 1);
    int r = ((2 * node) + 2);
 
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

int extractMin()
{
    int minValue = binaryHeap[0];
 
    binaryHeap[0] = binaryHeap[nodeCount];
    nodeCount--;

    shiftDown(0);
    return minValue;
}

void insertNode(int value)
{
    nodeCount++;
    binaryHeap[nodeCount] = value;
    shiftUp(nodeCount);
}
*/