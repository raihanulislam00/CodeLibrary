#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        map<int, int> a, b;
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            int r = x % k;
            if(r == 0 || (k % 2 == 0 && r == k/2)){
                a[r]++;
            } else {
                int m = min(r, k - r);
                a[m]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            int r = x % k;
            if(r == 0 || (k % 2 == 0 && r == k/2)){
                b[r]++;
            } else {
                int m = min(r, k - r);
                b[m]++;
            }
        }
        
        bool flag = true;
        for(auto& p : a){
            if(b[p.first] != p.second){
                flag = false;
                break;
            }
        }
        
        for(auto& p : b){
            if(a[p.first] != p.second){
                flag = false;
                break;
            }
        }
        
        if(flag){
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }
    
    return 0;
}