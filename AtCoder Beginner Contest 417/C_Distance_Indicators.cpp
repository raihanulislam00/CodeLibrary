#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        int t = j + 1 - a[j];
        ans += cnt[t];
        int k = a[j] + (j + 1);
        cnt[k]++;
    }
    cout << ans << endl;
    return 0;
}