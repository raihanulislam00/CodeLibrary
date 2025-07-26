#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<string> ans;
    
    vector<int> v1(k, 0);
    
    while (true) {
        string cur = "";
        for (int i = 0; i < k; i++) {
            cur += v[v1[i]];
        }
        ans.push_back(cur);
        
        int pos = k - 1;
        while (pos >= 0 && v1[pos] == n - 1) {
            v1[pos] = 0;
            pos--;
        }
        if (pos < 0) break;
        v1[pos]++;
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans[x - 1] << endl;
    
    return 0;
}