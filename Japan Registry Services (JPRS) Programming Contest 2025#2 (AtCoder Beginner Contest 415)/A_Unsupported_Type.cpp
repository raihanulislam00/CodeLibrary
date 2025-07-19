#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
