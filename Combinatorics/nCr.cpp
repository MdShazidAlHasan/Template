#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;

int fac[MAXN], infac[MAXN];

int expo(int a, int b)
{
    if (b == 0)
        return 1;

    int x = expo(a, b / 2);
    x = x * x % mod;

    if (b % 2)
        x = x * a % mod;

    return x;
}

int inverse(int a)
{
    return expo(a, mod - 2);
}

void compute_factorials()
{
    fac[0] = 1;

    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % mod;

    infac[MAXN - 1] = inverse(fac[MAXN - 1]);

    for (int i = MAXN - 2; i >= 0; i--)
        infac[i] = infac[i + 1] * (i + 1) % mod;
}

int nCr(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;

    return fac[n] * infac[r] % mod * infac[n - r] % mod;
}

signed main()
{
    compute_factorials();

    int n, m;
    cin >> n >> m;

    cout << nCr(n, m) << '\n';
}