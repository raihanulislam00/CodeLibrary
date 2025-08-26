#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n+1);
        
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << " " << n;
            for (int j = 1; j <= n; j++) cout << " " << j;
            cout << endl;
            cin >> d[i];
            if (d[i] == -1) return 0;
        }
        
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        sort(v.begin(), v.end(), [&](int a, int b) {
            return d[a] > d[b];
        });
        
        int mx = d[v[0]];
        vector<vector<int>> l(mx+1);
        for (int i = 1; i <= n; i++) {
            if (d[i] <= mx) l[d[i]].push_back(i);
        }
        
        vector<int> p;
        int c = v[0], y = d[c];
        p.push_back(c);
        
        while (y > 1) {
            int x = y - 1;
            bool ok = false;
            for (int u : l[x]) {
                cout << "? " << c << " 2 " << c << " " << u << endl;
                int a;
                cin >> a;
                if (a == -1) return 0;
                if (a == 2) {
                    c = u;
                    y = x;
                    p.push_back(u);
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }
        
        cout << "! " << p.size();
        for (int x : p) cout << " " << x;
        cout << endl;
    }
    return 0;
}