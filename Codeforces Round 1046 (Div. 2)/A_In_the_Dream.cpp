#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int r2 = c - a, k2 = d - b;
        
        bool flag = true;
        bool ok = true;
        
        if (a == 0) {
            if (b > 2) {
                flag = false;
            }
        } else if (b == 0) {
            if (a > 2) {
                flag = false;
            }
        } else {
            if (a > 2 * (b + 1) || b > 2 * (a + 1)) {
                flag = false;
            }
        }
        
        if (r2 == 0) {
            if (k2 > 2) {
                ok = false;
            }
        } else if (k2 == 0) {
            if (r2 > 2) {
                ok = false;
            }
        } else {
            if (r2 > 2 * (k2 + 1) || k2 > 2 * (r2 + 1)) {
                ok = false;
            }
        }
        
        if (flag && ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}