#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += min(v1[i], v2[i]);
    while (q--) {
        char c;
        int x;
        int v;
        cin >> c >> x >> v;
        x--;
        ans -= min(v1[x], v2[x]);
        if (c == 'A') v1[x] = v;
        else v2[x] = v;
        ans += min(v1[x], v2[x]);
        cout << ans << "\n";
    }
}
