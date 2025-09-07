#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0 && (b / 2) % 2 == 1)) {
            cout << -1 << endl;
        } else {
            if (a % 2 == 1 && b % 2 == 1) {
                cout << a * b + 1 << endl;
            } else {
                cout << a * (b / 2) + 2 << endl;
            }
        }
    }
    return 0;
}
