#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll I = (ll)-9e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<ll, 7>> d0(n+1), d1(n+1), d2(n+1);
    for(int i=1;i<=n;i++){
        for(int c=0;c<=k;c++){
            d0[i][c] = I;
            d1[i][c] = I;
            d2[i][c] = I;
        }
    }
    vector<tuple<int,int,int>> s;
    s.reserve(n*2);
    s.emplace_back(1,0,0);
    while(!s.empty()){
        auto [u,p,t] = s.back();
        s.pop_back();
        if(t == 0){
            s.emplace_back(u,p,1);
            for(int v: g[u]){
                if(v == p) continue;
                s.emplace_back(v,u,0);
            }
        } else {
            static ll h0[7], nh0[7];
            static ll h1[7][2], nh1[7][2];
            static ll h2[7][3], nh2[7][3];
            for(int i=0;i<=k;i++){
                h0[i] = (i==0 ? 0 : I);
                h1[i][0] = (i==0 ? 0 : I);
                h1[i][1] = I;
                h2[i][0] = (i==0 ? 0 : I);
                h2[i][1] = I;
                h2[i][2] = I;
            }
            for(int v: g[u]){
                if(v == p) continue;
                for(int i=0;i<=k;i++){
                    nh0[i] = I;
                    nh1[i][0] = nh1[i][1] = I;
                    nh2[i][0] = nh2[i][1] = nh2[i][2] = I;
                }
                for(int cu=0; cu<=k; cu++){
                    if(h0[cu] != I){
                        for(int cv=0; cu+cv<=k; cv++){
                            ll b = d0[v][cv];
                            if(d1[v][cv] > b) b = d1[v][cv];
                            if(b != I){
                                ll x = h0[cu] + b;
                                if(x > nh0[cu+cv]) nh0[cu+cv] = x;
                            }
                        }
                    }
                }
                for(int i=0;i<=k;i++) h0[i] = nh0[i];
                for(int cu=0; cu<=k; cu++){
                    for(int mu=0; mu<2; mu++){
                        if(h1[cu][mu] == I) continue;
                        for(int cv=0; cu+cv<=k; cv++){
                            ll b = d0[v][cv];
                            if(d1[v][cv] > b) b = d1[v][cv];
                            if(b != I){
                                ll x = h1[cu][mu] + b;
                                if(x > nh1[cu+cv][mu]){
                                    nh1[cu+cv][mu] = x;
                                }
                            }
                            if(mu == 0){
                                if(d2[v][cv] != I){
                                    ll x = h1[cu][mu] + d2[v][cv];
                                    if(x > nh1[cu+cv][1]){
                                        nh1[cu+cv][1] = x;
                                    }
                                }
                            }
                        }
                    }
                }
                for(int i=0;i<=k;i++){
                    h1[i][0] = nh1[i][0];
                    h1[i][1] = nh1[i][1];
                }
                for(int cu=0; cu<=k; cu++){
                    for(int mu=0; mu<3; mu++){
                        if(h2[cu][mu] == I) continue;
                        for(int cv=0; cu+cv<=k; cv++){
                            ll b = d0[v][cv];
                            if(d1[v][cv] > b) b = d1[v][cv];
                            if(b != I){
                                ll x = h2[cu][mu] + b;
                                if(x > nh2[cu+cv][mu]){
                                    nh2[cu+cv][mu] = x;
                                }
                            }
                            if(mu == 0){
                                if(d2[v][cv] != I){
                                    ll x = h2[cu][mu] + d2[v][cv];
                                    if(x > nh2[cu+cv][1]){
                                        nh2[cu+cv][1] = x;
                                    }
                                }
                            }
                            if(mu == 1){
                                if(d2[v][cv] != I){
                                    ll x = h2[cu][mu] + d2[v][cv];
                                    if(x > nh2[cu+cv][2]){
                                        nh2[cu+cv][2] = x;
                                    }
                                }
                            }
                        }
                    }
                }
                for(int i=0;i<=k;i++){
                    for(int m=0;m<3;m++){
                        h2[i][m] = nh2[i][m];
                    }
                }
            }
            for(int c=0;c<=k;c++){
                d0[u][c] = h0[c];
            }
            for(int c=0;c<=k;c++){
                ll b = I;
                if(h1[c][0] != I) b = h1[c][0];
                if(h1[c][1] != I && h1[c][1] > b) b = h1[c][1];
                if(b != I){
                    d2[u][c] = b + a[u];
                } else {
                    d2[u][c] = I;
                }
            }
            for(int c=0;c<=k;c++){
                ll b = I;
                if(h2[c][0] != I) b = h2[c][0];
                if(h2[c][1] != I && h2[c][1] > b) b = h2[c][1];
                if(h2[c][2] != I && h2[c][2] > b) b = h2[c][2];
                if(b != I && c+1 <= k){
                    d1[u][c+1] = b + a[u];
                }
            }
        }
    }
    ll ans = 0;
    for(int c=0;c<=k;c++){
        if(d0[1][c] > ans) ans = d0[1][c];
        if(d1[1][c] > ans) ans = d1[1][c];
    }
    cout<<ans;
    return 0;
}