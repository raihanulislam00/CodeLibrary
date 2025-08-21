#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int j = 0; j < m; ++j) cin >> b[j];
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        vector<int> P(n+1, 0), Q(m+1, 0);
        for(int i = 0; i < n; ++i) P[i+1] = P[i] + a[i];
        for(int j = 0; j < m; ++j) Q[j+1] = Q[j] + b[j];

        while(q--){
            int x, y, z;
            cin >> x >> y >> z;
            int l = std::max(0LL, z - y);
            int r = std::min(x, z);
            if(l > r){
                cout << 0 << endl;
                continue;
            }
            int best = 0;
            int lo = l, sz = r;
            while(sz - lo > 2){
                int m1 = lo + (sz - lo) / 3;
                int m2 = sz - (sz - lo) / 3;
                int f1 = P[m1] + Q[z - m1];
                int f2 = P[m2] + Q[z - m2];
                if(f1 <= f2) lo = m1;
                else sz = m2;
            }
            for(int k = lo; k <= sz; ++k){
                int sum = P[k] + Q[z - k];
                if(sum > best) best = sum;
            }
            cout << best << endl;
        }
    }
    return 0;
}
