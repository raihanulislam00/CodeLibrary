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

const int mod=998244353;
const int N=200005;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> inv(N,0);
    for(int i=1;i<N;i++){
        int b=i,e=mod-2,r=1;
        b%=mod;
        while(e>0){
            if(e&1)r=(r*b)%mod;
            b=(b*b)%mod;
            e>>=1;
        }
        inv[i]=r;
    }
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    vector<int> t(4*n,0),lz(4*n,-1);
    
    function<void(int,int,int)> build=[&](int v,int l,int r){
        if(l==r){
            t[v]=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*v+1,l,mid);
        build(2*v+2,mid+1,r);
        t[v]=(t[2*v+1]+t[2*v+2])%mod;
    };
    
    function<void(int,int,int)> push=[&](int v,int l,int r){
        if(lz[v]!=-1){
            int mid=(l+r)/2;
            int lc=2*v+1,rc=2*v+2;
            if(lc<4*n){
                lz[lc]=lz[v];
                t[lc]=(lz[v]*(mid-l+1))%mod;
            }
            if(rc<4*n){
                lz[rc]=lz[v];
                t[rc]=(lz[v]*(r-mid))%mod;
            }
            lz[v]=-1;
        }
    };
    
    function<void(int,int,int,int,int,int)> upd=[&](int v,int l,int r,int s,int e,int val){
        if(r<s||e<l)return;
        if(s<=l&&r<=e){
            lz[v]=val;
            t[v]=(val*(r-l+1))%mod;
            return;
        }
        push(v,l,r);
        int mid=(l+r)/2;
        upd(2*v+1,l,mid,s,e,val);
        upd(2*v+2,mid+1,r,s,e,val);
        t[v]=(t[2*v+1]+t[2*v+2])%mod;
    };
    
    function<int(int,int,int,int,int)> qry=[&](int v,int l,int r,int s,int e)->int{
        if(r<s||e<l)return 0;
        if(s<=l&&r<=e)return t[v];
        push(v,l,r);
        int mid=(l+r)/2;
        int ls=qry(2*v+1,l,mid,s,e);
        int rs=qry(2*v+2,mid+1,r,s,e);
        return (ls+rs)%mod;
    };
    
    build(0,0,n-1);
    
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int len=r-l+1;
        int tot=qry(0,0,n-1,l,r);
        int nv=(tot%mod)*inv[len]%mod;
        upd(0,0,n-1,l,r,nv);
    }
    
    for(int i=0;i<n;i++){
        int val=qry(0,0,n-1,i,i)%mod;
        if(val<0)val+=mod;
        cout<<val;
        if(i<n-1)cout<<' ';
    }
    cout<<'\n';
    
    return 0;
}