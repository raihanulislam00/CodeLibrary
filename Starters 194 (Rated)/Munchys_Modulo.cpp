#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
int main(){
    fast
    int t; cin >> t;
    ll a[5001];
    while(t--){
        int n; cin >> n;
        f(i,0,n) cin >> a[i];
        sort(a,a+n,greater<ll>());
        ll x = a[0], b = 0;
        f(i,1,n) f(j,i+1,n){
            ll s = a[i]+a[j];
            if(s==0) continue;
            ll r = x%s;
            if(r>b) b = r;
        }
        cout << max(b,(n>1?a[1]:0)) << '\n';
    }
}