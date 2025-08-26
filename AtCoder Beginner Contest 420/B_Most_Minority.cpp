#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> v(n, 0);
    for (int j = 0; j < m; j++) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '0') x++;
            else y++;
        }
        if (x == 0 || y == 0) {
            for (int i = 0; i < n; i++) v[i]++;
        } else if (x < y) {
            for (int i = 0; i < n; i++) if (s[i][j] == '0') v[i]++;
        } else {
            for (int i = 0; i < n; i++) if (s[i][j] == '1') v[i]++;
        }
    }
    int mx = *max_element(v.begin(), v.end());
    for (int i = 0; i < n; i++) if (v[i] == mx) cout << i + 1 << " ";
}
