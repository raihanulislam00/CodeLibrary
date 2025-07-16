#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
            if (sum < 40 * (i + 1)) {
                flag = true;
            }
        }
        if (flag) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}