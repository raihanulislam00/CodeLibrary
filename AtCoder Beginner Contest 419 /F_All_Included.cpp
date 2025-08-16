#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Node {
    int nx[26], lk, o;
    Node() { memset(nx, -1, sizeof nx); lk = o = 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    if (!(cin >> n >> l)) return 0;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<Node> t(1);
    for (int i = 0; i < n; ++i) {
        int v = 0;
        for (char c : s[i]) {
            int x = c - 'a';
            if (t[v].nx[x] == -1) {
                t[v].nx[x] = t.size();
                t.emplace_back();
            }
            v = t[v].nx[x];
        }
        t[v].o |= (1 << i);
    }
    queue<int> q;
    for (int x = 0; x < 26; ++x) {
        int u = t[0].nx[x];
        if (u != -1) {
            t[u].lk = 0;
            q.push(u);
        } else {
            t[0].nx[x] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        t[v].o |= t[t[v].lk].o;
        for (int x = 0; x < 26; ++x) {
            int u = t[v].nx[x];
            if (u != -1) {
                t[u].lk = t[t[v].lk].nx[x];
                q.push(u);
            } else {
                t[v].nx[x] = t[t[v].lk].nx[x];
            }
        }
    }
    int sz = t.size(), m = 1 << n;
    vector<vector<int>> dp(sz, vector<int>(m)), nd(sz, vector<int>(m));
    dp[0][0] = 1;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < sz; ++j) fill(nd[j].begin(), nd[j].end(), 0);
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < m; ++k) {
                int cur = dp[j][k];
                if (!cur) continue;
                for (int x = 0; x < 26; ++x) {
                    int nj = t[j].nx[x], nk = k | t[nj].o;
                    nd[nj][nk] = (nd[nj][nk] + cur) % MOD;
                }
            }
        }
        dp.swap(nd);
    }
    int ans = 0;
    for (int j = 0; j < sz; ++j) {
        ans = (ans + dp[j][m-1]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}