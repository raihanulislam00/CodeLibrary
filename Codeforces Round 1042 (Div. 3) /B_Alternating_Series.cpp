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
        for(int i=1;i<=n;i++){
            if(i%2==1) cout << -1;
            else {
                if(i==n && n%2==0) cout << 2;
                else cout << 3;
            }
            if(i<n) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
