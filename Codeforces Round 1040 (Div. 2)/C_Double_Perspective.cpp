#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int,int>> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i].first >> s[i].second;
        }
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = i;
        
        sort(v.begin(), v.end(), [&](int a, int b) {
            int la = s[a].second - s[a].first;
            int lb = s[b].second - s[b].first;
            if (la != lb) return la > lb;
            return s[a].first < s[b].first;
        });
        
        set<int> p;
        for (int i = 1; i <= 2*n; i++) p.insert(i);
        
        vector<int> r;
        for (int x : v) {
            int a = s[x].first;
            int b = s[x].second;
            
            auto temp = p.lower_bound(a);
            if (temp == p.end() || *temp >= b) continue;
            
            bool ok = false;
            while (temp != p.end() && *temp < b) {
                ok = true;
                auto temp1 = temp;
                ++temp;
                p.erase(temp1);
            }
            
            if (ok) r.push_back(x+1);
        }
        
        sort(r.begin(), r.end());
        cout << r.size() << "\n";
        
        for (int i = 0; i < (int)r.size(); i++) {
            cout << r[i] << (i+1<r.size() ? ' ' : '\n');
        }
        
        if (r.empty()) {
            cout << "\n";
        }
    }
    
    return 0;
}