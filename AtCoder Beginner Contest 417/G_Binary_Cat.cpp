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

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin>>q;
    
    const int I=1e18+5;
    vi len(q+2),l(q+2),r(q+2);
    
    len[0]=len[1]=1;
    
    for(int i=1;i<=q;i++){
        int a,b,x;
        cin>>a>>b>>x;
        
        int j=i+1;
        l[j]=a;
        r[j]=b;
        
        len[j]=min(I,len[a]+len[b]);
        
        int c=j;
        while(c>1){
            if(x<=len[l[c]]){
                c=l[c];
            }else{
                x-=len[l[c]];
                c=r[c];
            }
        }
        
        cout<<c<<'\n';
    }
    return 0;
}