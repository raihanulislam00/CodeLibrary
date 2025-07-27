#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, c;
        cin >> n >> c;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            int w = a[i];
            int k = 0;
            
            while (w <= c) {
                w *= 2;
                k++;
            }
            
            v.push_back(k);
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (x < v[i]) {
                x++;
            } else {
                ans++;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}