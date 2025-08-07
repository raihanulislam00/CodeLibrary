#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int x : b) {
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it != a.end() && *it == x) {
            a.erase(it);
        }
    }

    for (int num : a) {
        cout << num << " ";
    }
    return 0;
}