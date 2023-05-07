#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, bx, by;
int ort[205], xi[205], yi[205];
bool p;

char d;
int x, y, lx, ly, bi;

bool simul()
{
	d = 'E';
	x = 0, y = 0;

	while (true)
	{
		//cout << "direction is " << d << endl;
		//cout << "x and y is " << x << " " << y << endl;
		if (d == 'N')
		{
			if (x == bx && y < by)
			{
				return true;
			}
			ly = 10000005, bi = -1;
			for (int i = 0; i < n; i++)
			{
				//cout << " x index of " << i << " is " << xi[i] << endl;
				if (xi[i] == x)
				{
					if (ly > yi[i] && yi[i] != y && yi[i] > y)
					{
						ly = yi[i];
						bi = i;
					}
				}
			}
			//cout << "closest mirror index is " << bi << " with x, y " << xi[bi] << " " << yi[bi] << endl;
			if (bi == -1)
			{
				return false;
			}
			else if (ort[bi] == 0)
			{
				d = 'E';
			}
			else
			{
				d = 'W';
			}
		}
		else if (d == 'E')
		{
			if (y == by && x < bx)
			{
				return true;
			}
			lx = 10000005, bi = -1;
			for (int i = 0; i < n; i++)
			{
				//cout << " y index of " << i << " is " << yi[i] << endl;
				if (yi[i] == y)
				{
					if (lx > xi[i] && xi[i] != x && xi[i] > x)
					{
						lx = xi[i];
						bi = i;
					}
				}
			}
			//cout << "closest mirror index is " << bi << " with x, y " << xi[bi] << " " << yi[bi] << endl;
			if (bi == -1)
			{
				return false;
			}
			else if (ort[bi] == 0)
			{
				d = 'N';
			}
			else
			{
				d = 'S';
			}
		}
		else if (d == 'S')
		{
			if (x == bx && y > by)
			{
				return true;
			}
			ly = -10000005, bi = -1;
			for (int i = 0; i < n; i++)
			{
				if (xi[i] == x)
				{
					if (ly < yi[i] && yi[i] != y && yi[i] < y)
					{
						ly = yi[i];
						bi = i;
					}
				}
			}
			//cout << "closest mirror index is " << bi << " with x, y " << xi[bi] << " " << yi[bi] << endl;
			if (bi == -1)
			{
				return false;
			}
			else if (ort[bi] == 0)
			{
				d = 'W';
			}
			else
			{
				d = 'E';
			}
		}
		else if (d == 'W')
		{
			if (y == by && x > bx)
			{
				return true;
			}
			lx = -10000005, bi = -1;
			for (int i = 0; i < n; i++)
			{
				if (yi[i] == y)
				{
					if (lx < xi[i] && xi[i] != x && xi[i] < x)
					{
						lx = xi[i];
						bi = i;
					}
				}
			}
			//cout << "closest mirror index is " << bi << " with x, y " << xi[bi] << " " << yi[bi] << endl;
			if (bi == -1)
			{
				return false;
			}
			else if (ort[bi] == 0)
			{
				d = 'S';
			}
			else
			{
				d = 'N';
			}
		}
		x = xi[bi];
		y = yi[bi];
	}
}

int main()
{
	scanf("%d%d%d", &n, &bx, &by);
	for (int i = 0; i < n; i++)
	{
		char mo;
		scanf("%d%d %c", &xi[i], &yi[i], &mo);
		if (mo == '/')
		{
			ort[i] = 0;
		}
		else
		{
			ort[i] = 1;
		}
	}

	if (simul())
	{
		cout << 0 << endl;
		p = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (p)
		{
			break;
		}
		//cout << "simulating with mirror " << i << " flipped from " << ort[i] << " to ";
		ort[i] = 1 - ort[i];
		//cout << ort[i] << endl;
		if (simul())
		{
			cout << i + 1 << endl;
			p = true;
		}
		ort[i] = 1 - ort[i];
		//cout << "mirror " << i << " returned to " << ort[i] << endl;
	}
	
	if (!p)
	{
		cout << "-1" << endl;
	}
}
