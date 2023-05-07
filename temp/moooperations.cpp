#include <bits/stdc++.h>
using namespace std;

int n, o, l, fr, ts;
char t[101];
string s;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//cerr << "checking string no " << i << endl;
		scanf("%s", t);
		s = t;
		l = s.length();

		if (l <= 2)
		{
			//cerr << "length is 2, impossible" << endl;
			cout << -1 << endl;
			continue;
		}
		
		// LOOKING FOR WHOLE STRING

		fr = s.find("MOO");
		if (fr == -1)
		{
			//cerr << "whole string not found" << endl;
		}
		else
		{
			//cerr << "whole string found. required ops are " << l - 3 << endl;
			cout << l - 3 << endl;
			continue;
		}

		// LOOKING FOR OO
		
		fr = s.find("OO");
		if (fr == -1)
		{
			//cerr << "OO string not found" << endl;
		}
		else
		{
			ts = 0;
			while (fr == 0)
			{
				//cerr << "result is at front, checking for more" << endl;
				fr = s.find("OO", ts + 1);
			}
			if (fr != -1)
			{
				//cerr << "OO string found. required ops are " << l - 3 + 1 << endl;
				cout << l - 3 + 1;
				continue;
			}
			//cerr << "no OO string thats not at front" << endl;			
		}

		// LOOKING FOR OM

		fr = s.find("OM");
		if (fr == -1)
		{
			//cerr << "OM string not found" << endl;
		}
		else
		{
			ts = 0;
			while (fr == 0)
			{
				//cerr << "result is at front, checking for more" << endl;
				fr = s.find("OM", ts + 1);
			}
			if (fr != -1)
			{
				if (s[fr - 1] == 'M')
				{
					//cerr << "OM string found with M before. required ops are " << l - 3 + 1 << endl;
					cout << l - 3 + 1 << endl;
					continue;
				}
				else
				{
					//cerr << "OM string found without M before. required ops are " << l - 3 + 2 << endl;
					cout << l - 3 + 2 << endl;
					continue;
				}
			}
		}

		// NO MATCHES
		
		//cerr << "not possible" << endl;
		cout << -1 << endl;
	}
}
