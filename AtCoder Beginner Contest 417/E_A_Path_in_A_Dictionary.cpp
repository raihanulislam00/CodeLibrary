#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vvi g(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        for(int i=1;i<=n;i++)
            sort(all(g[i]));
        
        vi p;
        vector<bool> b(n+1,0);
        p.pb(x);
        b[x]=1;
        
        while(p.back()!=y){
            vector<bool> r(n+1,0);
            queue<int> q;
            if(!b[y]){
                q.push(y);
                r[y]=1;
            }
            while(!q.empty()){
                int w=q.front();q.pop();
                for(int z:g[w]){
                    if(!b[z]&&!r[z]){
                        r[z]=1;
                        q.push(z);
                    }
                }
            }
            int u=p.back();
            int c=-1;
            for(int z:g[u]){
                if(!b[z]&&r[z]){
                    c=z;
                    break;
                }
            }
            if(c==-1)break;
            p.pb(c);
            b[c]=1;
        }
        for(int i=0;i<sz(p);i++){
            if(i)cout<<" ";
            cout<<p[i];
        }
        cout<<"\n";
    }
    return 0;
}