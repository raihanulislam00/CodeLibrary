#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        int m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int s = 0;
        for(int x : a) s += x;
        for(int x : b) s += x;
        sort(a.begin(), a.end());
        multiset<int> ms(a.begin(), a.end());
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = m - b[i];
        sort(v.begin(), v.end(), greater<int>());
        int k = 0;
        for(int x : v) {
            auto it = ms.lower_bound(x);
            if(it != ms.end()) {
                k++;
                ms.erase(it);
            } else {
                ms.erase(ms.begin());
            }
        }
        cout << (s - m * k) << "\n";
    }
    return 0;
}