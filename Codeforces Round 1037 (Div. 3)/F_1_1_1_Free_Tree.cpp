#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> c(n+1);
        for(int i = 1; i <= n; i++) cin >> c[i];
        vector<vector<pair<int,ll>>> g(n+1);
        vector<tuple<int,int,ll>> ed;
        ed.reserve(n-1);
        for(int i = 0; i < n-1; i++){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            ed.push_back({u,v,w});
        }
        ll ans = 0;
        for(auto &e: ed){
            int u,v; ll w;
            tie(u,v,w) = e;
            if(c[u] != c[v]) ans += w;
        }
        int B = sqrt(n) + 1;
        vector<int> a(n+1, -1);
        vector<int> hv;
        hv.reserve(n);
        for(int i = 1; i <= n; i++){
            if((int)g[i].size() >= B){
                a[i] = hv.size();
                hv.push_back(i);
            }
        }
        int H = hv.size();
        vector<unordered_map<int,ll>> hm(H);
        vector<vector<pair<int,ll>>> hn(n+1);
        for(int hi = 0; hi < H; hi++){
            int h = hv[hi];
            for(auto &p: g[h]){
                int v = p.first; ll w = p.second;
                hm[hi][ c[v] ] += w;
                hn[v].push_back({hi, w});
            }
        }
        while(q--){
            int v, nc;
            cin >> v >> nc;
            int oc = c[v];
            if(oc == nc){
                cout << ans << "\n";
                continue;
            }
            ll so = 0, sn = 0;
            int hvid = a[v];
            if(hvid != -1){
                auto itOld = hm[hvid].find(oc);
                if(itOld != hm[hvid].end()) so = itOld->second;
                auto itNew = hm[hvid].find(nc);
                if(itNew != hm[hvid].end()) sn = itNew->second;
            } else {
                for(auto &p: g[v]){
                    int u = p.first; ll w = p.second;
                    if(c[u] == oc) so += w;
                    if(c[u] == nc) sn += w;
                }
            }
            ans += so;
            ans -= sn;
            c[v] = nc;
            for(auto &hvx: hn[v]){
                int hh = hvx.first;
                ll w = hvx.second;
                hm[hh][oc] -= w;
                hm[hh][nc] += w;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
