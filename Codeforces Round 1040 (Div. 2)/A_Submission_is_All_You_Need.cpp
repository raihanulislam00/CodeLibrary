#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        int ans = 0;
        int sum = 0;
        
        for (int x : v) {
            if (x == 0) {
                ans++;
            } else {
                sum += x;
            }
        }
        
        cout << ans + sum << "\n";
    }
    
    return 0;
}