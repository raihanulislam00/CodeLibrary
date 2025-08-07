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
typedef vector<int> vll;

const int M=5000;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vi p(n),a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>p[i]>>a[i]>>b[i];
    }
    
    vll pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+b[i-1];
    }
    int tot=pre[n];
    
    vll suf(n+1,0);
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+b[i];
    }
    
    vector<vll> dp(n+1,vll(M+1,0));
    for(int y=0;y<=M;y++){
        dp[n][y]=y;
    }
    
    for(int i=n-1;i>=0;i--){
        for(int y=0;y<=M;y++){
            int ny;
            if(y<=p[i]){
                ny=y+a[i];
            }else{
                if(y<b[i]){
                    ny=0;
                }else{
                    ny=y-b[i];
                }
            }
            
            if(ny<=M){
                dp[i][y]=dp[i+1][ny];
            }else{
                int rb=suf[i+1];
                int fm=ny-rb;
                if(fm<0)fm=0;
                dp[i][y]=fm;
            }
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x>M+tot){
            cout<<x-tot<<'\n';
        }else{
            auto it=lower_bound(all(pre),x-M);
            int k=it-pre.begin();
            int y0=x-pre[k];
            if(y0<0)y0=0;
            cout<<dp[k][y0]<<'\n';
        }
    }
    
    return 0;
}