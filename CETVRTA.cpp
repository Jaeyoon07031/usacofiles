#include <bits/stdc++.h>
using namespace std;

int xc1, yc1, xc2, yc2, xc3, yc3;

int main()
{
	scanf("%d%d%d%d%d%d", &xc1, &yc1, &xc2, &yc2, &xc3, &yc3);
	
	if (xc1 == xc2)
	{
		printf("%d ", xc3);
	}
	else if (xc1 == xc3)
	{
		printf("%d ", xc2);
	}
	else
	{
		printf("%d ", xc1);
	}

	if (yc1 == yc2)
	{
		printf("%d", yc3);
	}
	else if (yc1 == yc3)
	{
		printf("%d", yc2);
	}
	else
	{
		printf("%d", yc1);
	}
}
