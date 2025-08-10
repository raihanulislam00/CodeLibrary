#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int>a(n), b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int ans=0;
        for(int i=0;i<n;i++) if(a[i]>b[i]) ans += (a[i]-b[i]);
        cout << (ans+1) << '\n';
    }
    return 0;
}
