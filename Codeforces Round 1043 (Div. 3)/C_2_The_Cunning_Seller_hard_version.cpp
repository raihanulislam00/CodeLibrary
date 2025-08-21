#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    int p[40];
    p[0] = 1;
    for(int i = 1; i < 40; i++) p[i] = p[i-1] * 3;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        if(!n){
            cout << "0\n";
            continue;
        }
        
        vector<int> a;
        int x = n;
        while(x) a.push_back(x % 3), x /= 3;
        
        int sum = 0;
        for(int ai : a) sum += ai;
        
        k = min(k, n);
        if(sum > k){
            cout << "-1\n";
            continue;
        }
        
        int tgt = k;
        if((tgt - sum) & 1) tgt--;
        tgt = max(tgt, sum);
        
        int b = (tgt - sum) / 2;
        int cost = 0;
        
        for(int i = 0; i < a.size(); i++){
            if(!a[i]) continue;
            cost += a[i] * (i ? (i + 9) * p[i-1] : 3);
        }
        
        vector<int> u = a;
        int drop = 0;
        
        for(int i = u.size() - 1; i >= 1 && b; i--){
            if(!u[i]) continue;
            int x = min(u[i], b);
            b -= x;
            u[i] -= x;
            u[i-1] += x * 3;
            drop += x * p[i-1];
        }
        
        cout << cost - drop << "\n";
    }
    return 0;
}