#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(), a.end());
        int res=0;
        if(n%2==1){
            for(int i=0; i<n; i+=2) res += a[i];
        } else {
            for(int i=1; i<n; i+=2) res += a[i];
        }
        cout<<res;
        if(t) cout<<"\n";
    }
    return 0;
}
