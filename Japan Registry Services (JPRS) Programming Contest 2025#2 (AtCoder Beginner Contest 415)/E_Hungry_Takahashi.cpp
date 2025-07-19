#include <bits/stdc++.h>
using namespace std;
#define int long long
const int ni = -1000000000000000000LL;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    int t = h + w - 1;
    vector<int> p(t);
    for (int i = 0; i < t; i++) {
        cin >> p[i];
    }
    
    vector<int> q(t + 1, 0);
    for (int i = 1; i <= t; i++) {
        q[i] = q[i - 1] + p[i - 1];
    }

    int l = 0, r = 0;
    for (int i = 1; i <= t; i++) {
        if (q[i] > r) r = q[i];
    }
    int ans = r;
    
    while (l <= r) {
        int m = (l + r) / 2;
        vector<int> dp(w, ni);
        
        if (a[0][0] >= q[1] - m) {
            dp[0] = a[0][0];
        } else {
            l = m + 1;
            continue;
        }
        
        bool ok = true;
        for (int i = 0; i < h && ok; i++) {
            vector<int> nd(w, ni);
            for (int j = 0; j < w; j++) {
                if (i == 0 && j == 0) {
                    nd[j] = dp[j];
                    continue;
                }
                
                int k = i + j + 1;
                int tn = q[k] - m;
                int cv = ni;
                
                if (i > 0 && dp[j] != ni) {
                    cv = max(cv, dp[j]);
                }
                if (j > 0 && nd[j - 1] != ni) {
                    cv = max(cv, nd[j - 1]);
                }
                
                if (cv == ni) {
                    nd[j] = ni;
                } else {
                    int th = cv + a[i][j];
                    if (th >= tn) {
                        nd[j] = th;
                    } else {
                        nd[j] = ni;
                    }
                }
            }
            dp = nd;
        }
        
        if (dp[w - 1] != ni) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}