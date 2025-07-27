#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans1 = 1, ans2 = 1, ans3 = k;
        int lo = 1, hi = n;
        vector<int> v(n);
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            for(int i = 0; i < n; i++){
                v[i] = (a[i] >= mid ? 1 : -1);
                if(i > 0) v[i] += v[i-1];
            }
            int temp1 = 0;
            int temp2 = -1;
            bool flag = false;
            int l = 1, r = k;
            for(int i = 0; i < n; i++){
                if(i >= k){
                    if(v[i-k] < temp1){
                        temp1 = v[i-k];
                        temp2 = i-k;
                    }
                }
                if(i >= k-1){
                    if(v[i] - temp1 >= 0){
                        l = temp2 + 2;
                        r = i + 1;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                ans1 = mid;
                ans2 = l;
                ans3 = r;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }
    return 0;
}
