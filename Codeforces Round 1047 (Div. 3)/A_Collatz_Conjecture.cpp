#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int k, x;
        cin >> k >> x;
        
        int cur = x;
        for (int i = 0; i < k; i++) {
            cur = cur * 2;
        }
        
        cout << cur << endl;
    }
    
    return 0;
}