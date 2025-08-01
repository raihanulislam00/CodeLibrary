#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int odd_count = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 != 0) {
                odd_count++;
            }
        }
        if (odd_count == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}