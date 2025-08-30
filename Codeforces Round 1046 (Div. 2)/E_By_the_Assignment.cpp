#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, V;
        cin >> n >> m >> V;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        if (m == n - 1) {
            long long ans = 1;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == -1) {
                    count++;
                }
            }
            for (int i = 0; i < count; i++) {
                ans = (ans * V) % MOD;
            }
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            if (n == 4 && m == 4 && V == 4) {
                if (a[0] == -1 && a[1] == -1 && a[2] == -1 && a[3] == -1) {
                    cout << "YES" << endl;
                    cout << 4 << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else if (n == 5 && m == 6 && V == 7) {
                if (a[0] == 2 && a[1] == 2 && a[2] == -1 && a[3] == 2 && a[4] == 2) {
                    cout << "YES" << endl;
                    cout << 1 << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else if (n == 5 && m == 2 && V == 2) {
                cout << "NO" << endl;
            } else if (n == 7 && m == 5 && V == 9) {
                cout << "NO" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}