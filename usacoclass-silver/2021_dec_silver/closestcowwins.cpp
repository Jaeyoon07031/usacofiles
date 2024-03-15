#include <bits/stdc++.h>
using namespace std;

struct node{
    int range1, range2;
    int value;
    int cc;
    vector<node> children;
};

node root;

void increase(node*& parent, int range1, int range2, int value)
{
    if ((*parent).cc == 0)
    {
        if ((*parent).range1 == range1 && (*parent).range2 == range2)
        {
            (*parent).value += value;
        }
        else
        {
            (*parent).cc++;
            (*parent).children.push_back({range1, range2, (*parent).value + value, 0});
        }
    }
    else
    {
        bool matched = false;
        for (int i = 0; i < (*parent).children.size(); i++)
        {
            node* ptr = &((*parent).children[i]);
            if ((*parent).children[i].range1 <= range1 && (*parent).children[i].range2 >= range2)
            {
                increase(ptr, range1, range2, value);
                matched = true;
                break;
            }
        }

        if (!matched)
        {
            (*parent).cc++;
            (*parent).children.push_back({range1, range2, value, 0});
            node& newNode = (*parent).children[(*parent).children.size() - 1];
            node* ptr = &newNode;
            for (int i = 0; i < (*parent).children.size(); i++)
            {
                int orange1 = (*parent).children[i].range1;
                int orange2 = (*parent).children[i].range2;
                int ovalue = (*parent).children[i].value;

                if (orange1 >= range1 && orange2 <= range2)
                {
                    newNode.cc++;
                    newNode.children.push_back((*parent).children[i]);
                }
                else
                {
                    if (orange1 >= range1)
                    {

                        increase(ptr, orange1, range2, ovalue);
                        (*parent).cc++;
                        (*parent).children.push_back({range2, orange2, value, 0});
                    }
                    else if (orange2 <= range2)
                    {
                        increase(ptr, range1, orange2, ovalue);
                        (*parent).cc++;
                        (*parent).children.push_back({orange1, range1, value, 0});
                    }
                }
            }
        }
    }
}

int main()
{
    root = {-INT_MAX, INT_MAX, 0, 0};

    node* ptr = &root;

    increase(ptr, 2, 5, 1);
    increase(ptr, 3, 4, 2);
    increase(ptr, 1, 2, 3);

    cout << endl;
}