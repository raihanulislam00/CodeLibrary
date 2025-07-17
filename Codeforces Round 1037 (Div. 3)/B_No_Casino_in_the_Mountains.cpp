#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> v(n+1, 0);
        for (int i = 0; i < n; i++) {
            v[i+1] = v[i] + arr[i];
        }

        vector<bool> v1(n, false);
        for (int i = 0; i <= n-k; i++) {
            if (v[i+k] - v[i] == 0) {
                v1[i] = true;
            }
        }

        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            if (!v1[i]) {
                dp[i] = dp[i+1];
            } else {
                int x = i + k + 1;
                if (x > n) {
                    dp[i] = max(dp[i+1], 1LL);
                } else {
                    dp[i] = max(dp[i+1], 1LL + dp[x]);
                }
            }
        }
        cout << dp[0] << '\n';
    }
    return 0;
}