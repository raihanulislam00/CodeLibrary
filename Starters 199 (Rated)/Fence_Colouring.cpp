#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[x]++;
        }
        int k = n - v[1];
        int m = n;
        for (int c = 1; c <= n; c++) {
            m = min(m, n - v[c]);
        }
        cout << min(k, 1 + m) << "\n";
    }
}
