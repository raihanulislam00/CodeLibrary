#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        for(int i=0;i<n;i++) {
            int x = n + 1 - v[i];
            cout << x << (i+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
