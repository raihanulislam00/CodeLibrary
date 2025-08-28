#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int cost=0;
        if(n>=2){
            if(a[0] > a[1]){
                cost += a[0] - a[1];
                a[0] = a[1];
            }
        }
        for(int i=1;i<n-1;i+=2){
            int limit = a[i] - a[i-1];
            if(limit < 0){
                cost += -limit;
                a[i-1] = a[i];
                limit = 0;
            }
            if(i+1 < n && a[i+1] > limit){
                cost += a[i+1] - limit;
                a[i+1] = limit;
            }
        }
        if(n % 2 == 0){
            if(a[n-2] > a[n-1]){
                cost += a[n-2] - a[n-1];
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
