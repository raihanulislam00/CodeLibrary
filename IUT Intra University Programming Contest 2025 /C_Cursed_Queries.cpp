#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n=0): n(n), f(n+1, 0) {}
    void build(const vector<int>& a) {
        for(int i=1; i<=n; ++i) {
            f[i] += a[i];
            int j = i + (i & -i);
            if(j <= n) f[j] += f[i];
        }
    }
    void add(int i, int v) {
        for(; i<=n; i += i & -i) f[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for(; i>0; i -= i & -i) s += f[i];
        return s;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n+1);
        for(int i=1; i<=n; ++i) cin>>a[i];
        vector<int> div;
        div.reserve(64);
        for(int i=1; i*i<=m; ++i){
            if(m % i == 0){
                div.push_back(i);
                if(i != m/i) div.push_back(m/i);
            }
        }
        sort(div.begin(), div.end());
        int cnt = div.size();
        vector<int> idx(m+1, -1);
        for(int i=0; i<cnt; ++i) {
            idx[div[i]] = i;
        }
        vector<Fenwick> fenw;
        fenw.reserve(cnt);
        for(int i=0; i<cnt; ++i){
            fenw.emplace_back(n);
        }
        vector<int> arr(n+1);
        for(int di=0; di<cnt; ++di){
            int d = div[di];
            for(int i=1; i<=n; ++i){
                arr[i] = (a[i] % d == 0);
            }
            fenw[di].build(arr);
        }
        int q;
        cin>>q;
        while(q--){
            int type;
            cin>>type;
            if(type == 1){
                int i, x;
                cin>>i>>x;
                for(int di=0; di<cnt; ++di){
                    int d = div[di];
                    int v1 = (a[i] % d == 0);
                    int v2 = (x % d == 0);
                    if(v1 != v2){
                        fenw[di].add(i, v2 - v1);
                    }
                }
                a[i] = x;
            } else {
                int l, r;
                long long k;
                cin>>l>>r>>k;
                int g = std::gcd((int)k, m);
                if(g == 1){
                    cout<<0<<endl;
                } else {
                    int di = idx[g];
                    int cnt = fenw[di].sum(r) - fenw[di].sum(l-1);
                    int ans = (r - l + 1) - cnt;
                    cout<<ans<<endl;
                }
            }
        }
    }
    return 0;
}
