#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int total = n1 + n2 + n3;
        int k = min({n1, n3, total / 3});
        cout << k << endl;
    }
    return 0;
}