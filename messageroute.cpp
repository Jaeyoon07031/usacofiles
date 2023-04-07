#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

bool visited[100005], added[100005], addedl[100005];
int father[100005], layer[100005], q[100005];
vector<int> conn[100005], iil[100005];
int n, m, h, t;
bool possible, stop;

void printQueue()
{
	cout << "current queue is ";
	for (int i = 0; i < 15; i++)
	{
		cout << q[i] << " ";
	}
	cout << " and h and t are " << h << " " << t << endl;
}

void printVars()
{
	cout << "h and t are " << h << " " << t << endl;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	for (int i = 0; i < conn[n].size(); i++)
	{
		layer[conn[n][i]] = 2;
		iil[2].push_back(conn[n][i]);
		//cout << "layer for " << conn[n][i] << " set to " << 2 << endl;
		addedl[conn[n][i]] = true;
	}

	iil[1].push_back(n);
	addedl[n] = true;

	for (int i = 0; stop == false; i++)
	{
		//cout << "doing for layer " << i + 2 << endl;
		//cout << "items in layer is " << iil[i + 2].size() << endl;
		for (int j = 0; j < iil[i + 2].size(); j++)
		{
			for (int k = 0; k < conn[iil[i + 2][j]].size(); k++)
			{
				if (!addedl[conn[iil[i + 2][j]][k]])
				{
					layer[conn[iil[i + 2][j]][k]] = i + 3;
					addedl[conn[iil[i + 2][j]][k]] = true;
					iil[i + 3].push_back(conn[iil[i + 2][j]][k]);
					//cout << "layer for " << conn[iil[i + 2][j]][k] << " set to " << i + 3 << endl;
				}
			}
		}
		if (iil[i + 2].size() == 0)
		{
			stop = true;
		}
	}

	q[t] = n;
	t++;

	while(h != t)
	{
		//cout << "currently at node " << q[h] << endl;
		//printQueue();
		//printVars();
		if (q[h] == 1)
		{
			printf("%d\n%d ", layer[q[h]], 1);
			int pf = father[q[h]];
			for (int i = 0; i < layer[q[h]] - 1; i++)
			{
				printf("%d ", pf);
				pf = father[pf];
			}
			possible = true;
		}
		visited[q[h]] = true;
		//cout << "length of connections is " << conn[q[h]].size() << endl;
		for (int i = 0; i < conn[q[h]].size(); i++)
		{
			//cout << "trying to connect to " << conn[q[h]][i] << endl;
			
			if (!visited[conn[q[h]][i]] && !added[conn[q[h]][i]])
			{
				q[t] = conn[q[h]][i];
				added[conn[q[h]][i]] = true;
				father[conn[q[h]][i]] = q[h];
				t++;
				//cout << "successfuly added with" << "father " << q[h] << endl;
			}
			else
			{
			//cout << "not added" << endl;
			}
		}
		h++;
	}
	if (!possible)
	{
		printf("%s", "IMPOSSIBLE");
	}
}