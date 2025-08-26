#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        vector<int> dp(n + 1, 0);
        dp[1] = h[0];
        for (int i = 1; i < n; ++i) {
            int opt1 = dp[i] + h[i] - 1;
            int opt2 = dp[i - 1] + h[i - 1] + max(0LL, h[i] - (int)i);
            dp[i + 1] = min(opt1, opt2);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
