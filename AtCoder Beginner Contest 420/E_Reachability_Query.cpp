#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, sz, black;
    DSU(int n) {
        p.resize(n); sz.assign(n,1); black.assign(n,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    void unite(int a,int b) {
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        black[a]+=black[b];
    }
    void toggle(int x) {
        x=find(x);
        if(black[x]>0) black[x]--;
        else black[x]++;
    }
    bool hasBlack(int x) {
        return black[find(x)]>0;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;cin>>N>>Q;
    DSU dsu(N+1);
    vector<int> col(N+1,0);
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int u,v;cin>>u>>v;
            dsu.unite(u,v);
        }else if(t==2){
            int v;cin>>v;
            int r=dsu.find(v);
            if(col[v]==0){col[v]=1; dsu.black[r]++;}
            else {col[v]=0; dsu.black[r]--;}
        }else{
            int v;cin>>v;
            cout<<(dsu.hasBlack(v)?"Yes\n":"No\n");
        }
    }
}
