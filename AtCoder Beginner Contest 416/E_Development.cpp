#include<bits/stdc++.h>
using namespace std;
const long long I = (long long)1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> g(n, vector<long long>(n, I));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        if (c < g[a][b]) {
            g[a][b] = c;
            g[b][a] = c;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (g[i][k] == I) continue;
            for (int j = 0; j < n; j++) {
                if (g[k][j] != I) {
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
    }
    int k;
    long long t;
    cin >> k >> t;
    vector<bool> ap(n, false);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        d--;
        ap[d] = true;
    }
    vector<long long> f(n, I);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ap[j] && g[i][j] < f[i]) {
                f[i] = g[i][j];
            }
        }
    }
    int q;
    cin >> q;
    for (int x = 0; x < q; x++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            u--; v--;
            if (w < g[u][v]) {
                g[u][v] = w;
                g[v][u] = w;
            }
            vector<int> mid = {u, v};
            for (int k : mid) {
                for (int i = 0; i < n; i++) {
                    if (g[i][k] == I) continue;
                    for (int j = 0; j < n; j++) {
                        if (g[k][j] != I && g[i][j] > g[i][k] + g[k][j]) {
                            g[i][j] = g[i][k] + g[k][j];
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                f[i] = I;
                for (int j = 0; j < n; j++) {
                    if (ap[j] && g[i][j] < f[i]) {
                        f[i] = g[i][j];
                    }
                }
            }
        } else if (tp == 2) {
            int u;
            cin >> u;
            u--;
            ap[u] = true;
            for (int i = 0; i < n; i++) {
                if (g[i][u] < f[i]) {
                    f[i] = g[i][u];
                }
            }
        } else if (tp == 3) {
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    long long d = g[i][j];
                    if (f[i] < I && f[j] < I) {
                        long long fl = t + f[i] + f[j];
                        if (fl < d) {
                            d = fl;
                        }
                    }
                    if (d >= I) {
                        d = 0;
                    }
                    ans += d;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}