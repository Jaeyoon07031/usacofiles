#include <bits/stdc++.h>
using namespace std;

int len;
int targ;
int res;
int sum;
int head;
int tail;
int onemore;
int arr[200005];


int main()
{
	cin >> len;
	cin >> targ;
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}

	while (head != len || tail != len)
	{
		if (sum == targ)
		{
			if(tail == len)
			{
				onemore = 1;
			}
			res++;
			sum = sum + arr[tail];
 			tail++;
			sum = sum - arr[head];
			head++;
		}
		else if (sum > targ)
		{
			sum = sum - arr[head];
			head++;
		}
		else
		{
			sum = sum + arr[tail];
			tail++;
		}
		if (onemore == 1)
		{
			break;
		}
	}
	cout << res;
}
