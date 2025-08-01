#include <bits/stdc++.h> 
using namespace std; 
#define int long long
struct Fenwick { 
    int n; 
    vector<int> f; 
    Fenwick(int n):n(n),f(n+1,0){} 
    void update(int i,int v){for(;i<=n;i+=i&-i)f[i]+=v;} 
    int query(int i){int s=0;for(;i>0;i-=i&-i)s+=f[i];return s;} 
    int rangeQuery(int l,int r){if(r<l) return 0; return query(r)-query(l-1);} 
}; 
int32_t main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t; 
    cin>>t; 
    while(t--){ 
        
        int n; 
        cin>>n; 
        vector<int> p(n); 
        for(int i=0;i<n;i++){cin>>p[i];} 
        vector<int> v(n),v1(n); 
        Fenwick f1(n); 
        for(int i=0;i<n;i++){ 
            v1[i]=f1.rangeQuery(p[i]+1,n); 
            f1.update(p[i],1); 
        } 
        Fenwick f2(n); 
        for(int i=n-1;i>=0;i--){ 
            v[i]=f2.rangeQuery(1,p[i]-1); 
            f2.update(p[i],1); 
        } 
        vector<int> a(n); 
        for(int i=0;i<n;i++){ 
            if(i+1+v[i]+v1[i]>n) a[i]=2*n-p[i]; else a[i]=p[i]; 
        } 
        Fenwick f3(2*n); 
        int ans=0; 
        for(int i=0;i<n;i++){ 
            ans += f3.rangeQuery(a[i]+1,2*n); 
            f3.update(a[i],1); 
        } 
        cout<<ans<<endl; 
    } 
    return 0; 
} 
