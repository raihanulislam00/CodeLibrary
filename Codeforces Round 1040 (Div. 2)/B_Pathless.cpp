#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(s < sum){
            for(int i = 0; i < n; i++){
                cout << a[i] << (i+1<n ? ' ' : '\n');
            }
        } else if(s == sum){
            cout << -1 << '\n';
        } else {
            if(s == sum + 1){
                int c0 = 0, c1 = 0, c2 = 0;
                for(int v : a){
                    if(v == 0) c0++;
                    else if(v == 1) c1++;
                    else if(v == 2) c2++;
                }
                for(int i = 0; i < c0; i++){
                    cout << 0 << " ";
                }
                for(int i = 0; i < c2; i++){
                    cout << 2 << " ";
                }
                for(int i = 0; i < c1; i++){
                    cout << 1 << (i+1<c1 ? ' ' : '\n');
                }
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
