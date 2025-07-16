#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR_EQ(i,a,b) for(int i=a;i<=b;i++)

int main(){
    FAST_IO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        FOR(i,0,n) cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());
        vector<ll> v(n+1);
        v[0] = 0;
        FOR_EQ(i,1,n){
            v[i] = v[i-1] + a[i-1];
        }
        vector<ll> v1(2*n+1);
        int j = 0;
        v1[0] = 0;
        FOR_EQ(i,1,2*n){
            int l = (i + 1) / 2;
            if(l < 1) l = 1;
            int r = min(i, n);
            if(j < l) j = l;
            ll max = LLONG_MIN;
            if(j <= r){
                int c2 = i - j;
                ll sum = v[j] + (ll)c2 * j - (ll)c2 * (c2 + 1) / 2;
                max = sum;
                while(j < r){
                    int l = j + 1;
                    int c = i - l;
                    ll sum1 = v[l] + (ll)c * l - (ll)c * (c + 1) / 2;
                    if(sum1 >= sum){
                        j = l;
                        sum = sum1;
                        max = sum;
                    } else {
                        break;
                    }
                }
            } else {
                max = 0;
            }
            v1[i] = max;
            if(i > 1 && v1[i] < v1[i-1]) v1[i] = v1[i-1];
        }
        FOR_EQ(i,1,2*n){
            cout << v1[i] << (i < 2*n ? ' ' : endl);
        }
    }
    return 0;
}
