#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int temp;
        if (n % 2 == 1) {
            temp = (n + 1) / 2;
        } else {
            int x = n / 2;
            temp = x + (x + 1) / 2;
        }
        
        cout << temp << "\n";
    }
    
    return 0;
}