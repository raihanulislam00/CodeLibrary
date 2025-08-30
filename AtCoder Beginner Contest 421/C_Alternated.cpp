#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; string s;
    cin>>n>>s;
    vector<int> a,b;
    for(int i=0;i<2*n;i++){
        if(s[i]=='A') a.push_back(i);
        else b.push_back(i);
    }
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        ans1+=abs(a[i]-2*i);
        ans2+=abs(a[i]-(2*i+1));
    }
    cout<<min(ans1,ans2)<<"\n";
}
