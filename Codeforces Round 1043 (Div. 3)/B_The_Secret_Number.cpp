#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> s;
        __int128 N = n;
        __int128 pow = 10;
        for(int k = 1; ; ++k) {
            __int128 d = pow + 1;
            if(d > N) break;
            if(N % d == 0) {
                int x = (int)(N / d);
                if(x > 0) {
                    s.push_back(x);
                }
            }
            pow *= 10;
            if(pow > N) break;
        }
        sort(s.begin(), s.end());
        if(s.empty()) {
            cout << 0 << '\n';
        } else {
            cout << s.size() << '\n';
            for(size_t i = 0; i < s.size(); ++i) {
                cout << s[i] << (i + 1 < s.size() ? ' ' : '\n');
            }
        }
    }
    return 0;
}
