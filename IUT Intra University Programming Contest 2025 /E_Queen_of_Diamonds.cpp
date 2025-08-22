#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int MAX_N = 1000000;

int32_t main() {
    vector<int> p(MAX_N + 1);
    p[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        p[i] = (p[i-1] * 2) % MOD;
    }
    
    int r;
    cin >> r;
    while (r--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v(26, 0);
        for (char c : s) {
            v[c - 'a']++;
        }
        int ans = 1;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                ans = (ans * p[v[i] - 1]) % MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}