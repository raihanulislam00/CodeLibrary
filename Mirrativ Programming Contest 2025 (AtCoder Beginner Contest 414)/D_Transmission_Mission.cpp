#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (m >= n) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> v1;
    v1.reserve(n - 1);
    for (int i = 1; i < n; i++) {
        v1.push_back(v[i] - v[i - 1]);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < m - 1; i++) {
        sum += v1[i];
    }
    int total = v.back() - v.front();
    cout << (total - sum) << "\n";
    return 0;
}
