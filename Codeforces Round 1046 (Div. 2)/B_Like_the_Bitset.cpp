#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        if (k == 1) {
            bool ok = false;
            for (char c : s) {
                if (c == '1') {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << endl;
            }
            continue;
        }
        
        int max = 0;
        int cur = 0;
        for (char c : s) {
            if (c == '1') {
                cur++;
                if (cur > max) {
                    max = cur;
                }
            } else {
                cur = 0;
            }
        }
        
        if (max >= k) {
            cout << "NO" << endl;
            continue;
        }
        
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (c == '0') cnt0++;
            else cnt1++;
        }
        
        vector<int> ans(n);
        int l = n - cnt0 + 1;
        int sm = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ans[i] = l++;
            } else {
                ans[i] = sm++;
            }
        }
        
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}