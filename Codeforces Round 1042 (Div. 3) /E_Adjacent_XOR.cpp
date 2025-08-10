#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        
        bool ok = true;
        
        for(int i = n - 2; i >= 0; i--){
            bool flag = false;
            
            if(b[i] == a[i]){
                flag = true;
            }
            
            if(b[i] == (a[i] ^ a[i + 1])){
                flag = true;
            }
            
            if(b[i] == (a[i] ^ b[i + 1])){
                flag = true;
            }
            
            if(!flag){
                ok = false;
                break;
            }
        }
        
        if(b[n - 1] != a[n - 1]){
            ok = false;
        }
        
        if(ok){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}