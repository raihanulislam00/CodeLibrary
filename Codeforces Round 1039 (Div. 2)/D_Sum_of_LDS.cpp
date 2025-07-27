#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n+2);
        for (int i = 1; i <= n; ++i) cin >> p[i];
        int ans = n * (n + 1) / 2;
        for (int i = 1; i < n; ++i) {
            if (p[i] > p[i+1]) {
                ans += (int)i * (n - i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
