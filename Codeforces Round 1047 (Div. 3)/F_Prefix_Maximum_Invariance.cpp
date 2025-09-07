#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   vector<int> v(200001);
   v[1] = 0;
   for (int i=2; i<=200000; i++) {
       v[i] = v[i/2] + 1;
   }
   
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       vector<int> a(n+1), b(n+1);
       for (int i=1; i<=n; i++) cin >> a[i];
       for (int i=1; i<=n; i++) cin >> b[i];
       
       vector<int> v1(n+1, 0);
       stack<int> st;
       for (int i=1; i<=n; i++) {
           while (!st.empty() && a[st.top()] < a[i]) {
               st.pop();
           }
           if (st.empty()) {
               v1[i] = 0;
           } else {
               v1[i] = st.top();
           }
           st.push(i);
       }
       
       int m = v[n];
       vector<vector<int>> tab(m+1, vector<int>(n+1, 0));
       for (int i=1; i<=n; i++) {
           tab[0][i] = a[i];
       }
       for (int j=1; j<=m; j++) {
           int step = 1 << (j-1);
           for (int i=1; i + step <= n; i++) {
               tab[j][i] = max(tab[j-1][i], tab[j-1][i+step]);
           }
       }
       
       int ans = 0;
       for (int i=1; i<=n; i++) {
           int cnt = 0;
           if (b[i] == a[i]) {
               cnt += (i - v1[i]);
           }
           if (v1[i] > 0) {
               int l = 1, r = v1[i];
               int cad = 0;
               while (l <= r) {
                   int mid = (l + r) / 2;
                   int j = v[i-1-mid+1];
                   int val = max(tab[j][mid], tab[j][i-1 - (1<<j) + 1]);
                   if (val >= b[i]) {
                       cad = mid;
                       l = mid + 1;
                   } else {
                       r = mid - 1;
                   }
               }
               cnt += cad;
           }
           ans += cnt * (n - i + 1);
       }
       cout << ans << endl;
   }
   return 0;
}