#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        ll ans = 0;
        int L0 = 1, L1 = 1;
        // For i=1, L0=L1=1
        ans += 1;  // i - min(L0,L1) + 1 = 1
        for(int i=2;i<=n;i++){
            int l0 = i, l1 = i;
            if(a[i-1] < a[i]) l0 = min(l0, L0);
            if(b[i-1] < a[i]) l0 = min(l0, L1);
            if(a[i-1] < b[i]) l1 = min(l1, L0);
            if(b[i-1] < b[i]) l1 = min(l1, L1);
            L0 = l0;
            L1 = l1;
            int lmin = min(L0, L1);
            ans += (i - lmin + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
