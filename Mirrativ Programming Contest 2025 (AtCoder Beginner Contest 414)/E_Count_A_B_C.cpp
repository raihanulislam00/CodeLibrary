#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int32_t main() {
    int n;
    cin >> n;

    int t1 = (n % mod) * ((n + 1) % mod) % mod;
    t1 = t1 * inv2 % mod;

    int d = 0;
    for (int i = 1, l; i <= n; i = l + 1) {
        int q = n / i;
        l = n / q;
        d += q * (l - i + 1);
    }

    int temp = d % mod;
    int ans = (t1 - temp + mod) % mod;
    cout << ans << endl;

    return 0;
}