#include <bits/stdc++.h>
using namespace std;
#define innt long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (n > 0) {
            int temp = b[0];
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (b[i] > 2 * temp - 1) {
                    flag = false;
                    break;
                }
                temp = min(temp, b[i]);
            }
            if (flag) cout << "YES"<<endl;
            else cout << "NO"<<endl;
        } else {
            cout << "YES"<<endl;
        }
    }
    return 0;
}
