#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ll c0 = min(a[0], a[n-1]);
        
        vector<ll> m1(n, 0), m2(n, LLONG_MAX);
        vector<int> cnt(n, 0);
        
        m1[0] = a[0];
        cnt[0] = 1;
        
        for (int i = 1; i < n; i++) {
            if (a[i] < m1[i-1]) {
                m2[i] = m1[i-1];
                m1[i] = a[i];
                cnt[i] = 1;
            } else if (a[i] == m1[i-1]) {
                m1[i] = m1[i-1];
                m2[i] = m2[i-1];
                cnt[i] = cnt[i-1] + 1;
            } else if (a[i] < m2[i-1]) {
                m1[i] = m1[i-1];
                m2[i] = a[i];
                cnt[i] = cnt[i-1];
            } else {
                m1[i] = m1[i-1];
                m2[i] = m2[i-1];
                cnt[i] = cnt[i-1];
            }
        }
        
        ll c2 = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            int e = min(i, n-1);
            ll m;
            if (m1[e] < a[i-1]) m = m1[e];
            else if (m1[e] == a[i-1]) m = (cnt[e] > 1) ? m1[e] : m2[e];
            else m = m1[e];
            c2 = min(c2, a[i-1] + m);
        }
        
        cout << min(c0, c2) << '\n';
    }
    return 0;
}