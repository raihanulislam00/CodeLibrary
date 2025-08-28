#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> g(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=2){
            cout << -1 << "\n";
            continue;
        }
        
        vector<int> d(n+1,-1), p(n+1,-1);
        queue<int> q;
        q.push(1);
        d[1]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u])if(d[v]==-1){
                d[v]=d[u]+1;
                p[v]=u;
                q.push(v);
            }
        }
        int x=1;
        for(int i=1;i<=n;i++)if(d[i]>d[x])x=i;
        
        fill(d.begin(),d.end(),-1);
        fill(p.begin(),p.end(),-1);
        q.push(x);
        d[x]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u])if(d[v]==-1){
                d[v]=d[u]+1;
                p[v]=u;
                q.push(v);
            }
        }
        int y=x;
        for(int i=1;i<=n;i++)if(d[i]>d[y])y=i;
        
        vector<int> path;
        for(int v=y;v!=-1;v=p[v])path.push_back(v);
        reverse(path.begin(),path.end());
        set<int> s(path.begin(),path.end());
        
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(g[i].size()>2){
                ok=false;
                break;
            }
        }
        if(ok){
            cout << -1 << "\n";
            continue;
        }
        
        fill(d.begin(),d.end(),-1);
        fill(p.begin(),p.end(),-1);
        for(int v:path){
            d[v]=0;
            q.push(v);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u])if(d[v]==-1){
                d[v]=d[u]+1;
                p[v]=u;
                q.push(v);
            }
        }
        
        int leaf=-1;
        for(int i=1;i<=n;i++){
            if(s.count(i))continue;
            if(g[i].size()==1){
                if(leaf==-1||d[i]<d[leaf])leaf=i;
            }
        }
        if(leaf==-1){
            cout << -1 << "\n";
            continue;
        }
        int c=leaf;
        int b=p[c];
        int a=-1;
        for(int v:g[b]){
            if(v!=c){
                a=v;
                break;
            }
        }
        if(a==-1){
            cout << -1 << "\n";
        }else{
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}