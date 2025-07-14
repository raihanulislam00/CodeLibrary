#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int total = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[i][j] == '1') {
                    cnt++;
                }
            }
            total = (total * cnt) % mod;
        }
        int h = n / 2;
        int b = 1;
        for (int i = 0; i < h; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[i][j] == '1' && v[i + h][j] == '1') {
                    cnt++;
                }
            }
            b = (b * cnt) % mod;
        }
        int ans = (total - b) % mod;
        if (ans < 0) {
            ans += mod;
        }
        cout << ans << '\n';
    }
    return 0;
}