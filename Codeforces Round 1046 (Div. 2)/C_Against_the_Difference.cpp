#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> v(n+1);
        vector<int> dp(n+1, 0);
        vector<int> p(n+1, 0);
        
        int temp = 0;
        for (int i = 1; i <= n; i++) {
            int x = a[i-1];
            v[x].push_back(i);
            int c = v[x].size();
            if (c >= x) {
                int s = v[x][c - x];
                dp[x] = max(dp[x], p[s - 1] + x);
            }
            temp = max(temp, dp[x]);
            p[i] = temp;
        }   
        cout << p[n] << endl;
    }
    return 0;
}