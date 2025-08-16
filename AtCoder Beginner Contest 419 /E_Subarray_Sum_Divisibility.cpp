#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
int n, m, l;
cin >> n >> m >> l;
vector<int> a(n);
for (int i = 0; i < n; i++) {
cin >> a[i];
}
vector<vector<int>> c(l);
for (int i = 0; i < n; i++) {
c[i % l].push_back(i);
}
vector<vector<int>> cc(l, vector<int>(m, 0));
for (int r = 0; r < l; r++) {
for (int x = 0; x < m; x++) {
int t = 0;
for (int i : c[r]) {
t += (x >= a[i]) ? (x - a[i]) : (x + m - a[i]);
}
cc[r][x] = t;
}
}
vector<int> dp(m, LLONG_MAX);
dp[0] = 0;
for (int r = 0; r < l; r++) {
vector<int> nd(m, LLONG_MAX);
for (int s = 0; s < m; s++) {
if (dp[s] == LLONG_MAX) continue;
for (int x = 0; x < m; x++) {
int ns = (s + x) % m;
int cd = dp[s] + cc[r][x];
if (cd < nd[ns]) {
nd[ns] = cd;
}
}
}
dp = nd;
}
cout << (dp[0] == 0 ? 0 : dp[0]) << endl;
return 0;
}