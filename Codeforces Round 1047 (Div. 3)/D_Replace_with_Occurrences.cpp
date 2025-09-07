#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        cin>>n;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>b[i];
        vector<vector<int>> g(n+1);
        for(int i=0;i<n;i++){
            if(b[i] <= n) g[b[i]].push_back(i);
        }
        bool ok = true;
        for(int v=1; v<=n; v++){
            if(g[v].size() % v != 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        vector<int> a(n);
        int c = 0;
        for(int v=1; v<=n; v++){
            for(int i=0; i<g[v].size(); i += v){
                c++;
                for(int j=0; j<v; j++){
                    a[g[v][i+j]] = c;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << a[i] << (i+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
