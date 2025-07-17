#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        
        if (p[n-1] != s[0]) {
            no;
            continue;
        }
        
        vector<int> a(n);
        a[0] = p[0] * s[0] / p[n-1];
        
        for (int i = 1; i < n; i++) {
            a[i] = p[i] * s[i] / p[n-1];
        }
        
        vector<int> v1(n), v2(n);
        v1[0] = a[0];
        for (int i = 1; i < n; i++) {
            v1[i] = gcd(v1[i-1], a[i]);
        }
        
        v2[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            v2[i] = gcd(a[i], v2[i+1]);
        }
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (v1[i] != p[i] || v2[i] != s[i]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            yes;
        } else {
            no;
        }
    }
    
    return 0;
}