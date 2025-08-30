#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int x;
    string y;
    cin >> x >> y;
    if (s[x-1] == y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}