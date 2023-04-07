#include <bits/stdc++.h>
using namespace std;

long long n, f[1000010];
long long mod = 1000000007;


int main()
{
    scanf("%lld", &n);

    f[6] = 1;
    
    for (long long i = 7; i < n + 7; i++)
    {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4] + f[i - 5] + f[i - 6]) % mod;
    }

    cout << f[n + 6] << endl;
}