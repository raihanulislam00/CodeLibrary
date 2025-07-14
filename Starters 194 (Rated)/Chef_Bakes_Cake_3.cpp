#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int m = 0;
        f(i,n) {
            cin >> a[i];
            m = max(m, a[i]);
        }

        ll ans = 0;
        for (int x = 0; x <= m; x++) {
            ll s = 0;
            f(i,n) s += min(x, a[i]);
            ll rev = 50LL * s;
            ll cst = 30LL * x * n;
            ans = max(ans, rev - cst);
        }
        cout << ans << '\n';
    }

    return 0;
}