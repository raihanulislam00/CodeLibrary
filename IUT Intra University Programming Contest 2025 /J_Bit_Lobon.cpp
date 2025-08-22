#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        int a = l, b = r;
        while (a < b) {
            b &= (b - 1);
        }
        int ans = a & b;
        
        int O;
        if (l == 0) {
            if (r == 0) {
                O = 0;
            } else {
                int h = 63 - __builtin_clzll(r);
                O = (1LL << (h + 1)) - 1;
            }
        } else {
            int x = 63 - __builtin_clzll(l);
            int y = 63 - __builtin_clzll(r);
            
            if (x != y) {
                O = (1LL << (y + 1)) - 1;
            } else {
                int o = 0;
                int u = l, v = r;
                
                while (u > 0 && v > 0) {
                    int p = 63 - __builtin_clzll(u);
                    int q = 63 - __builtin_clzll(v);
                    
                    if (p != q) {
                        o |= (1LL << (q + 1)) - 1;
                        break;
                    }
                    
                    o |= 1LL << p;
                    u -= 1LL << p;
                    v -= 1LL << q;
                }
                
                if (u == 0 && v > 0) {
                    int h = 63 - __builtin_clzll(v);
                    o |= (1LL << (h + 1)) - 1;
                } else if (v == 0 && u > 0) {
                    int h = 63 - __builtin_clzll(u);
                    o |= (1LL << (h + 1)) - 1;
                }
                
                O = o;
            }
        }
        
        int temp;
        int s = r < 0 ? 0 : (r & 3) == 0 ? r : (r & 3) == 1 ? 1 : (r & 3) == 2 ? r + 1 : 0;
        int t = l - 1 < 0 ? 0 : ((l - 1) & 3) == 0 ? l - 1 : ((l - 1) & 3) == 1 ? 1 : ((l - 1) & 3) == 2 ? l : 0;
        temp = l == 0 ? s : s ^ t;
        
        cout << ans << " " << O << " " << temp << "\n";
    }
    
    return 0;
}